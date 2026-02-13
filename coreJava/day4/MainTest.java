package day4;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

public class MainTest {

    public static void drawShapes(List<Shape> shapes) {
    // public static void drawShapes(List<? extends Shape> shapes) {
        for (Shape s : shapes) {
            s.draw();
        }
    }

    public static void main(String[] args) {
        System.out.println("\nday four tasks :__:");

        System.out.println("task 1, temp change using inner class");

        float x = 24;

        float res = new Function<Float, Float>() {
            @Override
            public Float apply(Float t) {
                return (float) (t * 1.8 + 32);
            }
        }.apply(x);

        System.out.println("temprature in fahrenhite is : " + res);

        System.out.println("task2, exceptoins");
        TestEceptionsFunctions test = new TestEceptionsFunctions();
        test.run();

        System.out.println("task3: draw shape");

        ArrayList<Shape> shapes = new ArrayList<Shape>();
        ArrayList<Shape> rectangles = new ArrayList<Shape>();

        for (int i = 0; i < 4; i++) {
            shapes.add(new Circle());
            rectangles.add(new Rectangle());
        }

        System.out.println("shapes array length: ");

        drawShapes(shapes);
        drawShapes(rectangles);
    }

}
