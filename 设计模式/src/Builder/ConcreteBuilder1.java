package Builder;

import java.lang.ref.PhantomReference;

/**
 * @author oswin
 */
public class ConcreteBuilder1 extends Builder {
    private Product product = new Product();

    @Override
    public void BuildPartA() {
        product.Add("部件A");
    }

    @Override
    public void BuildPartB() {
        product.Add("部件B");
    }

    @Override
    public Product GetResult() {
        return product;
    }
}
