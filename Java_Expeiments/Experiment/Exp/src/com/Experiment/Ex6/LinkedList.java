package com.Experiment.Ex6;

public class LinkedList {
    private Node head;

    public LinkedList() {
        head = null;
    }

    public LinkedList(Object data) {
        Node node = new Node(data);
        this.head = node;
    }

    public void add(Object data) {
        Node node = new Node(data); //创建包含 data 值的 Node 节点
        if(head==null) {
            this.head = node;//链表为空，则当前节点就是第一个节点
        }
        else { //链表不为空，需要找到最后一个节点
            Node temp = head; //利用 temp 节点遍历

            while (temp.getNext() != null) {//temp 指向下一个节点
                temp = temp.getNext();
            }//temp 节点不是最后一个节点
             //循环结束时 temp 为最后一个节点
            temp.setNext(node); //把当前节点链接在最后一个节点之后
        }
    }

    public boolean remove(Object data){
        if(head == null){
            return false;
        }
        if(head.getData().equals(data)){
            head = head.getNext();
            return true;
        }

        Node temp = head;
        Node rec = null;
        while(temp.getNext()!=null){
            if(temp.getData().equals(data)){
                rec.setNext(temp.getNext());
                temp = null;
                return true;
            }
            rec = temp;
            temp = temp.getNext();
        }
        return  false;
    }

    public Node search(Object data){
        Node node = head;

        while(node!=null){
            if(node.getData().equals(data)){
                return node;
            }
            node = node.getNext();
        }
        return null;
    }

    public boolean insertAfter(Node previous,Object data){
        if(previous == null){
            return false;
        }

        Node node = new Node(data);
        node.setNext(previous.getNext());
        previous.setNext(node);
        return true;
    }

    public Node get(int index){
        if(index < 0){
            return null;
        }
        int count = 0;
        Node node = head;
        while (node != null){
            if(count == index){
                return node;
            }
            node = node.getNext();
            count++;
        }
        return null;
    }

    public boolean set(Node node,Object data){
        Node temp = head;
        while (temp!=null){
            if(temp.equals(node)){
                temp.setData(data);
                return true;
            }
            temp = temp.getNext();
        }
        return false;
    }

    public int size(){
        Node node = head;
        int count = 0;
        while (node != null){
            count++;
            node = node.getNext();
        }
        return count;
    }
}
