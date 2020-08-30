package Factory;

import org.junit.Test;

import java.util.Scanner;

/**
 * @author oswin
 */
public class Launch {
    @Test
    public void test() {

        Scanner scanner = new Scanner(System.in);

        double numberA = scanner.nextDouble();
        String operate = scanner.next();
        double numberB = scanner.nextDouble();

        Operation operate1 = OperationFactory.
                createOperate(operate);

        operate1.set_numberA(numberA);
        operate1.set_numberB(numberB);

        try {
            double result = operate1.GetResult();
            System.out.println(result);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
