class point {
//    ��Ա��������xy
    private double x = 0;
    private double y = 0;
//    �޲ι���ԭ��
    public  point(){
        this.x = 0;
        this.y = 0;
    }
//    �вι�����һ��
    public  point(double x,double y){
        this.x = x;
        this.y = y;
    }
//    չʾ������
    public String show() {return "("+x+","+y+")";}
//    �������
    public double distance(){
//        �������ԭ��֮��ľ���
        return Math.sqrt(Math.pow(this.x,2)+Math.pow(this.y,2));
    }
    public  double distance(point p ){
//        ������������
        return Math.sqrt(Math.pow(this.x-p.x,2)+Math.pow(this.y-p.y,2));
    }
//    �ƶ�λ��
    public point move(double x,double y){
        this.x = x;
        this.y = y;
        return this;
    }
    public point move(point p){
        this.x = p.x;
        this.y = p.y;
        return this;
    }
}
class Main2{
    public static void main(String[] args) {
        point start = new point();
        point end = new point(2,4);
        System.out.printf("���Ϊ:"+start.show());
        System.out.printf("�յ�Ϊ:"+end.show()+"\n");
        System.out.printf("ʹ��dis�޲η�������ľ���:%.2f\n",end.distance());
        System.out.printf("ʹ��dis�вη�������ľ���:%.2f\n",end.distance(start));
//        �����õ�����point
        point moveend = new point(5,10);
        System.out.printf("ʹ��move(x,y)�����ƶ�start,������ƶ����start����"+start.move(10,12).show()+"\n");
        System.out.printf("ʹ��move(point p)�����ƶ�start,������ƶ����start����"+start.move(moveend).show());
    }
}
