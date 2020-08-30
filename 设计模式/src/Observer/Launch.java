package Observer;

import org.junit.Test;

/**
 * @author oswin
 */
public class Launch {

    @Test
    public void test(){
        ConcreteSubject s = new ConcreteSubject();
        s.Attach(new ConcreteObserver(s,"X"));
        s.Attach(new ConcreteObserver(s,"Y"));
        s.Attach(new ConcreteObserver(s,"Z"));

        s.setSubjectState("ABC");

        s.Notify();
    }
}
