package Decorator.Decorator1;


/**
 * @author oswin
 */
public class ConcreteComponent implements Component {
    @Override
    public void Operation() {
        System.out.println("具体对象的操作");
    }
}
