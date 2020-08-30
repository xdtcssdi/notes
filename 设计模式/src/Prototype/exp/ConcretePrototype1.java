package Prototype.exp;


/**
 * @author oswin
 */
public class ConcretePrototype1 extends Prototype {
    private String name;
    public ConcretePrototype1(String id) {
        super(id);
        name="QAQ";
    }
    public void show(){
        System.out.println(name);
    }

    public String getName() {
        return name;
    }
}
