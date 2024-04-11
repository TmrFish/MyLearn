package work51;

public class Rectangle {
    //成员变量
    private double Long = 0;
    private double Wide = 0;

    //构造方法
    //矩形
    public Rectangle(double l, double wide) {
        Long = l;
        Wide = wide;
    }
    //正方形
    public Rectangle(double b){
        Long = Wide = b;
    }
    //无参构造方法
    public Rectangle(){
    }
    //get、set方法
    public double getLong() {
        return Long;
    }
    public void setLong(double l) {
        Long = l;
    }
    public double getWide() {
        return Wide;
    }
    public void setWide(double wide) {
        Wide = wide;
    }
    //求周长
    public double chang(){
        double chang = (this.Long+this.Wide)*2;
        return chang;
    }
    //求面积
    public double mianji(){
        double s = this.Long*this.Wide;
        return s;
    }
}
