class TV{
    private boolean power = false;//��Դ
    private int channel = 1;//Ƶ��1-200
    private int voice = 0;//����0-100
//    �޲ι���
    public  TV(){}
//    �вι���
    public  TV(boolean power,int channel,int voice){
        this.power = power;
        if(channel>0&&channel<200){
            this.channel = channel;
        }
        else {
            System.out.printf("Ƶ������1-200�����¶���");
        }
        if(voice>0&&voice<100){
            this.voice = voice;
        }
        else {
            System.out.printf("��������1-100�����¶���");
        }
    }
//    Ƶ������
    public void open(){System.out.println("ִ�в�������");this.power = true;}
    public void close(){System.out.println("ִ�в����ػ�");this.power = false;}
//    �л�Ƶ��
    public void channeladd(){
//        Ƶ�����
        if (this.channel<200){
            this.channel+=1;
            System.out.println("ִ�в���Ƶ����1");
        }
        else {
//            ����һ�������Ƶ��ʱ��Ϊ��Ҫ�ص�Ƶ��1
            this.channel = 1;
            System.out.println("��ǰƵ�����Ѵ������Ϊ������Ƶ��1");
        }
    }
    public void channeladd(int x){
//        Ƶ�����ӣ��������Ϊ��Ҫ���ӵ�Ƶ����
        if((this.channel+x)<200){
            this.channel+=x;
            System.out.printf("ִ�в���Ƶ������%d\n",x);
        }
        else {
//            ����200�Ĳ��ֻص�1���������
            int y = this.channel+x-200;
            this .channel = y;
            System.out.printf("��Ҫ��Ծ��Ƶ��������Χ����Ϊ���ص�Ƶ��1���ټ�����Ծ%d\n",y);
        }
    }
    public void channelsub(){
//        Ƶ�����
        if (this.channel>0){
            this.channel-=1;
            System.out.println("ִ�в���Ƶ����1");
        }
        else {
//            С��0�����Ƶ��ʱ��Ϊ��Ҫ�ص�Ƶ��200
            this.channel = 200;
            System.out.println("��ǰƵ�����Ѵ���С����Ϊ������Ƶ��200");
        }
    }
    public void channelsub(int x){
//        Ƶ���������������Ϊ��Ҫ���ٵ�Ƶ����
        if((this.channel-x)>0){
            this.channel-=x;
            System.out.printf("ִ�в���Ƶ����%d\n",x);
        }
        else {
//            ����200�Ĳ��ֻص�1���������
            int y = x - this.channel;
            this .channel = 200-y;
            System.out.printf("��Ҫ��Ծ��Ƶ��������Χ����Ϊ���ص�Ƶ��200���ټ�����Ծ%d\n",y);
        }
    }
//    ��������
    public void sound(int x){
        this.voice = x;
        System.out.printf("�����ѵ�����%d\n",this.voice);
    }
//    չʾ���ӻ�״̬
    public void show(){
        System.out.printf("��Դ���أ�%b\n",this.power);
        System.out.printf("Ƶ������%d\n",this.channel);
        System.out.printf("������С��%d\n",this.voice);
    }

}


class Main3 {
    public static void main(String[] args) {
        TV tv1 = new TV(true,55,77);
        System.out.println("TV1״̬:");
        tv1.show();
//        ����
        tv1.open();
        tv1.show();
//        �ػ�
        tv1.close();
        tv1.show();
//        �л�Ƶ��
//        ��
        tv1.channeladd();
        tv1.show();
        tv1.channeladd(44);
        tv1.show();
        tv1.channeladd(200);
        tv1.show();
//        ��
        tv1.channelsub();
        tv1.show();
        tv1.channelsub(44);
        tv1.show();
        tv1.channelsub(200);
        tv1.show();
//        ��������
        tv1.sound(99);
        tv1.show();
    }
}
