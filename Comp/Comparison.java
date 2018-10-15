import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*; 
import java.util.regex.*;//����
public class Comparison extends JFrame implements ActionListener{
	private JButton compar;
	private JTextField path1, path2;
	public Comparison() {
		super("�ļ��Ƚ�;��Ҫ�Ƚϵ��ļ�����D�̸�Ŀ¼��");
	}
	public static void main(String[] args) {
		Comparison com = new Comparison();
		com.f();
	}
	
	
	void f() {
		
		setSize(350, 500);
		setLocation(300, 240);
		setLayout(new FlowLayout());
		
		add(new Label("                     �뽫��Ҫ�Ƚϵ��ļ�������D�̸�Ŀ¼��                          "));
		

		
		add(new Label("�ļ�1�ļ�����"));
		path1 = new JTextField(25);
		add(path1);
		
		add(new Label("�ļ�2�ļ�����"));
		path2 = new JTextField(25);
		add(path2);
		
		compar = new JButton("�Ƚ�");
		add(compar);
		
		setVisible(true);
		
		
		//���ü���
		compar.addActionListener(this);
	}
	
	//����������Ķ���
	public void actionPerformed(ActionEvent e) {
		//����ȽϺ�
		if(e.getActionCommand().equals("�Ƚ�")) {
			comparIng();//�Ƚ�
		}
	}
	
	public void comparIng() {
		String s1, s2;
		boolean flag;
		File file=new File("D:\\ComparResult");
		if(!file.exists()){//����ļ��в�����
			file.mkdir();//�����ļ���
		}
		//�Ա��ļ�
		File f1 = new File("/D:/"+path1.getText());
		File f2 = new File("/D:/"+path2.getText());
		
//		File f1 = new File("/G:/one.txt");
//		File f2 = new File("/G:/two.txt");
		//����ļ�
		File find = new File("/D:/ComparResult/find.txt");
		File noFind = new File("/D:/ComparResult/noFind.txt");
		try {
			FileReader in1 = new FileReader(f1);
			
			FileWriter outFind = new FileWriter(find);
			FileWriter outNoFind = new FileWriter(noFind);
			
			BufferedReader bIn1 = new BufferedReader(in1);
			
			BufferedWriter bOutFind = new BufferedWriter(outFind);
			BufferedWriter bOutNoFind = new BufferedWriter(outNoFind);
			
			while((s1 = bIn1.readLine()) != null) {//��ȡһ�У�����ֵ���ַ���s1
				if(s1.equals(""))
					continue;
				FileReader in2 = new FileReader(f2);
				BufferedReader bIn2 = new BufferedReader(in2);
				flag = false;//�Ƿ��ҵ�
				while((s2 = bIn2.readLine()) != null) {
					if(s1.equals(s2)) {//������ļ�f2���ҵ��ַ���s2���ļ�f1�е��ַ���s1��ȣ���s1д���ļ���find.txt��
						flag = true;
						break;
					}
				}
				if(flag) {
					bOutFind.write(s1, 0, s1.length());//��s1�д�0��s.length()�������ַ�д��bOutFind
					bOutFind.newLine();//��ӷָ���
				} else {
					bOutNoFind.write(s1, 0, s1.length());
					bOutNoFind.newLine();
				}
				bIn2.close();
			}
			//�ر��ļ�
			bIn1.close();
			bOutFind.close();
			bOutNoFind.close();
			JOptionPane.showMessageDialog(null, "����ѵ���/D:/ComparResult", "���⡾�ȽϽ�����", JOptionPane.CLOSED_OPTION);
		} catch(Exception e) {
			System.out.println(e.getMessage());
		}
	}
}