package work51;

public class Rectangle {
    //��Ա����
    private double Long = 0;
    private double Wide = 0;

    //���췽��
    //����
    public Rectangle(double l, double wide) {
        Long = l;
        Wide = wide;
    }
    //������
    public Rectangle(double b){
        Long = Wide = b;
    }
    //�޲ι��췽��
    public Rectangle(){
    }
    //get��set����
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
    //���ܳ�
    public double chang(){
        double chang = (this.Long+this.Wide)*2;
        return chang;
    }
    //�����
    public double mianji(){
        double s = this.Long*this.Wide;
        return s;
    }
}
