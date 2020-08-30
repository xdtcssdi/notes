package Factory;

import Factory.OtherOperation.OperationAdd;
import Factory.OtherOperation.OperationDiv;
import Factory.OtherOperation.OperationMul;
import Factory.OtherOperation.OperationSub;

/**
 * @author oswin
 */
public class OperationFactory {

    public static Operation createOperate(String operate) {
        Operation oper = null;
        switch (operate) {
            case "+":
                oper = new OperationAdd();
                break;
            case "-":
                oper = new OperationSub();
                break;
            case "*":
                oper = new OperationMul();
                break;
            case "/":
                oper = new OperationDiv();
                break;
        }
        return oper;
    }

}
