package work51;

public class Test {
    public static void main(String[] args) {
        //���Գ�����
        Rectangle R1 = new Rectangle(4,6);
        //����������
        Rectangle R2 = new Rectangle(5);
        System.out.printf("R1������(%.1f,%.1f)���ܳ�:%.1f\n",R1.getLong(),R1.getWide(),R1.chang());
        System.out.printf("R1������(%.1f,%.1f)�����:%.1f\n",R1.getLong(),R1.getWide(),R1.mianji());
        System.out.printf("R2������(%.1f,%.1f)���ܳ�:%.1f\n",R2.getLong(),R2.getWide(),R2.chang());
        System.out.printf("R2������(%.1f,%.1f)�����:%.1f\n",R2.getLong(),R2.getWide(),R2.mianji());
    }
}
