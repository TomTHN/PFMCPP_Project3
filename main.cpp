 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    struct Limb
    {
        int size = 30;

        int stepSize(int normalStep);
        void stepForward();
    };

    Limb leftFoot;
    Limb rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

int Person::Limb::stepSize(int normalStep)
{
    return normalStep;
}

void Person::run(int howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += leftFoot.stepSize(30) + rightFoot.stepSize(30);
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */


struct Bank
{
    int numATM = 3;
    int amountEmployees = 20;
    int amountSecurityCameras = 5;
    int numBankCounters = 5;
    int numCustomersDay = 1000;

    struct Customer
    {
        int customerNumber = 12345678;
        int age = 45;
        std::string gender = "male";
        float bankBalance = 4550.60f;
        int memberTime  = 600; //days

        void cancelBankAccount(int customerNumber);
        void talkEmployee(std::string question);
        void robBank(int bankBalance = 0);
    };

    float withdrawMoney(Customer customer, float moneyToWithdraw); //returns updated bank balance
    float depositMoney(Customer customer, float moneyToDeposit); //returns updated bank balance
    float takeCredit(Customer customer, float amountCredit, int periodToRepay); //returns interest rate

    Customer Peter;
};

struct School
{
    int amountClassRooms = 25;
    int numTeachers = 50; 
    float amountBreakTime = 30.0f; //minutes
    float overallGradePointAverageSchool = 2.4f;
    int numPupils = 630;

    void writeGoodGrades();
    void skipSchool(); 
    bool eatLunch(std::string whatEat); //returns false if person is still hungry 
};

struct SwimmingPool
{
    int amountPools = 4;
    float maxHightDivingBoard = 10.0f; //meters
    float lengthSwimminglane = 50.0; //meters
    float amountWater = 30000.0f; //cubic meter
    int visitorsYear = 20000;

    void swim(std::string direction);
    void dive(bool breathStatus);         
    int bathInSun(bool useSunProtection, int startTime = 0); //returns endTime
};

struct BikePark
{
    int amountTracks = 23;
    float hightMountain = 3400; //meters
    int numLifts = 5;
    int amountBlackDiamontTracks = 10;
    int accidentsYear = 700;
    
    struct Bike
        {
            bool hasFullSuspension = true;
            std::string brand = "GT";
            std::string color = "red";
            float wheelSize = 27.5f;
            float ageBike = 4.5f;
    
            float inflateTires(float targetPressure); //Returns updated pressure 
            void setupSuspension(float targetPressure, float targetSag);
            void repair(std::string brokenComponent);
        };

    void rideDownhill(Bike bike, std::string track);
    bool eatLunch(std::string whatEat); //returns false if person is still hungry     
    void haveGoodTime();

    Bike firstBike;
};

struct Brakes
{
    int numPistons = 4;
    int numScrews = 6;
    float higthSpacer = 34.3f; //mm
    int numBreakPads = 4;
    int maintenanceInterval = 365; //days

    float slowDownBike(float initialSpeed, float amountDeceleration); //returns updated speed
    void blockWheels(float brakePower, int systemMass, float speed); 
    bool squeak(std::string weatherConditions); // returns squeaking status (true = squeak)
};

struct Pedals
{
    std::string brand = "RaceFace";
    int size = 10;
    std::string color = "black";
    std::string material = "titanium";
    int amountTorque = 15; //Nm

    void assemble();
    void turn();
    float accelerateBike(float currentSpeed, float targedSpeed); // returns updated speed
};

struct Suspension
{
    float pressure = 80.0; //PSI
    int travel = 170; //mm
    int stanchionDiameter = 38; //mm 
    std::string springType = "air";
    std::string damperType = "coil";

    void traction(bool setupCorrect);
    void dampen(float impactForce);   
    bool breakSuspension(); //returns suspension status
};

struct Frame
{
    std::string material = "carbon";
    std::string color = "black";
    std::string brand = "YT Industries";

    float weight = 5.4f; //kg
    float size = 634.0f; //mm
    void assemble(std::string nextTask); 
    void bePainted(std::string color);
    bool breakFrame(); //returns frame status
};

struct Handlebar
{
    std::string brand = "RaceFace";
    float clampDiameter = 25.3f; //mm
    float rise = 20.4f; //mm
    std::string color = "gold";
    std::string material = "carbon";

    float moveBikeRight(float initSteeringAngle); //returns updated angle
    float moveBikeLeft(float initSteeringAngle); //returns updated angle
    bool controlleBike(float speedAngleChange);// returns controlle status 
};

struct MountainBike
{
    Brakes brakes;
    Pedals pedals;
    Suspension suspesion;
    Frame frame;
    Handlebar handlebar;

    void crashTree(bool brakesStatus, Handlebar handlebar);
    void bunnyHop(Suspension suspension, int jumpHight);    
    void goUphill(Pedals pedals, Handlebar handlebar, float slope);
};

int main()
{
    std::cout << "good to go!" << std::endl;
}
