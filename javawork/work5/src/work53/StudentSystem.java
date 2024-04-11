package work53;

import java.util.Arrays;

public class StudentSystem {
    //成员变量一个班级数组
    static Student[] class1 ;
    //构造方法输入一个student数组
    public StudentSystem(Student[] class1) {
        this.class1 = class1;
    }
    //无参构造
    public StudentSystem() {
    }
    //打印已录入学生数量和名字
    public void tellme(){
        System.out.printf("已录入的学生有%d个\n",class1.length);
        for(int i =0;i<class1.length;i++){
            System.out.printf("学号为%s学生名字是%s\n",class1[i].getId(),class1[i].getName());
        }
    }
    //打印指定学生详细信息
    public void StuInf(String x){
        for(int i = 0 ;i<class1.length;i++)
        {
            if (class1[i].getId().equals(x)){
                System.out.printf("学生信息：\n学号为:%s,姓名为:%s,专业为:%s,学校为:%s\n",class1[i].getId(),class1[i].getName(),class1[i].getMajor(),class1[i].getSchool());
            }
        }
    }
    //加入新的同学
    public void AddStu(Student s){
        class1 = Arrays.copyOf(class1, 5);
        class1[class1.length-1] = s;

    }

}
