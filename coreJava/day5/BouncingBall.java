import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

public class BouncingBall extends JPanel implements Runnable {
    int x, y;
    int vx, vy;
    int diameter;

    public BouncingBall(int diameter) {
        this.x = (int) (Math.random() * 100);
        this.vx = (int) (Math.random() * 100);
        this.y = (int) (Math.random() * 100);
        this.vy = (int) (Math.random() * 100);
        this.diameter = diameter;
        this.setBackground(Color.black);
        new Thread(this).start();

    }

    public void updatePositioni() {
        this.x += this.vx;
        if (this.y + this.vy > this.getHeight() || this.y + this.vy <= 0)
            this.vy *= -1;
        if (this.x + this.vx > this.getWidth() || this.x + this.vx <= 0)
            this.vx *= -1;
        this.y += this.vy;
        this.x += this.vx;
    }

    @Override
    public void run() {
        while (true) {
            try {
                this.repaint();
                updatePositioni();
                Thread.sleep(100);

            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.WHITE);
        g.fillOval(this.x, this.y, this.diameter, this.diameter);
    }
}
