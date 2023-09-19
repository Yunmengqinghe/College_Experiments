package com.Experiment.Ex5;

public class MatrixTest {
        public static void main(String[] args) throws IllegalIndexException {
            System.out.println("\n--test1--");
            try {
                Matrix matrix = new Matrix(0,3);
            }
            catch (IllegalArgumentException e) {
                System.out.println(e.toString());
            }

            System.out.println("\n--test2--");
            double[][] data1 = {{1, 2, 3}, {4, 5, 6}};
            Matrix m1 = new Matrix(data1);
            System.out.println("Matrix 1:\n" + m1.toString());


            double[][] data2 = {{7, 8}, {9, 10}};
            Matrix m2 = new Matrix(data2);
            System.out.println("Matrix 3:\n" + m2.toString());

            try {
                System.out.println("矩阵相乘结果:\n" + m1.multiply(m2));
            }
            catch (MatrixMultiplicationException e) {
                System.out.println(e.toString());
            }

        }
}
