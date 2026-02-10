package day2;

import java.util.Arrays;
import java.util.Random;

public class Task3 {

    public static void main(String[] args) {
        int[] data = new int[1000];
        Random rand = new Random();
        for (int i = 0; i < data.length; i++) {
            data[i] = rand.nextInt(10000);
        }
        // zipkin >> search!!!!
        long startMinMax = System.nanoTime();

        int min = data[0];
        int max = data[0];
        for (int i = 1; i < data.length; i++) {
            if (data[i] < min) {
                min = data[i];
            }
            if (data[i] > max) {
                max = data[i];
            }
        }

        long endMinMax = System.nanoTime();
        System.out.println("Min/Max Extraction");
        System.out.println("Min: " + min);
        System.out.println("Max: " + max);
        System.out.println("Time taken: " + (endMinMax - startMinMax) + " ns");
        System.out.println();

        Arrays.sort(data);
        int target = data[rand.nextInt(1000)];

        long startBinary = System.nanoTime();
        int resultIndex = binarySearch(data, target);
        long endBinary = System.nanoTime();

        System.out.println("Binary Search");
        System.out.println("Target to find: " + target);
        if (resultIndex != -1) {
            System.out.println("Found at sorted index: " + resultIndex);
        } else {
            System.out.println("Not found.");
        }
        System.out.println("Time taken: " + (endBinary - startBinary) + " ns");
    }

    public static int binarySearch(int[] arr, int target) {
        int low = 0;
        int high = arr.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
}