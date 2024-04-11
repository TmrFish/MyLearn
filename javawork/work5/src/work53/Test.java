package work53;
import java.util.Scanner;
import static work53.StudentSystem.class1;

public class Test {
    public static void main(String[] args) {
        Student[] classadd = new Student[4];
        Student s1 = new Student("21252503144","谭瑞","大数据技术","广东财经大学");
        Student s2 = new Student("21252503145","李瑞","大数据技术","广东财经大学");
        Student s3 = new Student("21252503146","王瑞","大数据技术","广东财经大学");
        Student s4 = new Student("21252503147","康瑞","大数据技术","广东财经大学");
        //添加新同学测试用的学生5
        Student s5 = new Student("21252503148","张瑞","大数据技术","广东财经大学");
        classadd[0] = s1;
        classadd[1] = s2;
        classadd[2] = s3;
        classadd[3] = s4;
        StudentSystem students = new StudentSystem(classadd);
        Scanner scanner = new Scanner(System.in);
        T:
        while (true){
            System.out.println("------教务管理系统-----");
            System.out.println("输入你的选择");
            System.out.println("1.输出已录入学生名字");
            System.out.println("2.查看指定学生信息");
            System.out.println("3.加入新同学");
            System.out.println("4.退出系统");
            switch (scanner.nextInt()){
                case 1:students.tellme();break;
                case 2:
                    scanner.nextLine();
                    System.out.println("请输入学生学号");

                    String id = scanner.nextLine();
                    students.StuInf(id);
                    break ;
                case 3:
                    System.out.println("执行操作加入新同学");
                    students.AddStu(s5);
                    System.out.printf("新加入的同学的名字叫%s",class1[4].getName());
                    break ;
                case 4:break T;
            }
        }
    }
}
