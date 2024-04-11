class TV{
    private boolean power = false;//电源
    private int channel = 1;//频道1-200
    private int voice = 0;//音量0-100
//    无参构造
    public  TV(){}
//    有参构造
    public  TV(boolean power,int channel,int voice){
        this.power = power;
        if(channel>0&&channel<200){
            this.channel = channel;
        }
        else {
            System.out.printf("频道数在1-200请重新定义");
        }
        if(voice>0&&voice<100){
            this.voice = voice;
        }
        else {
            System.out.printf("音量数在1-100请重新定义");
        }
    }
//    频道开关
    public void open(){System.out.println("执行操作开机");this.power = true;}
    public void close(){System.out.println("执行操作关机");this.power = false;}
//    切换频道
    public void channeladd(){
//        频道逐加
        if (this.channel<200){
            this.channel+=1;
            System.out.println("执行操作频道加1");
        }
        else {
//            大于一百仍想加频道时认为想要回到频道1
            this.channel = 1;
            System.out.println("当前频道数已达最大，已为您跳至频道1");
        }
    }
    public void channeladd(int x){
//        频道跳加，输入参数为想要增加的频道数
        if((this.channel+x)<200){
            this.channel+=x;
            System.out.printf("执行操作频道跳加%d\n",x);
        }
        else {
//            超出200的部分回到1后继续增加
            int y = this.channel+x-200;
            this .channel = y;
            System.out.printf("想要跳跃的频道超出范围，已为您回到频道1后再继续跳跃%d\n",y);
        }
    }
    public void channelsub(){
//        频道逐减
        if (this.channel>0){
            this.channel-=1;
            System.out.println("执行操作频道减1");
        }
        else {
//            小于0仍想减频道时认为想要回到频道200
            this.channel = 200;
            System.out.println("当前频道数已达最小，已为您跳至频道200");
        }
    }
    public void channelsub(int x){
//        频道跳减，输入参数为想要减少的频道数
        if((this.channel-x)>0){
            this.channel-=x;
            System.out.printf("执行操作频道减%d\n",x);
        }
        else {
//            超出200的部分回到1后继续增加
            int y = x - this.channel;
            this .channel = 200-y;
            System.out.printf("想要跳跃的频道超出范围，已为您回到频道200后再继续跳跃%d\n",y);
        }
    }
//    调节音量
    public void sound(int x){
        this.voice = x;
        System.out.printf("音量已调整至%d\n",this.voice);
    }
//    展示电视机状态
    public void show(){
        System.out.printf("电源开关：%b\n",this.power);
        System.out.printf("频道数：%d\n",this.channel);
        System.out.printf("音量大小：%d\n",this.voice);
    }

}


class Main3 {
    public static void main(String[] args) {
        TV tv1 = new TV(true,55,77);
        System.out.println("TV1状态:");
        tv1.show();
//        开机
        tv1.open();
        tv1.show();
//        关机
        tv1.close();
        tv1.show();
//        切换频道
//        加
        tv1.channeladd();
        tv1.show();
        tv1.channeladd(44);
        tv1.show();
        tv1.channeladd(200);
        tv1.show();
//        减
        tv1.channelsub();
        tv1.show();
        tv1.channelsub(44);
        tv1.show();
        tv1.channelsub(200);
        tv1.show();
//        调节音量
        tv1.sound(99);
        tv1.show();
    }
}
