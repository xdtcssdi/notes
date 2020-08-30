package Delegate;

import java.lang.reflect.Method;

/**
 * @author oswin
 */
public class Event {
    private Object object;
    private String methodName;
    private Object[] params;
    private Class[] paramTypes;

    public Event(Object obj,String methodName,Object... params){
        this.object=obj;
        this.methodName =methodName;
        this.params = params;
        contractParamTypes(params);
    }


    private void contractParamTypes(Object[] params)
    {
        this.paramTypes = new Class[params.length];
        for (int i=0;i<params.length;i++)
        {
            this.paramTypes[i] = params[i].getClass();
        }
    }
    public Object invoke() throws Exception
    {
        Method method = object.getClass().getMethod(this.methodName, this.paramTypes);//判断是否存在这个函数
        if (null == method)
        {
            return null;
        }
        return method.invoke(this.object, this.params);
    }
}
