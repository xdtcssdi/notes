package TemplateMethod;

/**
 * @author oswin
 */
public class ConcreteClassB extends AbstractClass {
    @Override
    public void PrimitiveOperation1() {
        System.out.println("具体类B方法1实现");
    }

    @Override
    public void PrimitiveOperation2() {
        System.out.println("具体类B方法2实现");
    }
}
