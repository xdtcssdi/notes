package Decorator.Decorator1;

/**
 * @author oswin
 */
public class ConcreteDecoratorA extends Decorator {

    @Override
    public void Operation() {
        System.out.println("ConcreteDecoratorA");
        super.Operation();


    }
}
