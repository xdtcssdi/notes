package Observer;

import java.util.ArrayList;
import java.util.List;

/**
 * @author oswin
 */
public abstract class Subject {
    private List<Observer> observers = new ArrayList<>();
    public void Attach(Observer observer){
        observers.add(observer);
    }
    public void Detach(Observer observer){
        observers.remove(observer);
    }
    public void Notify(){
        for (Observer observer:observers){
            observer.Update();
        }
    }
}
