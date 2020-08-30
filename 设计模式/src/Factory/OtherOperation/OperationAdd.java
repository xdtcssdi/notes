package Factory.OtherOperation;

import Factory.Operation;

/**
 * @author oswin
 */
public class OperationAdd extends Operation {
    @Override
    public double GetResult() {
        double result;
        result = get_numberA() + get_numberB();
        return result;
    }
}
