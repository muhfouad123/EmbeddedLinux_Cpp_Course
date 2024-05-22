#include <iostream>
#include <memory>

class GasolineResource
{
private:
public:
    virtual void FuelUp(void) = 0;
    virtual ~GasolineResource() = default;
};

class GasStation : public GasolineResource
{
private:
public:
    void FuelUp(void)
    {
        std::cout << "Pumping gas at gas station" << std::endl;
    }
};

class FuelCan : public GasolineResource
{
private:
public:
    void FuelUp(void)
    {
        std::cout << "Pumping gas from fuel can" << std::endl;
    }
};

template <typename T> class Car
{
private:
    T gasolineService = nullptr;
public:
    /**
     *
     * Dependency Injection.
     * The dependecy for a "source" of gasoline is passed in through constructor injection, as opposed to
     * hard-coded into the class definition
     * 
     */
    Car(T service) : gasolineService(service)
    {
        /* If the dependency was not defined, throw an exception. */
        if (gasolineService == nullptr)
        {
            throw std::invalid_argument("Service must not be null!");
        }
    }
    void getGasoline(void)
    {
        std::cout << "Car needs more gasoline!" << std::endl;
        /* Abstract away the dependency implementation using "Polymorphism". */
        gasolineService->FuelUp();
    }
};

typedef GasolineResource* GasolineResourcePtr;

int main(void)
{
    std::cout << "Hello, World!" << std::endl;

    std::shared_ptr<GasolineResource> stationService = std::make_shared<GasStation>();
    std::shared_ptr<GasolineResource> canService = std::make_shared<FuelCan>();

    /* "raceCar" is independent from the implementation of the fuel service.
        A gas station service is injected. */
    Car<std::shared_ptr<GasolineResource>> raceCar(stationService);
    raceCar.getGasoline();

    /* "duneBuggy" is independent from the implementation of the fuel service.
        A fuel can service is injected. */
    Car<std::shared_ptr<GasolineResource>> duneBuggy(canService);
    duneBuggy.getGasoline();

    std::cout << "Goodbye, World!" << std::endl;
    return 0;
}