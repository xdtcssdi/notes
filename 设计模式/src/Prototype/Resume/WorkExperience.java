package Prototype.Resume;

/**
 * @author oswin
 */
public class WorkExperience implements Cloneable {

    private String workDate;

    public void setWorkDate(String workDate) {
        this.workDate = workDate;
    }

    public String getWorkDate() {
        return workDate;
    }
    private String company;

    public void setCompany(String company) {
        this.company = company;
    }

    public String getCompany() {
        return company;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}
