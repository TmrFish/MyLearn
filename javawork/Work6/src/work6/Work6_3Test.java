package work6;
import java.util.Scanner;
import java.util.Random;
interface Redpacket{
    //发红包
    void Give(double gold,int copies);
    //收红包
    double Get(double gold,int copies);
}
class Group{
    //名字
    String Name;
    //余额
    double Balance;

    public Group(String name, double balance) {
        Name = name;
        Balance = balance;
    }
    //汇报余额所有子类通用方法
    public void tellbalance(){
        System.out.println("我是:"+Name+"\n我的余额是:"+Balance);
    }
}
class member extends Group implements Redpacket{
    public member(String name, double balance) {
        super(name, balance);
    }

    @Override
    public void Give(double gold, int copies) {

    }

    @Override
    public double Get(double gold, int copies) {
        //红包份数大于零领取红包，小于零返回
        if (copies>0){
            //红包份数等于1直接将剩余金额领取
            if (copies == 1){
                //精确到小数点后两位
                String randomDouble1 = String.format("%.2f",gold);
                //转换回double型
                double Redpag = Double.parseDouble(randomDouble1);
                System.out.println(this.Name+"获得了"+Redpag+"元红包");
                this.Balance = this.Balance + Redpag;
                return 0;
            }
            //否则用随机数领取
            else {
                Random random = new Random();
                //生成一个随机的double型，范围是0.01到剩余余额均值的两倍
                double randomDouble = random.nextDouble() * (((gold/copies)*2)- 0.01) + 0.01;
                //精确到小数点后2位
                String randomDouble1 = String.format("%.2f",randomDouble);
                //转换回double型
                double Redpag = Double.parseDouble(randomDouble1);
                System.out.println(this.Name+"获得了"+randomDouble1+"元红包");
                //传入成员余额
                this.Balance = this.Balance + Redpag;
                //返回领取后的红包余额
                return gold-Redpag;
            }
        }
        //否则返回，并提示份数为0
        else {
            System.out.println("红包已经抢完啦");
            return gold;
        }
    }
}
class master extends Group implements Redpacket{
    public master(String name, double balance) {
        super(name, balance);
    }


    @Override
    public void Give(double gold,int copies) {
        //如果发的红包金额小于群主余额则成功发放红包
        if(gold<this.Balance){
            this.Balance = this.Balance - gold;
            System.out.println("已扣除余额发放红包");
            this.tellbalance();
        }
        //否则提示余额不足
        else {
            System.out.println("群主的余额不够发真么多红包");
        }
    }

    @Override
    public double Get(double gold, int copies) {
        return gold;
    }
}


public class Work6_3Test {
    public static void main(String[] args) {
        //创建一个群主初始有1000余额
        master M1 = new master("群主",1000);
        //汇报一下群主初始状态
        M1.tellbalance();
        System.out.println("**********下面群主开始发红包**********\n请输入总金额：");
        Scanner scanner = new Scanner(System.in);
        //输入发多大的红包
        double gold = scanner.nextDouble();
        System.out.println("请输入份数:");
        //输入发多少份红包
        int copies = scanner.nextInt();
        M1.Give(gold,copies);
        System.out.println("**********下面由成员领取红包**********");
        //创建四个成员并加入到一个数组中方便后续操作
        member m1 = new member("成员1",0);
        member m2 = new member("成员2",0);
        member m3 = new member("成员3",0);
        member m4 = new member("成员4",0);
        member[] members = new member[4];
        members[0] = m1;
        members[1] = m2;
        members[2] = m3;
        members[3] = m4;
        //循环让所有的成员挨个领红包
        for(int i =0;i<members.length;i++){
            gold = members[i].Get(gold,copies);
            copies --;
            System.out.printf("剩余红包%.2f",gold);
            System.out.printf("\n剩余个数%d",copies);
        }
        //领完之后汇报一下各自余额
        for(int i =0;i<members.length;i++){
            members[i].tellbalance();
        }
    }
}
