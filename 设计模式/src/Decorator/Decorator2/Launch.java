package Decorator.Decorator2;

import org.junit.Test;

/**
 * @author oswin
 */
public class Launch {

    @Test
    public void test(){

        Person xc = new Person("小菜");
        BigTrouser kk = new BigTrouser();
        TShirts dtx = new TShirts();

        kk.Decorate(xc);
        dtx.Decorate(kk);
        dtx.Show();

    }
}
