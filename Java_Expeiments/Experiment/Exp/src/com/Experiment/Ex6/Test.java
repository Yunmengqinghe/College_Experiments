package com.Experiment.Ex6;

public class Test {

    public static void main(String[] args) {
        LinkedList list=new LinkedList();
        System.out.println("Test1："+list.size()+" "+list.get(0)+" "+list.search(1)+" "+list.remove(1));
        list.add(1);
        list.add(2);
        list.add(3);
        System.out.println("Test2："+list.size());
        Node p=list.search(22);
        System.out.println("Test3："+p);
        p=list.search(2);
        System.out.println("Test4："+p);
        System.out.println("Test5："+list.set(null,"22"));
        list.set(p,22);
        System.out.println("Test6："+p);
        list.insertAfter(p, 23);
        System.out.println("Test7："+list.size());
        System.out.println("Test8："+list.insertAfter(null, 23));
        System.out.println("Test9："+list.remove(12));
        System.out.println("Test10："+list.remove(22));
        p=list.get(0);
        System.out.println("Test11："+p);
        p=list.get(-1);
        System.out.println("Test12："+p);
        p=list.get(100);
        System.out.println("Test13："+p);

    }
}
