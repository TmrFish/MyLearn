package work53;
import java.util.Scanner;
import static work53.StudentSystem.class1;

public class Test {
    public static void main(String[] args) {
        Student[] classadd = new Student[4];
        Student s1 = new Student("21252503144","̷��","�����ݼ���","�㶫�ƾ���ѧ");
        Student s2 = new Student("21252503145","����","�����ݼ���","�㶫�ƾ���ѧ");
        Student s3 = new Student("21252503146","����","�����ݼ���","�㶫�ƾ���ѧ");
        Student s4 = new Student("21252503147","����","�����ݼ���","�㶫�ƾ���ѧ");
        //�����ͬѧ�����õ�ѧ��5
        Student s5 = new Student("21252503148","����","�����ݼ���","�㶫�ƾ���ѧ");
        classadd[0] = s1;
        classadd[1] = s2;
        classadd[2] = s3;
        classadd[3] = s4;
        StudentSystem students = new StudentSystem(classadd);
        Scanner scanner = new Scanner(System.in);
        T:
        while (true){
            System.out.println("------�������ϵͳ-----");
            System.out.println("�������ѡ��");
            System.out.println("1.�����¼��ѧ������");
            System.out.println("2.�鿴ָ��ѧ����Ϣ");
            System.out.println("3.������ͬѧ");
            System.out.println("4.�˳�ϵͳ");
            switch (scanner.nextInt()){
                case 1:students.tellme();break;
                case 2:
                    scanner.nextLine();
                    System.out.println("������ѧ��ѧ��");

                    String id = scanner.nextLine();
                    students.StuInf(id);
                    break ;
                case 3:
                    System.out.println("ִ�в���������ͬѧ");
                    students.AddStu(s5);
                    System.out.printf("�¼����ͬѧ�����ֽ�%s",class1[4].getName());
                    break ;
                case 4:break T;
            }
        }
    }
}
