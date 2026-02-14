import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;

public class Marquee extends JPanel implements Runnable {
    String statment = "Botato Chips";
    int xTravel = 0;
    int speed = 1000;

    public Marquee(String statment, int speed) {
        this.setBackground(Color.magenta);
        new Thread(this).start();
        this.statment = statment;
        this.speed = speed;
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setFont(new Font("Monospaced", Font.BOLD, 30));
        g.drawString(statment, this.xTravel, 100);
    }

    @Override
    public void run() {
        while (true) {
            try {
                this.repaint();
                if (xTravel + 10 >= this.getWidth()) {
                    xTravel = 0;
                } else {
                    xTravel += 10;
                }
                Thread.sleep(speed);

            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }

}