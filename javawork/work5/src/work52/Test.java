package work52;

public class Test {
    public static void main(String[] args) {
        Myself me = new Myself("̷����",20,"��","�����ݼ���");
        //public��������������
        //public��Χ��ͬһ���࣬ͬһ���������࣬ȫ��
        me.introduce();
        //default����ͬһ�����п�����
        //default��Χ��ͬһ���࣬ͬһ����
        me.InDuAge();
        //private��������ͬһ�����޷�����
        //private��Χ��ͬһ����
//        me.InDuName();'InDuName()' �� 'work52.Myself' �о��� private ����Ȩ��
    }
}
