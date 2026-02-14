import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.util.Date;

public class Clook extends JPanel implements Runnable {
    public Clook() {
        this.setBackground(Color.cyan);
        new Thread(this).start();
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setFont(new Font("Monospaced", Font.BOLD, 30));
        g.drawString(new Date().toLocaleString(), 100, 100);
    }

    @Override
    public void run() {
        while (true) {
            try {
                this.repaint();
                Thread.sleep(1000);

            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }

}
