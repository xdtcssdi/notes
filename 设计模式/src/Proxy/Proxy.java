package Proxy;

/**
 * @author oswin
 */
public class Proxy implements GiveGift {

    Pursuit xd;

    public Proxy(SchoolGirl mm) {
        xd = new Pursuit(mm);
    }

    @Override
    public void GiveDolls() {
        xd.GiveDolls();
    }

    @Override
    public void GiveFlowers() {
        xd.GiveFlowers();
    }

    @Override
    public void GiveChocolate() {
        xd.GiveChocolate();
    }
}
