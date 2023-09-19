package com.Experiment.Ex5;

public class Test {
    public static void main(String[] args) {
        System.out.println("\n--test1--");
        ArrayReverser arrayReverser = new ArrayReverser(null);
        System.out.println(arrayReverser.getData().length);

        System.out.println("\n--test2--");
        int[] arr1 = {1, 2, 3, 4, 5, 6};
        ArrayReverser arrayReverser1 = new ArrayReverser(arr1);
        System.out.println(arrayReverser1.toString());
        int[] arr2 = arrayReverser1.getData();
        for (int i =0;i<arrayReverser1.getData().length;i++){
            if(i==0)
                System.out.print("[");
            System.out.print(arr2[i]);
            if(i<arr2.length-1)
                System.out.print(",");
            if(i==arr2.length-1){
                System.out.println("]");
            }
        }

        System.out.println("\n--test2--");
        ArrayReverser ar = new ArrayReverser(arr1);
        ar.setData(null);
        System.out.println(ar.toString());

        System.out.println("\n--test3--");
        int[] arr3 = {1,2,3};
        ar.setData(arr3);
        System.out.println(ar.toString());

        System.out.println("\n--test4--");

    }

}
