package com.Experiment.Ex2;

public class Circle {
    public Point center;
    public int radius;
    public Circle(){
        center = new Point(0,0);
        radius = 0;
    }

    public Circle(int x,int y,int r){
        center = new Point(x,y);
        if(r<0)
            radius=0;
        else
            radius = r;
    }

    public Circle(Point c,int r){
        if (c==null){
            center=new Point(0,0);
        }
        else
            center=c;
        if(r<0)
            radius=0;
        else
            radius = r;
    }

    public Point getCenter() {
        return center;
    }

    public void setCenter(Point center) {
        this.center = center;
    }

    public void setRadius(int radius){
        if(radius>=0)
            this.radius=radius;
        else
            this.radius=0;
    }
    public int getRadius(){
        return radius;
    }
    public double perimeter(){
        return 2 * Math.PI * radius;
    }

    public double area(){
        return Math.PI * Math.pow(radius,2);
    }

    public int relation(Circle c){
        double dis = center.distance(c.center);
        if(dis == 0 && radius==c.radius){
            return 0;
        }
        else if(dis == 0){
            return 1;
        }
        else if(dis < radius + c.radius){
            return  2;
        }
        else if(dis >= radius + c.radius){
            return  3;
        }
        else {
            return 4;
        }
    }
}
