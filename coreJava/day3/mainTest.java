package day3;

public class mainTest {
    public static void main(String[] args) {
        System.out.println("\ntesting task 1");
        TempratureConvert tc = new TempratureConvert();
        System.out.println("temprature in fahrenhite is: " + tc.apply((float)55.0));

        System.out.println("testing task 2");

            QuadraticEqn q = new QuadraticEqn();
            Roots rs = q.apply(new Eqn(1, -5, 6));

            rs.print();

    }
}
