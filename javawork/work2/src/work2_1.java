import java.util.Scanner;
import java.util.Random;
public class work2_1 {
    public static void main(String[] args) {
        while (true){
            String playerin;
            int playerout = 0;
            int computer ;
            int out = 0;
            Scanner sc = new Scanner(System.in);
            System.out.println("��ӭ������ȭ��Ϸ");
            System.out.println("�����ȭ��������ʯͷ������:");
            playerin = sc.nextLine();
            if (playerin.equals("ʯͷ"))
                playerout = 0;
            else if (playerin.equals("����"))
                playerout = 1;
            else if (playerin.equals("��"))
                playerout = 2;
            Random r = new Random();
            computer = r.nextInt(3);
            if (computer == 0)
            {
                System.out.println("���Գ���ʯͷ");
                if (playerout == 0)
                    out = 2;
                else if(playerout == 1)
                    out = 0;
                else if (playerout == 2)
                    out = 1;
            }
            else if (computer == 1)
            {
                System.out.println("���Գ��˼���");
                if (playerout == 0)
                    out = 1;
                else if(playerout == 1)
                    out = 2;
                else if (playerout == 2)
                    out = 0;
            }
            else if (computer == 2)
            {
                System.out.println("���Գ��˲�");
                if (playerout == 0)
                    out = 0;
                else if(playerout == 1)
                    out = 1;
                else if (playerout == 2)
                    out = 2;
            }

            if (out == 0)
                System.out.println("������");
            else if(out == 1)
                System.out.println("��Ӯ��");
            else if(out == 2)
                System.out.println("ƽ��");





            System.out.println("��Ϸ�ѽ����Ƿ����¿�ʼ������1Ϊ����������0Ϊ����");
            int a ;
            a =sc.nextInt();
            if (a == 1)
                continue;
            else
                break;
        }
    }


}

