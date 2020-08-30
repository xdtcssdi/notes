package TemplateMethod;

import org.junit.Test;

/**
 * @author oswin
 */
public class Launch {

    @Test
    public void test() {
        AbstractClass c;
        c = new ConcreteClassA();
        c.TemplateMethod();

        c = new ConcreteClassB();
        c.TemplateMethod();

    }
}
