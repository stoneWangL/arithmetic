import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*; 
import java.util.regex.*;//正则
public class Comparison extends JFrame implements ActionListener{
	private JButton compar;
	private JTextField path1, path2;
	public Comparison() {
		super("文件比较;需要比较的文件放在D盘根目录下");
	}
	public static void main(String[] args) {
		Comparison com = new Comparison();
		com.f();
	}
	
	
	void f() {
		
		setSize(350, 500);
		setLocation(300, 240);
		setLayout(new FlowLayout());
		
		add(new Label("                     请将需要比较的文件放置于D盘根目录中                          "));
		

		
		add(new Label("文件1文件名："));
		path1 = new JTextField(25);
		add(path1);
		
		add(new Label("文件2文件名："));
		path2 = new JTextField(25);
		add(path2);
		
		compar = new JButton("比较");
		add(compar);
		
		setVisible(true);
		
		
		//设置监听
		compar.addActionListener(this);
	}
	
	//监听触发后的动作
	public void actionPerformed(ActionEvent e) {
		//点击比较后
		if(e.getActionCommand().equals("比较")) {
			comparIng();//比较
		}
	}
	
	public void comparIng() {
		String s1, s2;
		boolean flag;
		File file=new File("D:\\ComparResult");
		if(!file.exists()){//如果文件夹不存在
			file.mkdir();//创建文件夹
		}
		//对比文件
		File f1 = new File("/D:/"+path1.getText());
		File f2 = new File("/D:/"+path2.getText());
		
//		File f1 = new File("/G:/one.txt");
//		File f2 = new File("/G:/two.txt");
		//结果文件
		File find = new File("/D:/ComparResult/find.txt");
		File noFind = new File("/D:/ComparResult/noFind.txt");
		try {
			FileReader in1 = new FileReader(f1);
			
			FileWriter outFind = new FileWriter(find);
			FileWriter outNoFind = new FileWriter(noFind);
			
			BufferedReader bIn1 = new BufferedReader(in1);
			
			BufferedWriter bOutFind = new BufferedWriter(outFind);
			BufferedWriter bOutNoFind = new BufferedWriter(outNoFind);
			
			while((s1 = bIn1.readLine()) != null) {//读取一行，并赋值给字符串s1
				if(s1.equals(""))
					continue;
				FileReader in2 = new FileReader(f2);
				BufferedReader bIn2 = new BufferedReader(in2);
				flag = false;//是否找到
				while((s2 = bIn2.readLine()) != null) {
					if(s1.equals(s2)) {//如果在文件f2中找到字符串s2和文件f1中的字符串s1相等，将s1写入文件“find.txt”
						flag = true;
						break;
					}
				}
				if(flag) {
					bOutFind.write(s1, 0, s1.length());//将s1中从0至s.length()的所有字符写入bOutFind
					bOutFind.newLine();//添加分隔符
				} else {
					bOutNoFind.write(s1, 0, s1.length());
					bOutNoFind.newLine();
				}
				bIn2.close();
			}
			//关闭文件
			bIn1.close();
			bOutFind.close();
			bOutNoFind.close();
			JOptionPane.showMessageDialog(null, "结果已导入/D:/ComparResult", "标题【比较结束】", JOptionPane.CLOSED_OPTION);
		} catch(Exception e) {
			System.out.println(e.getMessage());
		}
	}
}