package work53;

import java.util.Arrays;

public class StudentSystem {
    //��Ա����һ���༶����
    static Student[] class1 ;
    //���췽������һ��student����
    public StudentSystem(Student[] class1) {
        this.class1 = class1;
    }
    //�޲ι���
    public StudentSystem() {
    }
    //��ӡ��¼��ѧ������������
    public void tellme(){
        System.out.printf("��¼���ѧ����%d��\n",class1.length);
        for(int i =0;i<class1.length;i++){
            System.out.printf("ѧ��Ϊ%sѧ��������%s\n",class1[i].getId(),class1[i].getName());
        }
    }
    //��ӡָ��ѧ����ϸ��Ϣ
    public void StuInf(String x){
        for(int i = 0 ;i<class1.length;i++)
        {
            if (class1[i].getId().equals(x)){
                System.out.printf("ѧ����Ϣ��\nѧ��Ϊ:%s,����Ϊ:%s,רҵΪ:%s,ѧУΪ:%s\n",class1[i].getId(),class1[i].getName(),class1[i].getMajor(),class1[i].getSchool());
            }
        }
    }
    //�����µ�ͬѧ
    public void AddStu(Student s){
        class1 = Arrays.copyOf(class1, 5);
        class1[class1.length-1] = s;

    }

}
