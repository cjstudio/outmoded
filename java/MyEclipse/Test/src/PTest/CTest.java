package PTest;
import java.awt.BorderLayout;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;

public class CTest implements ITest {

	public CTest() {
		// TODO Auto-generated constructor stub
	}

	@Override
	public void test() {
		// TODO Auto-generated method stub
	
	/*
	 * ������������ JFrame��JDialog��JApplet�м����� JPanel
	 */
	/*
	 * ���ֹ����� ��ʽ���� FlowLayout �������£��������� JPanelĬ�ϲ��� �߽粼�� BorderLayout �����ϱ���
	 * JFrameĬ�ϲ��� ���񲼾� GridLayout �ȷ� ��Ƭ���� ���������
	 */
	/*
	 * ��� JButton
	 */
		// ���ɽ���(������container)
		JFrame mainFrame = new JFrame();
		// ���ý��沼��(���ֹ�������layoutManager)
		// mainFrame.setLayout(new FlowLayout());
		mainFrame.setLayout(new GridLayout(3, 2));
		// ���ɰ�ť(�����component)
		JButton b1 = new JButton();
		// ���ð�ť����
		b1.setText("��");
		// ���ɰ�ť(�����component)
		JButton b2 = new JButton();
		// ���ð�ť����
		b2.setText("��");
		JButton b3 = new JButton();
		// ���ð�ť����
		b3.setText("��");
		// ���ɰ�ť(�����component)
		JButton b4 = new JButton();
		// ���ð�ť����
		b4.setText("��");
		// ���ɰ�ť(�����component)
		JButton b5 = new JButton();
		// ���ð�ť����
		b5.setText("��");
		// �ڽ�������Ӱ�ť
		mainFrame.add(b1, BorderLayout.EAST);
		mainFrame.add(b2, BorderLayout.WEST);
		mainFrame.add(b3, BorderLayout.SOUTH);
		mainFrame.add(b4, BorderLayout.NORTH);
		mainFrame.add(b5, BorderLayout.CENTER);
		// ���ô�С
		mainFrame.setSize(400, 400);
		// ����λ��
		mainFrame.setLocation(312, 184);
		// ����Ĭ�Ϲرշ�ʽexit dispose hide donothing
		mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		// ���ÿ���
		mainFrame.setVisible(true);
		b1.doClick();
	}

}
