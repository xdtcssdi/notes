package Prototype.exp;

import org.junit.Test;

/**
 * @author oswin
 */
public class Client {
    @Test
    public void test(){
        ConcretePrototype1 p1 = new ConcretePrototype1("I");
        ConcretePrototype1 c1 = null;
        try {
            c1 = (ConcretePrototype1)p1.clone();

        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
        System.out.println(c1.getId());
        c1.show();

        System.out.println(p1.getName().hashCode());
        System.out.println(c1.getName().hashCode());

    }
}
