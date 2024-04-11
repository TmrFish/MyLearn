class triangle {
//  成员变量
    private int a;
    private int b;
    private int c;
    public triangle(){

    }
//  set方法
    public void set(int a,int b,int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
//  get方法
    public int getA() {
         return a;
    }
    public int getB() {
        return b;
    }
    public int getC() {
        return c;
    }
//  检查是否为三角形
     public boolean cheek(){
        if (a>0&&b>0&&c>0&&a+b>c&&a+c>b&&b+c>a){return true;}
        else {return false;}
     }
//  计算三角形面积
     public double mianji(){
        if (this.cheek()){
            double s = 0;
            double area = 0;
            s = (double) (a+b+c)/2;
            area = Math.sqrt(s*(s-a)*(s-b)*(s-c));
            return area;
        }
        else {
            System.out.println("发生错误该三角形不成立");
            return 0;
        }
     }
//     计算三角形周长
     public double zhouchang(){
        if(this.cheek()){
            double sjxlong = a+b+c;
            return sjxlong;
        }
        else{
            System.out.println("发生错误该三角形不成立");
            return 0;
        }
     }

}

 class Main {
//  测试类
    public static void main(String[] args) {
//        创建三角形类
        triangle sanjiaoxing = new triangle();
//        赋值
        int[] x = {3,4,5};
        sanjiaoxing.set(x[0],x[1],x[2]);
        System.out.printf("您输入的三角形三边长为%d、%d、%d\n",sanjiaoxing.getA(),sanjiaoxing.getB(),sanjiaoxing.getC());
//        判断是否为三角形
        System.out.printf("是否为三角形:");
        System.out.println(sanjiaoxing.cheek());
//        计算面积
        System.out.printf("该三角形面积:");
        System.out.println(sanjiaoxing.mianji());
//        计算周长
        System.out.printf("该三角形周长:");
        System.out.println(sanjiaoxing.zhouchang());
    }

}
