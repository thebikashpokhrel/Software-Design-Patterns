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
    Duck(IFlyBehaviour *fb, IQuackBehaviour *qck)
    {
        flyBehaviour = fb;
        quackBehaviour = qck;
    }
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
    MallardDuck() : Duck(new FlyWithWings(), new Quack()) {}

    void display()
    {
        cout << "Displaying Mallard Duck\n";
    }
};

// main function
int main()
{
    MallardDuck md;
    md.display();
    md.performQuack();
    md.performFly();
    return 0;
}