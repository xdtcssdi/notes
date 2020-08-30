package Facade;

import org.junit.Test;

/**
 * @author oswin
 */
public class Launch {
    @Test
    public void test(){
        Facade facade = new Facade();
        facade.MethodA();
        facade.MethodB();

    }
}
