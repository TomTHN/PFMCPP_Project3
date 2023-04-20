/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





struct Bank
{
    Bank();

    int numATM;
    int amountEmployees {20};
    int amountSecurityCameras {5};
    int numBankCounters = 5;
    int numCustomersDay = 1000;
    float moneyATM {40000.00f};

    struct Customer
    {
        Customer();

        int customerNumber, age;
        std::string gender = "male";
        float bankBalance {4550.60f};
        int memberTime  = 600; //days

        void cancelBankAccount(bool state);
        std::string talkEmployee(std::string question);
        void robBank(bool decision);
    };

    float withdrawMoney(Customer customer, float moneyToWithdraw); //returns updated bank balance
    float depositMoney(Customer customer, float moneyToDeposit); //returns updated bank balance
    float takeCredit(Customer customer, float amountCredit, float periodToRepay); //returns interest rate
    void refillATM(int amountWithdrawFiftyDollar)
    {
        for (int i = 0; i < amountWithdrawFiftyDollar; ++i)
        {
            moneyATM -= 50.00f;
            if(moneyATM <= 1000.00f)
            {
                std::cout << "Only " << moneyATM << " Dollar left. Please refill ATM" << std::endl;
            }
        }  
    }
};

Bank::Bank() : numATM(3)
{
    std::cout << std::endl << "Bank being constructed!" << std::endl;
}

Bank::Customer::Customer() : customerNumber{12345678}, age{45}
{
    std::cout << "Bank::Customer being constructed!" << std::endl;
}

void Bank::Customer::cancelBankAccount(bool state)
{
    if(state)
    {
        std::cout << "I want to cancel my bank account!" << std::endl;
    }
}

std::string Bank::Customer::talkEmployee(std::string question)
{
    std::cout << question << std::endl;
    return question;
}

void Bank::Customer::robBank(bool desicion)
{
    if(desicion)
    {
        std::cout << "Ladies and gentlemen, this is a robbery!" << std::endl;
    }
}

float Bank::withdrawMoney(Customer customer, float moneyToWithdraw)
{
    float updatedBankBalance = customer.bankBalance - moneyToWithdraw;
    std::cout << "Your new bank balance is: " << updatedBankBalance << "."  << std::endl;
    return updatedBankBalance;
}

float Bank::depositMoney(Customer customer, float moneyToDeposit)
{
    float updatedBankBalance = customer.bankBalance + moneyToDeposit;
    std::cout << "Your new bank balance is: " << updatedBankBalance << "." << std::endl;
    return updatedBankBalance;
}

float Bank::takeCredit(Customer customer, float amountCredit, float periodToRepay)
{
    customer.bankBalance += amountCredit;
    return amountCredit / periodToRepay;
}

struct School
{
    School();

    int amountClassRooms = 25;
    int numTeachers = 50; 
    float amountBreakTime, overallGradePointAverageSchool;
    int numPupils = 630;

    void writeGoodGrades(float mathGrade);
    void skipSchool(bool wantSkipSchool); 
    bool eatLunch(); //returns false if person is still hungry 
    void breakTimeCounter()
    {
        while(amountBreakTime != 0.00f)
        {
            amountBreakTime -= 1.00f;
            //Wait 1 minute 
        }

        std::cout << "Lets go back to the classroom" << std::endl;
    }
};

School::School() : amountBreakTime{30.0f}, overallGradePointAverageSchool{2.4f}
{
    std::cout << "School being constructed!" << std::endl;
}

void School::writeGoodGrades(float mathGrade)
{
    std::cout << "Your grade in math is " << mathGrade << "." << std::endl;
}

void School::skipSchool(bool wantSkipSchool)
{
    std::cout << (wantSkipSchool == true ? "skip!" : "don´t skip!") << std::endl;
}

bool School::eatLunch()
{
    return true;
}

struct SwimmingPool
{
    SwimmingPool();

    int amountPools = 4;
    float maxHightDivingBoard {10.0f}; //meters
    float lengthSwimminglane {50.0}; //meters
    float amountWater = 30000.0f; //cubic meter
    int visitorsYear = 20000;

    void swim(std::string direction);
    void dive(bool breathStatus);         
    int bathInSun(bool useSunProtection, int targetTime = 30); //returns endTime
    float metersLeftToSwim(int strokes, float metersPerStroke = 1.00f)
    {
        float metersDone = 0;
        
        for(int i = 0; i < strokes; ++i)
        {
            metersDone += metersPerStroke;
        }

        float metersLeft = lengthSwimminglane - metersDone;
        std::cout << "You need to swim " << metersLeft << " m to finish the lane" << std::endl;
        return metersLeft;
    }
};

SwimmingPool::SwimmingPool()
{
    std::cout << "SwimmingPool being constructed!" << std::endl;
}

