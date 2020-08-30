package Prototype.Resume;

/**
 * @author oswin
 */
public class Resume implements Cloneable {

    private String name;
    private String sex;
    private String age;
    private WorkExperience work;

    public Resume(String name) {
        this.name = name;
        this.work = new WorkExperience();
    }

    public Resume(WorkExperience work) {

        try {
            this.work = (WorkExperience) work.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
    }

    public void SetPersonalInfo(String sex, String age) {
        this.sex = sex;
        this.age = age;
    }

    public void SetWorkExperience(String timeArea, String company) {
        this.work.setCompany(company);
        this.work.setWorkDate(timeArea);
    }

    public void Display() {
        System.out.println(name + " " + sex + " " + age);
        System.out.println(this.work.getWorkDate() + " " + this.work.getCompany());
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public void setAge(String age) {
        this.age = age;
    }

    @Override
    protected Object clone() {
        Resume obj = new Resume(this.work);
        obj.setName(this.name);
        obj.setAge(this.age);
        obj.setSex(this.sex);
        return obj;
    }
}
