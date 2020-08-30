package Builder;

import sun.jvm.hotspot.ui.action.ShowAction;

import java.util.ArrayList;
import java.util.List;

/**
 * @author oswin
 */
public class Product {
    List<String> parts = new ArrayList<>();
    public void Add(String part){
        parts.add(part);
    }
    public void Show(){
        System.out.println("\n创建 ---");
        for (String part:parts){
            System.out.println(part);
        }
    }
}
