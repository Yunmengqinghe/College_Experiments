package com.Experiment.Ex3;

import com.Experiment.Ex2.Circle;
import com.Experiment.Ex2.Point;

public class Test {
    public static void main(String[] args) {
        System.out.println("--test1--");
        Point p=new Point();
        //System.out.println(p.x + p.y);
        Circle c=new Circle();
        //System.out.println(c.center + c.radius);

        System.out.println("--test2--");
        Color col = new Color();
        System.out.println("红色：" + col.getRed() + " 绿色：" + col.getGreen() + "蓝色：" + col.getBlue());
        System.out.println();

        System.out.println("--test3--");
        col=new Color(255,255,255);
        System.out.println("红色：" + col.getRed() + " 绿色：" + col.getGreen() + "蓝色：" + col.getBlue());
        System.out.println();

        System.out.println("--test4--");
        col=new Color(355,355,355);
        System.out.println("红色：" + col.getRed() + " 绿色：" + col.getGreen() + "蓝色：" + col.getBlue());
        System.out.println();

        System.out.println("--test5--");
        ColoredCircle colc = new ColoredCircle();
        System.out.println("半径:" + colc.getRadius() + " 面积:" + colc.area() + " 周长:" + colc.perimeter());
        System.out.println("x:" + colc.center.getX() + " y:" + colc.center.getY());
        System.out.println(" bordercolor:" + colc.getBorderColor().red + " " + colc.getBorderColor().green + " " + colc.getBorderColor().blue);
        System.out.println(" centercolor:" + colc.getCenterColor().red + " " + colc.getCenterColor().green + " " + colc.getCenterColor().blue);
        System.out.println();
        colc = new ColoredCircle(null,-1);
        System.out.println("半径:" + colc.getRadius() + " 面积:" + colc.area() + " 周长:" + colc.perimeter());
        System.out.println("x:" + colc.center.getX() + " y:" + colc.center.getY());
        System.out.println(" bordercolor:" + colc.getBorderColor().red + " " + colc.getBorderColor().green + " " + colc.getBorderColor().blue);
        System.out.println(" centercolor:" + colc.getCenterColor().red + " " + colc.getCenterColor().green + " " + colc.getCenterColor().blue);
        System.out.println();
        colc=new ColoredCircle(null,null);
        System.out.println("半径:" + colc.getRadius() + " 面积:" + colc.area() + " 周长:" + colc.perimeter());
        System.out.println("x:" + colc.center.getX() + " y:" + colc.center.getY());
        System.out.println(" bordercolor:" + colc.getBorderColor().red + " " + colc.getBorderColor().green + " " + colc.getBorderColor().blue);
        System.out.println(" centercolor:" + colc.getCenterColor().red + " " + colc.getCenterColor().green + " " + colc.getCenterColor().blue);
        System.out.println();

        System.out.println("--test6--");
        colc=new ColoredCircle(new Point(0,0),10);
        System.out.println("半径:" + colc.getRadius() + " 面积:" + colc.area() + " 周长:" + colc.perimeter());
        System.out.println("x:" + colc.center.getX() + " y:" + colc.center.getY());
        System.out.println(" bordercolor:" + colc.getBorderColor().red + " " + colc.getBorderColor().green + " " + colc.getBorderColor().blue);
        System.out.println(" centercolor:" + colc.getCenterColor().red + " " + colc.getCenterColor().green + " " + colc.getCenterColor().blue);
        System.out.println();

        System.out.println("--test7--");
        colc=new ColoredCircle(new Color(0,0,0),new Color(1,1,1));
        System.out.println("半径:" + colc.getRadius() + " 面积:" + colc.area() + " 周长:" + colc.perimeter());
        System.out.println("x:" + colc.center.getX() + " y:" + colc.center.getY());
        System.out.println(" bordercolor:" + colc.getBorderColor().red + " " + colc.getBorderColor().green + " " + colc.getBorderColor().blue);
        System.out.println(" centercolor:" + colc.getCenterColor().red + " " + colc.getCenterColor().green + " " + colc.getCenterColor().blue);
        System.out.println();

        System.out.println("--test8--");
        colc=new ColoredCircle(null,-10,null,null);
        System.out.println("半径:" + colc.getRadius() + " 面积:" + colc.area() + " 周长:" + colc.perimeter());
        System.out.println("x:" + colc.center.getX() + " y:" + colc.center.getY());
        System.out.println(" bordercolor:" + colc.getBorderColor().red + " " + colc.getBorderColor().green + " " + colc.getBorderColor().blue);
        System.out.println(" centercolor:" + colc.getCenterColor().red + " " + colc.getCenterColor().green + " " + colc.getCenterColor().blue);
        System.out.println();

    }

}
