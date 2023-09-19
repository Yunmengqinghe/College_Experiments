package com.Experiment.Ex3;

import com.Experiment.Ex2.Circle;
import com.Experiment.Ex2.Point;

public class ColoredCircle extends Circle {
    public Color borderColor;
    public Color centerColor;
    public ColoredCircle(){
        super(0,0,0);
        borderColor = new Color();
        centerColor = new Color();
    }
    public ColoredCircle(Point center,int radius){
        super(center,radius);
        borderColor = new Color();
        centerColor = new Color();
    }

    public ColoredCircle(Color borderColor,Color centerColor){
        if (borderColor!=null)
            this.borderColor=borderColor;
        else
            this.borderColor = new Color();

        if (centerColor!=null)
            this.centerColor=centerColor;
        else
            this.centerColor=new Color();
    }

    public ColoredCircle(Point center,int radius,Color centerColor,Color borderColor){
        if (center!=null)
            this.center=center;
        else
            this.center=new Point();

        if (radius>=0)
            setRadius(radius);
        else
            setRadius(0);

        if (borderColor!=null)
            this.borderColor=borderColor;
        else
            this.borderColor = new Color();

        if (centerColor!=null)
            this.centerColor=centerColor;
        else
            this.centerColor=new Color();
    }

    public void setBorderColor(Color c) {
        borderColor = c;
    }
    public void setCenterColor(Color c) {
        centerColor = c;
    }

    public Color getBorderColor() {
        return borderColor;
    }

    public Color getCenterColor() {
        return centerColor;
    }

    @Override
    public int relation(Circle c) {
        double dis = center.distance(c.center);
        if (c instanceof ColoredCircle coloredCircle) {
            if (dis == 0 && getRadius() == c.getRadius() && getBorderColor().getBlue() == coloredCircle.getBorderColor().getBlue()
                    && getBorderColor().getRed() == coloredCircle.getBorderColor().getRed() &&  getBorderColor().getGreen() == coloredCircle.getBorderColor().getGreen()
                    && getCenterColor() == coloredCircle.getCenterColor() && getCenterColor().getBlue() == coloredCircle.getCenterColor().getBlue()
                    && getCenterColor().getGreen() == coloredCircle.getCenterColor().getGreen() && getCenterColor().getRed() == coloredCircle.getCenterColor().getRed()) {
                return 0;
            }
            else if (dis == 0) {
                return 1;
            }
            else if (dis <= getRadius() + c.getRadius()) {
                return 2;
            }
            else if (dis > getRadius() + c.getRadius()) {
                return 3;
            }
            else {
                return 4;
            }
        }
        else {
            if (dis == 0 && getRadius() == c.getRadius()) {
                return 1;
            } else if (dis <= getRadius() + c.getRadius()) {
                return 2;
            } else if (dis > getRadius() + c.getRadius()) {
                return 3;
            } else {
                return 4;
            }
        }
    }

    }


