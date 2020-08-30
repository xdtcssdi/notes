package Builder;

/**
 * @author oswin
 */
public class Director {

    public void Construct(Builder builder){
        builder.BuildPartA();
        builder.BuildPartB();
    }
}
