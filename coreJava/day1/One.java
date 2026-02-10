public class One {
    public static void main(String[] args) {
        System.out.println("botato chips");

        for (int i = 0; i < args.length; i++) {
            System.out.print(args[i] + " ");
        }
        System.out.println("\nprogram ended");

    }
}

class Two {
    public static void main(String[] args) {
        try {
            int iterations = Integer.parseInt(args[0]);

            for (int i = 0; i < iterations; i++) {
                System.out.println(args[i]);
            }

        } catch (NumberFormatException e) {
            System.out.println("first arg must be a valid number");
        }

    }
}