#include <iostream>
using namespace std;

// FlyBehaviour Interface
class IFlyBehaviour
{
public:
    virtual void fly() = 0;
};

// QuackBehaviour Interface
class IQuackBehaviour
{
public:
    virtual void quack() = 0;
};

// Set of classes to represent each Flying Behaviour
class FlyWithWings : public IFlyBehaviour
{
public:
    void fly() override
    {
        cout << "Flying with wings....\n";
    };
};

class FlyWithRocket : public IFlyBehaviour
{
public:
    void fly()
    {
        cout << "Flying with rocket...\n";
    }
};

class FlyNoWay : public IFlyBehaviour
{
public:
    void fly()
    {
        cout << "I cannot fly\n";
    }
};

// Set of Classes to represent each Quacking Behavour
class Quack : public IQuackBehaviour
{
public:
    void quack()
    {
        cout << "Quacking...\n";
    }
};

class Squeak : public IQuackBehaviour
{
public:
    void quack()
    {
        cout << "Squeaking...\n";
    }
};

class NoQuack : public IQuackBehaviour
{
public:
    void quack()
    {
        cout << "I cannot quack...\n";
    }
};

// Base class Duck
class Duck
{
    IFlyBehaviour *flyBehaviour;
    IQuackBehaviour *quackBehaviour;

public:
    Duck() {};

    // Behaviour Setters
    void setFlyBehaviour(IFlyBehaviour *fb)
    {
        flyBehaviour = fb;
    }

    void setQuackBehaviour(IQuackBehaviour *qck)
    {
        quackBehaviour = qck;
    }

    // Behaviour definitions
    void performQuack()
    {
        quackBehaviour->quack();
    }

    void performFly()
    {
        flyBehaviour->fly();
    }
};

// Specific ducks
class MallardDuck : public Duck
{
public:
    MallardDuck()
    {
        setFlyBehaviour(new FlyWithWings());
        setQuackBehaviour(new Quack());
    }

    void display()
    {
        cout << "Displaying Mallard Duck\n";
    }
};

class RubberDuck : public Duck
{
public:
    RubberDuck()
    {
        setFlyBehaviour(new FlyNoWay());
        setQuackBehaviour(new Squeak());
    }

    void display()
    {
        cout << "Displaying rubber duck\n";
    }
};

class ModelDuck : public Duck
{
public:
    ModelDuck()
    {
        setFlyBehaviour(new FlyNoWay());
        setQuackBehaviour(new Quack());
    }

    void display()
    {
        cout << "I am a model duck\n";
    }
};
// main function
int main()
{
    MallardDuck md;
    md.display();
    md.performQuack();
    md.performFly();
    cout << "\n";

    RubberDuck rd;
    rd.display();
    rd.performQuack();
    rd.performFly();
    cout << "\n";

    ModelDuck mod;
    mod.display();
    mod.performQuack();
    mod.performFly();
    // Changing ModelDuck flying behaviour during during runtime
    mod.setFlyBehaviour(new FlyWithRocket());
    mod.performFly();

    return 0;
}