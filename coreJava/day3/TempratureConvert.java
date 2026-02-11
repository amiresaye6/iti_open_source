package day3;

import java.util.function.Function;

public class TempratureConvert implements Function<Float, Float> {
    @Override
    public Float apply(Float t) {
        return (float) (t * 1.8 + 32);
    }
}
