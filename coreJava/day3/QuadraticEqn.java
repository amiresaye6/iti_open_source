package day3;

import java.util.function.Function;

class Eqn {
    float a;
    float b;
    float c;

    Eqn(float a, float b, float c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}

class Roots {
    float r1;
    float r2;

    Roots(float r1, float r2) {
        this.r1 = r1;
        this.r2 = r2;
    }

    void print() {
        System.out.println("first root is : " + this.r1 + " , and second root is : " + this.r2);
    }
}

public class QuadraticEqn implements Function<Eqn, Roots> {
    @Override
    public Roots apply(Eqn eq) {
        float r1, r2;
        float o = (eq.b * eq.b) - (4 * eq.a * eq.c);
        if (o < 0) // negative number under the root :__:
        {
            System.out.println("roots are imaginary numbers");
            return new Roots(0, 0);
        }
        r1 = (float) ((-eq.b + Math.sqrt(o)) / (2 * eq.a));
        r2 = (float) ((-eq.b - Math.sqrt(o)) / (2 * eq.a));

        return new Roots(r1, r2);
    }
}
