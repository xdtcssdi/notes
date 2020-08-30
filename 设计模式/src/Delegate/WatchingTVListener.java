package Delegate;

import java.util.Date;

/**
 * @author oswin
 */
public class WatchingTVListener {

    public WatchingTVListener()
    {
        System.out.println("watching TV");
    }

    public void stopWatchingTV(Date date)
    {
        System.out.println("stop watching" + date);
    }
}