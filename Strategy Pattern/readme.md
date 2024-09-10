# Strategy Pattern

### Strategy Pattern Overview:

According to the Book, The **Strategy Pattern** is a design pattern that defines a family of algorithms, encapsulates each one, and makes them interchangeable. It allows the algorithm to vary independently from the clients that use it.

In simpler terms, the Strategy Pattern enables a class to change its behavior at runtime by using different strategies (or algorithms). It promotes flexibility by allowing objects to select different behavior dynamically without changing their code.

### Example Overview:

In this example, I implemented the Strategy Pattern by creating two interfaces: `IFlyBehaviour` and `IQuackBehaviour`. Each interface represents a family of algorithms for flying and quacking behaviors, respectively. Specific classes then implement these interfaces, representing different types of flying and quacking behaviors.

The `Duck` class uses these behavior interfaces to determine how it flies and quacks without needing to know the specifics of the implementation. This approach allows flexibility: we can easily change a duck's flying or quacking behavior during runtime by swapping strategies.

### Code Breakdown:

**Interfaces:**

- `IFlyBehaviour`: Defines the `fly()` function that all flying behavior classes must implement.
- `IQuackBehaviour`: Defines the `quack()` function that all quacking behavior classes must implement.

**Concrete Behavior Classes:**

- **Flying behaviors**: `FlyWithWings`, `FlyWithRocket`, `FlyNoWay`.
- **Quacking behaviors**: `Quack`, `Squeak`, `NoQuack`.

**Duck Class:**

- The `Duck` class holds references to `IFlyBehaviour` and `IQuackBehaviour` objects, allowing it to perform `fly()` and `quack()` actions.
- We can dynamically change the duck's behavior by using setter methods (`setFlyBehaviour()`, `setQuackBehaviour()`).

**Specific Duck Types:**

- `MallardDuck`, `RubberDuck`, and `ModelDuck` are specific duck types that inherit from `Duck`. Each duck type initializes with different flying and quacking behaviors.

**Runtime Behavior Changes:**

- The `ModelDuck` can change its flying behavior at runtime, demonstrating the flexibility of the Strategy Pattern. For example, it starts with `FlyNoWay` but can switch to `FlyWithRocket` during runtime.

### Key Takeaway:

**Favoring Composition over Inheritance:**  
The Strategy Pattern follows the principle of "favoring composition over inheritance." Instead of inheriting behaviors, the pattern composes classes with the right behaviors, providing more flexibility. This approach (i.e., using a "has-a" relationship) allows us to mix and match behaviors dynamically, rather than relying on static inheritance ("is-a"), making it easier to adapt to changing requirements.
