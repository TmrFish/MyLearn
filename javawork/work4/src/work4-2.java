class point {
//    成员变量坐标xy
    private double x = 0;
    private double y = 0;
//    无参构造原点
    public  point(){
        this.x = 0;
        this.y = 0;
    }
//    有参构造任一点
    public  point(double x,double y){
        this.x = x;
        this.y = y;
    }
//    展示点坐标
    public String show() {return "("+x+","+y+")";}
//    计算距离
    public double distance(){
//        计算点与原点之间的距离
        return Math.sqrt(Math.pow(this.x,2)+Math.pow(this.y,2));
    }
    public  double distance(point p ){
//        计算两点间距离
        return Math.sqrt(Math.pow(this.x-p.x,2)+Math.pow(this.y-p.y,2));
    }
//    移动位置
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
        System.out.printf("起点为:"+start.show());
        System.out.printf("终点为:"+end.show()+"\n");
        System.out.printf("使用dis无参方法计算的距离:%.2f\n",end.distance());
        System.out.printf("使用dis有参方法计算的距离:%.2f\n",end.distance(start));
//        测试用的输入point
        point moveend = new point(5,10);
        System.out.printf("使用move(x,y)方法移动start,并输出移动后的start坐标"+start.move(10,12).show()+"\n");
        System.out.printf("使用move(point p)方法移动start,并输出移动后的start坐标"+start.move(moveend).show());
    }
}
