class triangle {
//  ��Ա����
    private int a;
    private int b;
    private int c;
    public triangle(){

    }
//  set����
    public void set(int a,int b,int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
//  get����
    public int getA() {
         return a;
    }
    public int getB() {
        return b;
    }
    public int getC() {
        return c;
    }
//  ����Ƿ�Ϊ������
     public boolean cheek(){
        if (a>0&&b>0&&c>0&&a+b>c&&a+c>b&&b+c>a){return true;}
        else {return false;}
     }
//  �������������
     public double mianji(){
        if (this.cheek()){
            double s = 0;
            double area = 0;
            s = (double) (a+b+c)/2;
            area = Math.sqrt(s*(s-a)*(s-b)*(s-c));
            return area;
        }
        else {
            System.out.println("��������������β�����");
            return 0;
        }
     }
//     �����������ܳ�
     public double zhouchang(){
        if(this.cheek()){
            double sjxlong = a+b+c;
            return sjxlong;
        }
        else{
            System.out.println("��������������β�����");
            return 0;
        }
     }

}

 class Main {
//  ������
    public static void main(String[] args) {
//        ������������
        triangle sanjiaoxing = new triangle();
//        ��ֵ
        int[] x = {3,4,5};
        sanjiaoxing.set(x[0],x[1],x[2]);
        System.out.printf("����������������߳�Ϊ%d��%d��%d\n",sanjiaoxing.getA(),sanjiaoxing.getB(),sanjiaoxing.getC());
//        �ж��Ƿ�Ϊ������
        System.out.printf("�Ƿ�Ϊ������:");
        System.out.println(sanjiaoxing.cheek());
//        �������
        System.out.printf("�����������:");
        System.out.println(sanjiaoxing.mianji());
//        �����ܳ�
        System.out.printf("���������ܳ�:");
        System.out.println(sanjiaoxing.zhouchang());
    }

}
