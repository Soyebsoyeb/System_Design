#include <iostream>
using namespace std;

// Strategy Interface for Walk
class WalkableRobot {
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};

// Concrete Strategies for Walk
class NormalWalk : public WalkableRobot {
public:
    void walk() override {
        cout << "Walking Normally .... " <<endl;
    }
};

class NoWalk : public WalkableRobot {
public:
    void walk() override {
        cout << "Cannot Walk." <<endl;
    }
};


// Strategy Interface for Talk
class TalkableRobot {
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {}
};

// Concrete Strategies for Talk
class NormalTalk : public TalkableRobot {
public:
    void talk() override {
        cout << "Talking normally ...." <<endl;
    }
};

class NoTalk : public TalkableRobot {
public:
    void talk() override {
        cout << "Cannot Talk ..." << endl;      
    }
};



// Strategy Interface for Fly
class FlyableRobot {
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot {
public:
    void fly() override {
        cout << "Flying Normally ...." <<endl;
    }
};

class NoFly : public FlyableRobot {
public:
    void fly() override {
        cout << "Cannot Fly ... " << endl;
    }
};


// Robot Base Class

class Robot {
protected:
    WalkableRobot* walkBehavior;
    TalkableRobot* talkBehavior;
    FlyableRobot* flyBehavior;


public:
    Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) {
        this->walkBehavior = w;
        this->talkBehavior = t;
        this->flyBehavior = f;
    }
       
    void walk() { 
        walkBehavior->walk(); 
    }
    void talk() { 
        talkBehavior->talk(); 
    }
    void fly() { 
        flyBehavior->fly(); 
    }

    virtual void projection() = 0; // Abstract method for subclasses
};


// Concrete Robot Types

class CompanionRobot : public Robot {
public: 
    CompanionRobot(WalkableRobot* w , TalkableRobot* t , FlyableRobot* f)
        : Robot(w,t,f) {}

    
    void projection() override {
        cout << "Displaying friendly companion features... " << endl;
    }
};


class WorkerRobot : public Robot {
public:
    WorkerRobot(WalkableRobot* w , TalkableRobot* t , FlyableRobot* f) 
        : Robot(w,t,f) {}
    
    void projection() override {
        cout << "Displaying Worker Efficiently Stats ......" << endl;
    }
};


// Main Functions

int main() {
    Robot* r1 = new CompanionRobot(new NormalWalk() , new NormalTalk()  , new NoFly());
    r1->walk();
    r1->talk();
    r1->fly();
    r1->projection();

    cout<< "==========================================" << endl;

    Robot* r2 = new WorkerRobot(new NoWalk() , new NoTalk() , new NormalFly());
    r2->walk();
    r2->talk();
    r2->fly();
    r2->projection();


    return 0;
}

