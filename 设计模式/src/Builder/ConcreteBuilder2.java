package Builder;

/**
 * @author oswin
 */
public class ConcreteBuilder2 extends Builder {
    private Product product = new Product();

    @Override
    public void BuildPartA() {
        product.Add("部件X");
    }

    @Override
    public void BuildPartB() {
        product.Add("部件Y");
    }

    @Override
    public Product GetResult() {
        return product;
    }
}
