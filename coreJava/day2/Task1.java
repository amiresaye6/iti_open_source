package day2;

public class Task1 {
    public static void main(String[] args) {
        String[] vals;
        IpCutter ic = new IpCutter("192.168.1.1");
        vals = ic.splitCut();
        for (int i = 0; i < vals.length; i++) {
            System.out.println(vals[i]);
        }
        ic.streingTokenizerCut();
        for (int i = 0; i < vals.length; i++) {
            System.out.println(vals[i]);
        }
    }
}
