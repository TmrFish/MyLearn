package work52;

public class Myself {
    //��Ա����
     public String name;//����
     private int age;//����
     String sex;//�Ա�
     protected String major;//רҵ
    //���췽��
    //�޲�
    public  Myself(){

    }
    //�в�
    public Myself(String name, int age, String sex, String major) {
        this.name = name;
        this.age = age;
        this.sex = sex;
        this.major = major;
    }
    //���ҽ���
    public void introduce(){
        System.out.printf("�ҽ�%s,����%d��,�ҵ��Ա���%s���ҵ�רҵ��%s��\n",this.name,this.age,this.sex,this.major);
    }
    private void InDuName(){
        System.out.println(this.name);
    }
    void InDuAge(){
        System.out.println(this.age);
    }


}
