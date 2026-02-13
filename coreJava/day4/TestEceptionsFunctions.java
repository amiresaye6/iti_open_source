package day4;

public class TestEceptionsFunctions {
    public void run() {
        ATM f = new ATM(1000);
        try {
            f.withdraw(30); // will pass
            f.deposit(70); // will thow an exception
            boolean cond = f.checkLimit(501); // will thow an error too....
            System.err.println(cond);
        } catch (CustomException e) {
            System.out.println(e);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        } finally {
            System.out.println("program ended :::");
        }
    }
}
