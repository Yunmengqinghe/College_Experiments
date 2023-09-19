package com.Experiment.Ex4;

import com.Experiment.Ex2.Circle;
import com.Experiment.Ex2.Point;

public class Test {
    public static void main(String[] args) {
        System.out.println("\n--test1--");
        Ex4_Point p1 = new Ex4_Point();
        Ex4_Point p2 = new Ex4_Point(0,10);
        System.out.println("p1.x=" + p1.getX() + " p1.y=" + p1.getY() + " p2.distance=" + p1.distance(p2));

        System.out.println("\n--test2--");
        Ex4_Circle c1 = new Ex4_Circle();
        Ex4_Circle c2 = new Ex4_Circle(0,0,10);
        System.out.println("c1.x=" + c1.getCenter().getX() + " c1.y=" + c1.getCenter().getY());
        System.out.println("c1.area=" + c1.area() + "c1.perimeter=" + c1.perimeter());
        System.out.println(c1.relation(c2));

        System.out.println("\n--test3 4-");
        System.out.println("p1=" + p1.toString());
        System.out.println("p2=" + c1.toString());

        System.out.println("\n--test5-");
        System.out.println(p1.equals(p2));

        System.out.println("\n--test6-");
        p2=new Ex4_Point(0,0);
        System.out.println(p1.equals(p2));

        System.out.println("\n--test7-");
        Point p3 = new Point();
        System.out.println(p1.equals(p3));

        System.out.println("\n--test8-");
        Point p4 = new Point();
        System.out.println(p4.equals(p3));

        System.out.println("\n--test9-");
        System.out.println(c1.equals(c2));

        System.out.println("\n--test10-");
        c2= new Ex4_Circle(0,0,0);
        System.out.println(c1.equals(c2));

        System.out.println("\n--test11-");
        c2 = new Ex4_Circle(p1,0);
        System.out.println("1:" + c1.equals(c2));
        System.out.println("2:" + c1.equals(p1));
        System.out.println("3:" + p1.equals(c1));

        System.out.println("\n--test12-");
        c2 = new Ex4_Circle(p3,0);
        System.out.println(c1.equals(c2));

        System.out.println("\n--test13-");
        Circle c3 = new Circle(0,0,0);
        System.out.println("1:" + c1.equals(c3));
        System.out.println("2:" + c3.equals(c1));
    }
}
