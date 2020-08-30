package Delegate;

import org.junit.Test;

import java.util.Date;

/**
 * @author oswin
 */
public class Launch {
    @Test
    public void test(){
        Notifier goodNotifier = new ConcreteNotifier();

        PlayingGameListener playingGameListener = new PlayingGameListener();

        WatchingTVListener watchingTVListener = new WatchingTVListener();

        goodNotifier.addListener(playingGameListener, "stopPlayingGame", new Date());

        goodNotifier.addListener(watchingTVListener, "stopWatchingTV", new Date());

        goodNotifier.notifyX();
    }
}