void SwimmingPool::swim(std::string direction)
{
    if(direction == "right")
    {
        std::cout << "I´m swimming to the right on a " << lengthSwimminglane << " m swimming lane!" << std::endl;
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

int SwimmingPool::bathInSun(bool useSunProtection, int targetTime)
{    
    if(useSunProtection && (targetTime < 60))
    {
        std::cout << "You are protected!" << std::endl;
    }    
    
    return targetTime;
}

struct BikePark
{
    BikePark();

    int amountTracks;
    float hightMountain; //meters
    int numLifts = 5;
    int amountBlackDiamontTracks = 10;
    int accidentsYear = 700;
    int bikeMaximum {6};

    struct Bike
    {
        Bike();

        bool hasFullSuspension = true;
        std::string brand = "GT";
        std::string color = "red";
        float wheelSize = 27.5f;
        float ageBike = 4.5f;
        float pressureSuspension = 95.4f;
        int sag;

        float inflateTires(float targetPressureTire, float currentPressur); //Returns updated pressure 
        int setupSuspension(float targetPressure, int targetSag);
        void repair();
    };

    void rideDownhill();
    bool eatLunch(); //returns false if person is still hungry     
    void haveGoodTime();
    void fillPickupTruckWithBikes(int amountOfBikes)
    {
        for(int addedBikes = 0; addedBikes < amountOfBikes; ++addedBikes)
        {
            if(addedBikes == bikeMaximum)
            {
                std::cout << "Truck is full!" << std::endl;
            }   
            else
            {
                std::cout << "Still space!" << std::endl;
            }
        }
    }

    Bike firstBike;
};

BikePark::BikePark() : amountTracks{23}, hightMountain{3400}
{
    std::cout << "BikePark being constructed!" << std::endl;
}

BikePark::Bike::Bike() : sag{15}
{
    std::cout << "BikePark::Bike being constructed!" << std::endl;
}

float BikePark::Bike::inflateTires(float targetPressureTire, float currentPressur)
{
    return targetPressureTire - currentPressur;
}

int BikePark::Bike::setupSuspension(float targetPressure, int targetSag)
{
    pressureSuspension = targetPressure;
    std::cout << "my sag is " << sag << " cm but I need " << targetSag << " cm!" << std::endl;
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
    Brakes();

    int numPistons, numScrews, numBreakPads, maintenanceInterval;
    float higthSpacer = 34.3f; //mm

    float slowDownBike(float initialSpeed, float amountDeceleration, float brakeTime); //returns updated speed
    void blockWheels(); 
    bool squeak(std::string weatherConditions); // returns squeaking status (true = squeak)
    void breakStatus(bool breakStatus) //for example to avoid endless loop only "false"
    {
        while(breakStatus)
        {
            blockWheels();
            std::cout << "Your wheels are blocked" << std::endl;
        }
        
        std::cout << "Your wheels are spinning" << std::endl;
    }
};

Brakes::Brakes() : numPistons{4}, numScrews{6}, numBreakPads{4}, maintenanceInterval{365}
{
    std::cout << "Brakes being constructed!" << std::endl;
}

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
    Pedals();

    std::string brand {"RaceFace"};
    int size = 10;
    std::string color {"black"};
    std::string material = "titanium";
    int amountTorque = 15; //Nm

    void assemble();
    void turn();
    float accelerateBike(float currentSpeed, float targetSpeed); // returns updated speed
    void hitShin(int hitsTillBlood = 10)
    {
        for(int hit = 0; hit < hitsTillBlood; ++hit)
        {
            std::cout << hit << std::endl;
            
            if(hit == 9)
            {
                std::cout << "You´re bleeding" << std::endl;
            }
        }
    }
};

Pedals::Pedals()
{
    std::cout << "Pedals being constructed!" << std::endl;
}

void Pedals::assemble()
{
    
}

void Pedals::turn()
{
    
}

float Pedals::accelerateBike(float currentSpeed, float targetSpeed)
{
    return targetSpeed - currentSpeed;
}

struct Suspension
{
    Suspension();

    float pressure = 80.0; //PSI
    int travel = 170; //mm
    int stanchionDiameter = 38; //mm 
    std::string springType, damperType;

    void traction(bool setupCorrect);
    void dampen(float impactForce);   
    bool breakSuspension(); //returns suspension status
};

Suspension::Suspension() : springType{"air"}, damperType{"coil"}
{
    std::cout << "Suspension being constructed!" << std::endl;
}

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
    Frame();

    std::string material = "carbon";
    std::string color = "black";
    std::string brand = "YT Industries";
    float weight {5.4f}; //kg
    float size {634.0f}; //mm
    int scratches {0};

    void assemble(); 
    void bePainted(std::string color);
    bool breakFrame(); //returns frame status
    void scratchFrame(int addScratch)
    {
        for(int i = 0; addScratch < i; ++i)
        {
            ++scratches;
        }
    }
};

Frame::Frame()
{
    std::cout << "Frame being constructed!" << std::endl;
}

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
        std::cout << "Color not available!" << std::endl;
    }
}

bool Frame::breakFrame()
{
    return false;
}

