package com.Experiment.Ex5;

public class Matrix {
    private double[][] data;

    public Matrix(int rows,int cols) throws IllegalArgumentException {
        if(rows<1||cols<1){
            throw new IllegalArgumentException("矩阵行数或列数非法！");
        }
        this.data = new double[rows][cols];
    }

    public Matrix(double[][] data) throws IllegalIndexException {
        if(data==null || data[0].length ==0 || data.length ==0){
            this.data = new double[2][2];
            throw new IllegalIndexException("参数不能为空");
        }
        else if (data.length <=0){
            throw new IllegalIndexException("行号<0, 行号>=行数");
        }
        else if(data[0].length <= 0){
            throw new IllegalIndexException("列号<0, 列号>=行数");
        }
        this.data = data;
    }

    public double getData(int rows,int cols) {
        return this.data[rows][cols];
    }

    public void setData(int rows,int cols) throws IllegalIndexException {
        if(rows<=0 || cols<=0){
            throw new IllegalIndexException("设置行数或列数不合法");
        }
        else {
            data = new double[rows][cols];
        }
    }

    public void setData(int rows,int cols,double value) throws IllegalIndexException {
        if(rows<=0 || cols<=0){
            throw new IllegalIndexException("设置行数或列数不合法");
        }
        this.data[rows][cols] = value;
    }

    public int getRows(){
        return this.data.length;
    }
    public int getCols(){
        return this.data[0].length;
    }

    public Matrix multiply(Matrix m) throws MatrixMultiplicationException, IllegalIndexException {
        if(getCols()!=m.getRows() || m==null){
            throw new MatrixMultiplicationException("不符合矩阵相乘的要求");
        }
        double[][] matrix = new double[getRows()][m.getCols()];
        Matrix result = new Matrix(matrix);
        int n=getRows(),p=getCols(),q=m.getCols();
        for (int i=0;i<n;i++){//m1的行数
            for(int j=0;j<q;j++){//m2的列数
                for(int k=0;k<p;k++) {//m1的行数，m2的列数
                    result.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Matrix matrix){
            if(matrix==this){
                return true;
            }
            if(this.getRows()==matrix.getRows() && this.getCols()== matrix.getCols()){
                return true;
            }
            for(int i =0; i < this.getRows(); i++){
                for(int j=0;j < this.getCols(); j++){
                    if(this.data[i][j]!=matrix.data[i][j]){
                        return false;
                    }
                }
            }
            return true;
        }
        return false;
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        for(int i =0; i < this.getRows(); i++){
            for(int j=0;j < this.getCols(); j++){
                s.append(this.data[i][j]);
                s.append("  ");
            }
            s.append("\n");
        }
        return s.toString();
    }
}
