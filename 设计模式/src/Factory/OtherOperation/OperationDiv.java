package Factory.OtherOperation;

import Factory.Operation;

/**
 * @author oswin
 */
public class OperationDiv extends Operation {
    @Override
    public double GetResult() throws Exception {
        double result;

        double numberB = get_numberB();
        if (numberB == 0){
            throw  new Exception("除数不能为0");
        }

        result = get_numberA() / numberB;
        return result;
    }
}
