package work6;
import java.util.Scanner;
import java.util.Random;
interface Redpacket{
    //�����
    void Give(double gold,int copies);
    //�պ��
    double Get(double gold,int copies);
}
class Group{
    //����
    String Name;
    //���
    double Balance;

    public Group(String name, double balance) {
        Name = name;
        Balance = balance;
    }
    //�㱨�����������ͨ�÷���
    public void tellbalance(){
        System.out.println("����:"+Name+"\n�ҵ������:"+Balance);
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
        //���������������ȡ�����С���㷵��
        if (copies>0){
            //�����������1ֱ�ӽ�ʣ������ȡ
            if (copies == 1){
                //��ȷ��С�������λ
                String randomDouble1 = String.format("%.2f",gold);
                //ת����double��
                double Redpag = Double.parseDouble(randomDouble1);
                System.out.println(this.Name+"�����"+Redpag+"Ԫ���");
                this.Balance = this.Balance + Redpag;
                return 0;
            }
            //�������������ȡ
            else {
                Random random = new Random();
                //����һ�������double�ͣ���Χ��0.01��ʣ������ֵ������
                double randomDouble = random.nextDouble() * (((gold/copies)*2)- 0.01) + 0.01;
                //��ȷ��С�����2λ
                String randomDouble1 = String.format("%.2f",randomDouble);
                //ת����double��
                double Redpag = Double.parseDouble(randomDouble1);
                System.out.println(this.Name+"�����"+randomDouble1+"Ԫ���");
                //�����Ա���
                this.Balance = this.Balance + Redpag;
                //������ȡ��ĺ�����
                return gold-Redpag;
            }
        }
        //���򷵻أ�����ʾ����Ϊ0
        else {
            System.out.println("����Ѿ�������");
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
        //������ĺ�����С��Ⱥ�������ɹ����ź��
        if(gold<this.Balance){
            this.Balance = this.Balance - gold;
            System.out.println("�ѿ۳����ź��");
            this.tellbalance();
        }
        //������ʾ����
        else {
            System.out.println("Ⱥ������������ô����");
        }
    }

    @Override
    public double Get(double gold, int copies) {
        return gold;
    }
}


public class Work6_3Test {
    public static void main(String[] args) {
        //����һ��Ⱥ����ʼ��1000���
        master M1 = new master("Ⱥ��",1000);
        //�㱨һ��Ⱥ����ʼ״̬
        M1.tellbalance();
        System.out.println("**********����Ⱥ����ʼ�����**********\n�������ܽ�");
        Scanner scanner = new Scanner(System.in);
        //���뷢���ĺ��
        double gold = scanner.nextDouble();
        System.out.println("���������:");
        //���뷢���ٷݺ��
        int copies = scanner.nextInt();
        M1.Give(gold,copies);
        System.out.println("**********�����ɳ�Ա��ȡ���**********");
        //�����ĸ���Ա�����뵽һ�������з����������
        member m1 = new member("��Ա1",0);
        member m2 = new member("��Ա2",0);
        member m3 = new member("��Ա3",0);
        member m4 = new member("��Ա4",0);
        member[] members = new member[4];
        members[0] = m1;
        members[1] = m2;
        members[2] = m3;
        members[3] = m4;
        //ѭ�������еĳ�Ա��������
        for(int i =0;i<members.length;i++){
            gold = members[i].Get(gold,copies);
            copies --;
            System.out.printf("ʣ����%.2f",gold);
            System.out.printf("\nʣ�����%d",copies);
        }
        //����֮��㱨һ�¸������
        for(int i =0;i<members.length;i++){
            members[i].tellbalance();
        }
    }
}
