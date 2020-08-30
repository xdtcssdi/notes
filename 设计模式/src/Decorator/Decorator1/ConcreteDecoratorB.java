package Decorator.Decorator1;


/**
 * @author oswin
 */
public class ConcreteDecoratorB extends Decorator {

    @Override
    public void Operation() {
        super.Operation();

        System.out.println("ConcreteDecoratorB");
    }
}
