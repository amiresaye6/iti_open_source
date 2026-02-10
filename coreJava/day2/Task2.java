package day2;

public class Task2 {
    public static void main(String[] args) {
        String sentence = "java is fun and java is powerful, i love java";
        String targetWord = "java";

        Count c = new Count(sentence, targetWord);

        System.out.println("count with split");
        int a = c.countIndexOf();
        System.out.println(a);
        System.out.println("count with index of");
        int b = c.countSplit();
        System.out.println(b);
    }
}