struct Handlebar
{
    Handlebar();

    std::string brand {"RaceFace"};
    float clampDiameter = 25.3f; //mm
    float rise = 20.4f; //mm
    std::string color {"gold"};
    std::string material {"carbon"};

    float moveBikeRight(float initSteeringAngle); //returns updated angle
    float moveBikeLeft(float initSteeringAngle); //returns updated angle
    bool controlleBike(float speedAngleChange);// returns controlle status 
};

Handlebar::Handlebar()
{
    std::cout << "Handlebar being constructed!" << std::endl;
}

float Handlebar::moveBikeRight(float initSteeringAngle)
{
    float moveRightAngel = 90.0f;
    return moveRightAngel - initSteeringAngle;
}

float Handlebar::moveBikeLeft(float initSteeringAngle)
{
    float moveLeftAngel = 90.0f;
    std::cout << "Using a " << color << "en " << brand << " handlebar." << std::endl;
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
    MountainBike();

    Brakes brakes;
    Pedals pedals;
    Suspension suspesion;
    Frame frame;
    Handlebar handlebar;
    int psiTire {20};

    void crashTree(bool brakesStatus, Handlebar handlebar);
    void bunnyHop(int jumpHight);    
    void goUphill(Pedals pedals, Handlebar handlebar, float slope);
    void inflateTires(int psiTarget, int psiPerPump = 1)
    {    
        int startTirePressure = psiTire;
        for(int pump = 0; pump < (psiTarget - startTirePressure); ++pump)  //only works for psiPerPump = 1 and Target > Tire
        {
            psiTire += psiPerPump;
        }
        std::cout << "You pumped " << psiTire << " times!" << std::endl;
    }
};

MountainBike::MountainBike()
{
    std::cout << "MountainBike being constructed!" << std::endl;
}

void MountainBike::crashTree(bool brakesStatus, Handlebar handlebarCrash)
{
    if(brakesStatus && handlebarCrash.controlleBike(15.0f))
    {
        //Good
    }
}

void MountainBike::bunnyHop(int jumpHight)
{
    std::cout << "You jumped " << jumpHight << "cm!" << std::endl;
}

void MountainBike::goUphill(Pedals pedalsUphill, Handlebar handlebarUphill, float slope)
{
    handlebarUphill.controlleBike(15.0f);
    pedalsUphill.accelerateBike(10.0f, 12.0f);
    if(10.5f < slope)
    {
        std::cout << "too steep!" << std::endl;
    }
}

int main()
{
    Example::main();

    Bank newBank;
    Bank::Customer tom;
    School newSchool;
    SwimmingPool newPool;
    BikePark newBikePark;
    BikePark::Bike newBike;
    Brakes newBrakes;
    Pedals newPedals;
    Suspension newSuspesion;
    Frame newFrame;
    Handlebar newHandlebar;
    MountainBike newMountainBike;
    std::cout << std::endl;
    
    newBank.depositMoney(tom, 2000.50f);
    newBank.withdrawMoney(tom, 500.0f);
    newBank.refillATM(10);
    tom.cancelBankAccount(false);
    tom.talkEmployee("I need to talk to your boss");
    tom.robBank(true);

    newSchool.writeGoodGrades(1.5f);
    newSchool.skipSchool(true);
    newSchool.eatLunch();
    newSchool.breakTimeCounter();
    
    newPool.bathInSun(true);
    newPool.dive(false);
    newPool.swim("right");
    newPool.metersLeftToSwim(5);

    newBikePark.eatLunch();
    newBikePark.haveGoodTime();
    newBikePark.rideDownhill();
    newBikePark.fillPickupTruckWithBikes(7);

    newBike.inflateTires(27.0f, 20.0f);
    newBike.repair();
    newBike.setupSuspension(95.4f, 25);

    newBrakes.blockWheels();
    newBrakes.slowDownBike(10, 2.5f, 10.5f);
    newBrakes.squeak("rain");
    newBrakes.breakStatus(false);

    float accelerateBikeReturn = newPedals.accelerateBike(8.5f, 15.0f);
    newPedals.assemble();
    newPedals.turn();
    newPedals.hitShin(10);

    newSuspesion.breakSuspension();
    newSuspesion.dampen(555.5);
    newSuspesion.traction(true);

    newFrame.assemble();
    newFrame.bePainted("Red");
    newFrame.breakFrame();

    newHandlebar.controlleBike(5.6f);
    newHandlebar.moveBikeLeft(80.4f);
    newHandlebar.moveBikeRight(75.3f);

    newMountainBike.bunnyHop(30);
    newMountainBike.crashTree(false, newHandlebar);
    newMountainBike.goUphill(newPedals, newHandlebar, 30.1f);
    newMountainBike.inflateTires(25, 1);
    std::cout << newMountainBike.psiTire << std::endl;

    std::cout << "You need to drive " << accelerateBikeReturn << " km/h faster!" << std::endl;
    
    std::cout << "good to go!" << std::endl;
}
