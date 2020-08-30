package Prototype.Resume;

import org.junit.Test;

/**
 * @author oswin
 */
public class Client {
    @Test
    public void test() throws CloneNotSupportedException {
        Resume a = new Resume("大鸟");
        a.SetPersonalInfo("男","29");
        a.SetWorkExperience("1998-2000","XX公司");

        Resume b = (Resume) a.clone();
        b.SetWorkExperience("1998-2006","YY企业");

        Resume c = (Resume) a.clone();
        c.SetWorkExperience("1998-2003","zz企业");
        a.Display();
        b.Display();
        c.Display();
    }
}
