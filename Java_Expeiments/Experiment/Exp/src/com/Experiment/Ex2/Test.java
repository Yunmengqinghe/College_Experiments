package com.Experiment.Ex2;

public class Test {
    public static void main(String[] args) {
        System.out.println("---样例一---");
        Circle circle_1 = new Circle();
        Circle circle_2 = new Circle(0,0,0);
        System.out.println(circle_1.relation(circle_2));

        System.out.println("---样例二---");
        Circle circle_3 = new Circle(0,0,1);
        System.out.println(circle_1.relation(circle_3));

        System.out.println("---样例三---");
        Circle circle_4 = new Circle(0,0,10);
        Circle circle_5 = new Circle(0,5,10);
        System.out.println(circle_4.relation(circle_5));

        System.out.println("---样例四---");
        Circle circle_6 = new Circle(0,20,10);
        System.out.println(circle_4.relation(circle_6));
    }
}
