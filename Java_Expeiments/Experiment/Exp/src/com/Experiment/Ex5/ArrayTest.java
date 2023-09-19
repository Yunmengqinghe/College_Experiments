package com.Experiment.Ex5;

import java.util.Random;

public class ArrayTest {
    public static void main(String[] args) {
        Random random = new Random();
        int n = random.nextInt(0,11);
        int[] data = new int[n];
        for(int i=0;i<n;i++){
            int r = random.nextInt(0,11);
            data[i] = r;
        }
        ArrayReverser arrayReverser = new ArrayReverser(data);
        System.out.println(arrayReverser.toString());
        arrayReverser.reverse();
        System.out.println();
        System.out.println(arrayReverser.toString());
    }
}
