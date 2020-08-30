package Factory;

/**
 * @author oswin
 */
public abstract class Operation {
    private double _numberA;
    private double _numberB;

    protected double get_numberA() {
        return _numberA;
    }

    protected double get_numberB() {
        return _numberB;
    }

    public void set_numberA(double _numberA) {
        this._numberA = _numberA;
    }

    public void set_numberB(double _numberB) {
        this._numberB = _numberB;
    }
    public abstract double GetResult() throws Exception;
}
