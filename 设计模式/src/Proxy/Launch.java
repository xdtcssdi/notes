package Proxy;

import Factory.Operation;
import Factory.OperationFactory;
import org.junit.Test;

import java.util.Scanner;

/**
 * @author oswin
 */
public class Launch {
    @Test
    public void test() {

        SchoolGirl wnx = new SchoolGirl();
        wnx.setName("WNX");
        Proxy xd = new Proxy(wnx);
        xd.GiveDolls();
        xd.GiveFlowers();
        xd.GiveChocolate();
    }

}
