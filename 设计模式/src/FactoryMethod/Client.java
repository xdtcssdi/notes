package FactoryMethod;

import org.junit.Test;

/**
 * @author oswin
 */
public class Client {

    @Test
    public void test(){
        IFactory factory = new UndergraduateFactory();
        LeiFeng student = factory.CreateLeiFeng();
        student.BuyRice();
        student.Sweep();
        student.Wash();
    }
}
