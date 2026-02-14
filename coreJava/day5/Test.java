
import javax.swing.JFrame;

public class Test extends Thread {
    public static void main(String[] args) {
        JFrame clookFrame = new JFrame();

        clookFrame.setContentPane(new Clook());

        clookFrame.setTitle("Clook Task");
        clookFrame.setSize(800, 400);
        clookFrame.setVisible(true);

        JFrame marqueeFrame = new JFrame();

        marqueeFrame.setContentPane(new Marquee("Hi there", 100));

        marqueeFrame.setTitle("Marquee Task");
        marqueeFrame.setSize(800, 400);
        marqueeFrame.setVisible(true);

        JFrame bouncingBallFrame = new JFrame();

        bouncingBallFrame.setContentPane(new BouncingBall(20));

        bouncingBallFrame.setTitle("Bouncing Ball Task");
        bouncingBallFrame.setSize(400, 400);
        bouncingBallFrame.setVisible(true);
    }
}
