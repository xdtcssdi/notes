package Observer;

/**
 * @author oswin
 */
public class ConcreteSubject extends Subject {
    private String subjectState;

    public void setSubjectState(String subjectState) {
        this.subjectState = subjectState;
    }

    public String getSubjectState() {
        return subjectState;
    }
}
