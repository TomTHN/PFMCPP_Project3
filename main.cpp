/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.





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

        void cancelBankAccount();
        std::string talkEmployee(std::string question);
        void robBank();
    };

    float withdrawMoney(Customer customer, float moneyToWithdraw); //returns updated bank balance
    float depositMoney(Customer customer, float moneyToDeposit); //returns updated bank balance
    float takeCredit(Customer customer, float amountCredit, float periodToRepay); //returns interest rate

    Customer peter;
};

void Bank::Customer::cancelBankAccount()
{
    
}

std::string Bank::Customer::talkEmployee(std::string question)
{
    return question;
}

void Bank::Customer::robBank()
{
    if(bankBalance < 0)
    {
        
    }
}

float Bank::withdrawMoney(Customer customer, float moneyToWithdraw)
{
    float updatedBankBalance = customer.bankBalance - moneyToWithdraw;
    return updatedBankBalance;
}

float Bank::depositMoney(Customer customer, float moneyToDeposit)
{
    float updatedBankBalance = customer.bankBalance + moneyToDeposit;
    return updatedBankBalance;
}

float Bank::takeCredit(Customer customer, float amountCredit, float periodToRepay)
{
    customer.bankBalance += amountCredit;
    return amountCredit/periodToRepay;
}

struct School
{
    int amountClassRooms = 25;
    int numTeachers = 50; 
    float amountBreakTime = 30.0f; //minutes
    float overallGradePointAverageSchool = 2.4f;
    int numPupils = 630;

    void writeGoodGrades();
    void skipSchool(); 
    bool eatLunch(); //returns false if person is still hungry 
};

void School::writeGoodGrades()
{
    
}

void School::skipSchool()
{
    
}

bool School::eatLunch()
{
    return true;
}

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

void SwimmingPool::swim(std::string direction)
{
    if(direction == "right")
    {
        //go right
    }
    else
    {
        //go left
    }
}

void SwimmingPool::dive(bool breathStatus)
{
    while(breathStatus)
    {
            
    }
}

int SwimmingPool::bathInSun(bool useSunProtection, int startTime)
{
    useSunProtection = 30;
    return startTime;
}

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
            float pressureSuspension = 95.4f;
            int sag = 15;

            float inflateTires(float targetPressureTire, float currentPressur); //Returns updated pressure 
            int setupSuspension(float targetPressure, int targetSag);
            void repair();
        };

    void rideDownhill();
    bool eatLunch(); //returns false if person is still hungry     
    void haveGoodTime();

    Bike firstBike;
};

float BikePark::Bike::inflateTires(float targetPressureTire, float currentPressur)
{
    return targetPressureTire - currentPressur;
}

int BikePark::Bike::setupSuspension(float targetPressure, int targetSag)
{
    pressureSuspension = targetPressure;
    return targetSag - sag;
}

void BikePark::Bike::repair()
{
    
}

void BikePark::rideDownhill()
{
    
}

bool BikePark::eatLunch()
{
    return true;
}

void BikePark::haveGoodTime()
{
    
}

struct Brakes
{
    int numPistons = 4;
    int numScrews = 6;
    float higthSpacer = 34.3f; //mm
    int numBreakPads = 4;
    int maintenanceInterval = 365; //days

    float slowDownBike(float initialSpeed, float amountDeceleration, float brakeTime); //returns updated speed
    void blockWheels(); 
    bool squeak(std::string weatherConditions); // returns squeaking status (true = squeak)
};

float Brakes::slowDownBike(float initialSpeed, float amountDeceleration, float brakeTime)
{
    return initialSpeed - amountDeceleration * brakeTime;
}

void Brakes::blockWheels()
{

}

bool Brakes::squeak(std::string weatherConditions)
{
    if(weatherConditions == "rain")
    {
        //squeak
    }
    
    return true;
}

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

void Pedals::assemble()
{
    
}

void Pedals::turn()
{
    
}

float Pedals::accelerateBike(float currentSpeed, float targedSpeed)
{
    return targedSpeed - currentSpeed;
}

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

void Suspension::traction(bool setupCorrect)
{
    if(setupCorrect)
    {
        
    }
}

void Suspension::dampen(float impactForce)
{
    float impactMax = 100.0f;
    if(impactForce < impactMax)
    {
        //Good
    }
    else
    {
        //Bad
    }
}

bool Suspension::breakSuspension()
{
    return true;
}

struct Frame
{
    std::string material = "carbon";
    std::string color = "black";
    std::string brand = "YT Industries";
    float weight = 5.4f; //kg
    float size = 634.0f; //mm

    void assemble(); 
    void bePainted(std::string color);
    bool breakFrame(); //returns frame status
};

void Frame::assemble()
{
    
}

void Frame::bePainted(std::string newColor)
{
    if(newColor == "Red")
    {
        //paint red
    }
    else
    {
        std::cout << "Color not available!";
    }
}

bool Frame::breakFrame()
{
    return false;
}

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

float Handlebar::moveBikeRight(float initSteeringAngle)
{
    float moveRightAngel = 90.0f;
    return moveRightAngel - initSteeringAngle;
}

float Handlebar::moveBikeLeft(float initSteeringAngle)
{
    float moveLeftAngel = 90.0f;
    return moveLeftAngel - initSteeringAngle;
}

bool Handlebar::controlleBike(float speedAngleChange)
{
    float criticalAngleChange = 20.4f;
    if(speedAngleChange < criticalAngleChange)
    {
        return true;
    }
    return false;
}

struct MountainBike
{
    Brakes brakes;
    Pedals pedals;
    Suspension suspesion;
    Frame frame;
    Handlebar handlebar;

    void crashTree(bool brakesStatus, Handlebar handlebar);
    void bunnyHop(Suspension suspension);    
    void goUphill(Pedals pedals, Handlebar handlebar, float slope);
};

void MountainBike::crashTree(bool brakesStatus, Handlebar handlebarCrash)
{
    if(brakesStatus && handlebarCrash.controlleBike(15.0f))
    {
        //Good
    }
}

void MountainBike::bunnyHop(Suspension suspensionHop)
{
    suspensionHop.breakSuspension();
}

void MountainBike::goUphill(Pedals pedalsUphill, Handlebar handlebarUphill, float slope)
{
    handlebarUphill.controlleBike(15.0f);
    pedalsUphill.accelerateBike(10.0f, 12.0f);
    if(slope > 10.5f)
    {
        std::cout << "too steep";
    }
}

int main()
{
    Example::main();
    
    
    std::cout << "good to go!" << std::endl;
}
