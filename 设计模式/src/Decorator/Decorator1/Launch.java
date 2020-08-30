package Decorator.Decorator1;

import org.junit.Test;

/**
 * @author oswin
 */
public class Launch {

    @Test
    public void test(){
        ConcreteComponent c = new ConcreteComponent();
        ConcreteDecoratorA d1 = new ConcreteDecoratorA();
        ConcreteDecoratorB d2 = new ConcreteDecoratorB();

        d1.setComponent(c);
//        d2.setComponent(d1);
//        d2.Operation();
        d1.Operation();

    }
}
