#include<iostream>
#include<fstream>
#include<malloc.h>
#include<string>

using namespace std;
struct keyword {
	string kword;
};//���ڴ洢�ؼ���

struct contrat {
	string SYM;
	string ID;
	int NUM;
}common;


keyword key_w[14];
fstream file;//���ڴ��ļ�
int x_site=0, y_site=1;//���ڼ�¼�����λ��,��ʼ��λ0
//��ʼ���ؼ���
void Initial_Key_w()
{
	key_w[0].kword = "program";
	key_w[1].kword = "begin";
	key_w[2].kword = "end";
	key_w[3].kword = "if";
	key_w[4].kword = "then";
	key_w[5].kword = "while";
	key_w[6].kword = "do";
	key_w[7].kword = "const";
	key_w[8].kword = "var";
	key_w[9].kword = "call";
	key_w[10].kword = "procedure";
	key_w[11].kword = "odd";
	key_w[12].kword = "read";
	key_w[13].kword = "write";
}
//������
void error_deal(int num)
{
	int select = num;
	switch (select)
	{
	case 1:
		cout << y_site << "��" << x_site << " ��" << "  �Ƿ��ַ�" << endl;
		break;
	case 2:
		cout << y_site << "��" << x_site << "��" << "  �Ƿ�����" << endl;
		break;
	case 3:
		cout << y_site << "��" << x_site << "��" << "  ȱ��'='" << endl;
		break;
	case 4:
		cout << y_site << "��" << x_site << "��" << "  ȱ��program" << endl;
		break;
	case 5:
		cout << y_site << "��" << x_site << "��" << "  ȱ�ٳ�����" << endl;
		break;
	case 6:
		cout << y_site << "��" << x_site << "��" << "  ȱ��';'" << endl;
		break;
	case 7:
		cout << y_site << "��" << x_site << "��" << "  " << endl;
		break;
	case 8:
		cout << y_site << "��" << x_site << "��" << "  ȱ�ٳ�����" << endl;
		break;
	case 9:
		cout << y_site << "��" << x_site << "��" << "  ȱ��:=" << endl;
		break;
	case 10:
		cout << y_site << "��" << x_site << "��" << "  ȱ����" << endl;
		break;
	case 11:
		cout << y_site << "��" << x_site << "��" << "  ȱ��','" << endl;
		break;
	case 12:
		cout << y_site << "��" << x_site << "��" << "  ȱ�ٱ�����" << endl;
		break;
	case 13:
		cout << y_site << "��" << x_site << "��" << "  ȱ�ٹ�����" << endl;
		break;
	case 14:
		cout << y_site << "��" << x_site << "��" << "  ȱ��������" << endl;
		break;
	case 15:
		cout << y_site << "��" << x_site << "��" << "  ȱ��������" << endl;
		break;
	case 16:
		cout << y_site << "��" << x_site << "��" << "  ȱ��begin" << endl;
		break;
	case 17:
		cout << y_site << "��" << x_site << "��" << "  ȱ������" << endl;
		break;
	case 18:
		cout << y_site << "��" << x_site << "��" << "  ȱ��then" << endl;
		break;
	case 19:
		cout << y_site << "��" << x_site << "��" << "  ȱ��do" << endl;
		break;
	case 20:
		cout << y_site << "��" << x_site << "��" << "  ȱ��end" << endl;
		break;
	case 21:
		cout << y_site << "��" << x_site << "��" << "  ȱ�ٲ�������� " << endl;
		break;
	case 22:cout << y_site << "��" << x_site << "��" << "  ���Ϸ��ַ�" << endl;
		break;
	case 23:cout << y_site-1 << "��" << x_site << "��" << "  �����';'" << endl;
		break;
	case 24:
		cout << y_site - 1 << "��" << x_site << "��" << "  �����ظ�����" << endl;
		break;
	case 25:
		cout << y_site - 1 << "��" << x_site << "��" << "  ����δ����" << endl;
		break;
	case 26:
		cout << y_site - 1 << "��" << x_site << "��" << "  ��������" << endl;
		break;
	case 27:
		cout << y_site - 1 << "��" << x_site << "��" << "  ��������" << endl;
		break;
	defeat:break;
	}
}
//###########################�ʷ�����#############################//

char ch;//���ڱ�������ķ���
string str;//���ڱ���������
//�ж��ַ��Ƿ�Ϊ�Ϸ��ַ�
bool Judge()
{
	if (ch == '\t')
		return true;
	if (ch == ',')
		return true;
	if (ch == '=')
		return true;
	if (ch == '>')
		return true;
	if (ch == '<')
		return true;
	if (ch == '+')
		return true;
	if (ch == '-')
		return true;
	if (ch == '*')
		return true;
	if (ch == '/')
		return true;
	if (ch == ':')
		return true;
	if (ch == '{')
		return true;
	if (ch == '}')
		return true;
	if (ch == '[')
		return true;
	if (ch == ']')
		return true;
	if (ch == ';')
		return true;
	if (ch == ' ')
		return true;
	if (ch == '(')
		return true;
	if (ch == ')')
		return true;
	if (ch == '\n')
	{
		return true;
	}
	if (ch == ',')
		return true;
	if ('0' <= ch && ch <= '9')
		return true;
	if ('A' <= ch && ch <= 'Z' || 'a' <= ch && ch <= 'z')
		return true;
	error_deal(1);
	return false;
}
//������һ�ַ�,�������ַ�λ��
void GetChar()
{
	ch = file.get();
	x_site++;
	while(ch == '\t')
	{
		ch = file.get();
		x_site += 4;
	}
	if (file.peek() == EOF)
	{
		ch = ' ';
		return;
	}
	if (!Judge())
	{
		ch = file.get();
		x_site++;
	}
}
//ƴ���ַ���
void Concat()
{
	str += ch;
}
//���ch���ַ��Ƿ�Ϊ�ո��س�,����������GetChar����ֱ��ch��Ϊ��
void GetBC()
{
	if (file.peek() == EOF)
		return;
	while (ch == ' ' || ch == '\n')
	{
		if (ch == '\n')
		{
			x_site = 0;
			y_site++;
		}
		GetChar();
	}
}
//�ж��Ƿ�Ϊ��ĸ
bool Is_Letter()
{
	if ('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z')
	{
		return true;
	}
	return false;
}
//�ж��Ƿ�Ϊ����
bool Is_Digit()
{
	if ('0' <= ch && ch <= '9')
	{
		return true;
	}
	return false;
}
//��str�е��ַ������ұ����ֱ�,�����Ǳ������򷵻�1,���򷵻�0
bool Reserve()
{
	int i(0);
	for (i = 0; i < 14; i++)
	{
		if (key_w[i].kword==str)
		{
			return true;
		}
	}
	return false;
}
//������ָ����ǰ�ص�һ���ַ�λ��,����ch��Ϊ���ַ�
void Retract()
{
	file.seekg(-1, ios::cur);
	ch = ' ';
}
//Ѱ����һ���ո���߻س�
void Find_s()
{
	while (ch != ' ' && ch != '\n')
	{
		GetChar();
	}
}
//���ַ���ת��Ϊint�ͱ���,�����ؽ��
int calcu_integer()
{
	int result(0);
	result = str[0]-'0';
	for (int i = 2; i <= str.length(); i++)
	{
		result *= 10;
		result += str[i-1]-'0';
	}
	return result;
}
void GETSYM()
{
	GetChar();
	GetBC();
	//����ĸ��ͷident
	if (Is_Letter())
	{
		while (Is_Letter() || Is_Digit())//����Ȼ����ĸ,����ѭ��
		{
			Concat();
			GetChar();
		}
		if (file.eof())//�����ַ�������ļ�����
		{
			if (Reserve())
			{
				common.SYM = str + "sym";
				common.ID = str;
				common.NUM = -1;//�������
			}
			else
			{
				common.SYM = "ident";
				common.ID = str;
				common.NUM = -1;//�������
			}
			Retract();
			str = "";
			return;
		}
		if (Judge())
		{
			if (Reserve())
			{
				common.SYM = str + "sym";
				common.ID = str;
				common.NUM = -1;//�������
			}
			else
			{
				common.SYM = "ident";
				common.ID = str;
				common.NUM = -1;//�������
			}
			Retract();
			str = "";
			return;
		}
		str = "";
		return;
	}
	//�����ֿ�ͷnumber
	if (Is_Digit())
	{
		while (Is_Digit())
		{
			Concat();
			GetChar();
		}
		if (Is_Letter())
		{
			error_deal(2);
			Find_s();
			return;
		}
		if (Judge())
		{
			common.SYM = "number";
			common.NUM = calcu_integer();
			common.ID = "";
			Retract();
			str = "";
			return;
		}
		str = "";
		return;
	}
	//���������lop
	if (ch == '=')
	{
		common.SYM = "lop";
		common.ID = "=";
		common.NUM = -1;//�������
		return;
	}
	if (ch == '>')
	{
		Concat();
		GetChar();
		if (ch == '=')
		{
			Concat();
			common.SYM = "lop";
			common.ID = ">=";
			common.NUM = -1;//�������
			str = "";
			return;
		}
		else
		{
			common.SYM = "lop";
			common.ID = ">";
			common.NUM = -1;//�������
			Retract();
			str = "";
			return;
		}
	}
	if (ch == '<')
	{
		Concat();
		GetChar();
		if (ch == '>')
		{
			Concat();
			common.SYM = "lop";
			common.ID = "<>";
			common.NUM = -1;//�������
			str = "";
			return;
		}
		if (ch == '=')
		{
			Concat();
			common.SYM = "lop";
			common.ID = "<=";
			common.NUM = -1;//�������
			str = "";
			return;
		}
		else
		{
			common.SYM = "lop";
			Retract();
			str = "";
			return;
		}
	}
	//���������mop
	if (ch=='*'||ch=='/')
	{
		Concat();
		common.SYM = "mop";
		common.ID = str;
		common.NUM = -1;//�������
		str = "";
		return;
	}
	//��������aop
	if (ch == '+' || ch == '-')
	{
		Concat();
		common.SYM = "aop";
		common.ID = str;
		common.NUM = -1;
		str = "";
		return;
	}
	//become
	if (ch == ':')
	{
		Concat();
		GetChar();
		if (ch == '=')
		{
			Concat();
			common.SYM = "become";
			common.ID = str;
			str = "";
			return;
		}
		else
		{
			error_deal(3);//ȱ��=
			common.SYM = "become";
			common.ID = str+'=';
			Retract();
			str = "";
			return;
		}
	}
	if(ch==',')
	{
		common.SYM = "comma";
		common.ID = ",";
		common.NUM = -1;//�������
		return;
	}
	if (ch == ';')
	{
		common.SYM = "semicolon";
		common.ID = ";";
		common.NUM = -1;//�������
		return;
	}
	if (ch == '(')
	{
		common.SYM = "L_parenthesis";
		common.ID = "(";
		common.NUM = -1;//�������
		return;
	}
	if (ch == ')')
	{
		common.SYM = "R_parenthesis";
		common.ID = ")";
		common.NUM = -1;//�������
		return;
	}
	if (ch == '[')
	{
		common.SYM = "LM_brackets";
		common.ID = "[";
		common.NUM = -1;//�������
		return;
	}
	if (ch == ']')
	{
		common.SYM = "RM_brackets";
		common.ID = "]";
		common.NUM = -1;//�������
		return;
	}
	return;
}
//#######################�ʷ�����############################//
//2019-12-31 ����5:00�������
//#######################�﷨����+�������###################//
//���岿��
enum object {
	constant,
	variable,
	procedure
};
//���ű�ṹ
struct word_table {
	string name;//����
	enum object kind;//����:const,var��procedure
	int val;//��ֵ,��constʹ��
	int level;//������,��const��ʹ��
	int adr;//��Ե�ַ,��const��ʹ��
	int size;//����ĵ�ַ�ռ�,��procedureʹ��
};
struct instruction {
	string f;  /*���������ָ��*/
	int l;			  /*���ò���������Ĳ�β�*/
	int a;			  /*����f�Ĳ�ͬ����ͬ*/
};
struct instruction code[100];
word_table table[100];
int tx(0);//table���±�
int lev(0);//���
int sz(0);//proc���ٵĿռ��С
int cx(0);//Ŀ�����code������±�ָ��


void factor_check();
void term_check();
void exp_check();
void lexp_check();
void statement_check(int tx0,int dx);
void const_check();
void condecl_check(int &dx);
void vardecl_check(int &dx);
void body_check(int tx,int &dx);
void proc_check();
void block_check(int num);
//��������
//����p����
void Gen(string f, int l, int a)
{
	code[cx].f = f;
	code[cx].l = l;
	code[cx].a = a;
	cx++;
}
//���ұ����ڷ��ű��е�λ��
int position()
{
	int i;
	for (i = tx; i > 0; i--)
	{
		if (common.ID == table[i].name)
		{
			if (lev >= table[i].level)
				return i;
			if (table[i].kind == procedure)
				return i;
		}
	}
	return -1;
}
//��¼��ʶ��������,����,���ڲ��,ֵ�ͷ�������λ��
void Enter(object k,int dx=0,int p_num=0)
{
	for (int i = 0; i <= tx; i++)
	{
		if (common.ID == table[tx].name)
		{
			if (k == variable && lev == table[tx].level)
			{
				error_deal(24);//�����ظ�����
				return;
			}
			if (k == procedure && lev == table[tx].level)
			{
				error_deal(25);//�ֳ����ض���
				return;
			}
			if (k == constant)
			{
				error_deal(26);//�����ظ�����
				return;
			}
		}

	}
	tx++;
	table[tx].name = common.ID;
	table[tx].kind = k;
	switch (k)
	{
	case constant:
		break;
		
	case variable:
		table[tx].level = lev;
		table[tx].adr = dx;
		break;
	case procedure:
		table[tx].level = lev;
		table[tx].adr += p_num;
		break;
	}

}
void factor_check()
{
	int i;
	if (common.SYM == "ident")
	{
		i = position();
		if (i == -1)
			error_deal(25);
		else if (table[i].kind == procedure)
			error_deal(25);
		if (table[i].kind == constant)
			Gen("lit", 0, table[i].val);
		else if (table[i].kind == variable)
			Gen("lod", lev - table[i].level, table[i].adr);
		GETSYM();
		return;
	}
	if (common.SYM == "number")
	{
		Gen("lit", 0, common.NUM);
		GETSYM();
		return;
	}
	if (common.SYM == "L_parenthesis")
	{
		GETSYM();
		exp_check();
		if (common.SYM != "R_parenthesis")
			error_deal(15);
		else
			GETSYM();
		return;
	}
	error_deal(17);//ȱ������
}
void term_check()
{
	string mop;
	factor_check();
	while (common.SYM == "mop")
	{
		mop = common.ID;
		GETSYM();
		factor_check();
		if (mop == "*")
			Gen("opr", 0, 4);
		if (mop == "/")
			Gen("opr", 0, 5);
	}
}
void exp_check()
{
	string aop;
	if (common.ID == "+" || common.ID == "-")
	{
		Gen("lit", 0, 0);
		aop = common.ID;
		GETSYM();
	}
	term_check();
	if (aop == "+")
		Gen("opr", 0, 2);
	if (aop == "-")
		Gen("opr", 0, 3);
	while (common.SYM == "aop")
	{
		aop = common.ID;
		GETSYM();
		term_check();
		if (aop == "+")
			Gen("opr", 0, 2);
		if (aop == "-")
			Gen("opr", 0, 3);
	}
}
void lexp_check()
{
	string lop;//��¼����ֵ
	if (common.SYM == "oddsym")
	{
		Gen("opr", 0, 6);
		GETSYM();
		exp_check();
	}
	else
	{
		exp_check();
	if (common.SYM != "lop")
		error_deal(21);//ȱ�ٲ��������
	else
	{
		lop = common.ID;
		GETSYM();
	}
	exp_check();
	if (lop == ">")
		Gen("opr", 0, 12);
	if (lop == ">=")
		Gen("opr", 0, 11);
	if (lop == "<")
		Gen("opr", 0, 10);
	if (lop == "<=")
		Gen("opr", 0, 13);
	if (lop == "<>")
		Gen("opr", 0, 9);
	if (lop == "=")
		Gen("opr", 0, 8);
	//Gen("opr", 0, 14);//ջ��ֵ�������Ļ
	}
}
void statement_check(int tx0=0,int dx=0)
{
	int i(0),num(0);
	int cx0;
	int cx1;
	if (common.SYM == "ident")
	{
		i = position();
		GETSYM();
		if (common.SYM != "become")
			error_deal(9);
		else
			GETSYM();
		exp_check();
		Gen("sto", lev - table[i].level, table[i].adr);
		return;
	}
	//���
	if (common.SYM == "ifsym")
	{
		GETSYM();
		lexp_check();
		if (common.SYM != "thensym")
			error_deal(18);
		else
			GETSYM();
		cx0 = cx;
		Gen("jpc", 0, 0);
		statement_check();
		cx1 = cx;
		Gen("jmp", 0, 0);//����
		code[cx0].a = cx;//
		if (common.SYM == "elsesym")
		{
			GETSYM();
			statement_check();
		}
		code[cx1].a = cx;
		if (common.SYM == "endsym")
			return;
		//GETSYM();
		return;
	}
	//���
	if (common.SYM == "whilesym")
	{
		GETSYM();
		cx0 = cx;
		lexp_check();
		cx1 = cx;
		Gen("jpc", 0, 0);//����������,ת
		if (common.SYM != "dosym")
			error_deal(19);//ȱ��do
		else
			GETSYM();
		statement_check();
		Gen("jmp", 0, cx0);//�������ص������жϴ�
		code[cx1].a = cx;
		return;
	}
	if (common.SYM == "callsym")
	{
		GETSYM();
		if (common.SYM != "ident")
			error_deal(13);//ȱ�ٹ�����
		else
		{
			i = position();//ȡ�ù�������table�±�
			GETSYM();
		}
		if (common.SYM != "L_parenthesis")
			error_deal(14);
		else
			GETSYM();
		while (common.SYM != "R_parenthesis")
		{
			int n(0);
			exp_check();
			Gen("sto", -1, num+3);//����
			num++;
			if(common.SYM=="comma")
				GETSYM();
			n++;
			if (n > 10)
				break;
			if (common.SYM == "endsym")
			{
				error_deal(15);
				break;
			}
		}
		Gen("cal", lev - table[i].level, table[i].adr);//��ת���ֳ���
		//lev++;//���++
		//Gen("jmp", 0, table[i].adr);
		if (num > table[i].adr)
			error_deal(26);
		GETSYM();
		return;
	}
	if (common.SYM == "readsym")
	{
		GETSYM();
		if (common.SYM != "L_parenthesis")
			error_deal(14);
		else
			GETSYM();
		if (common.SYM == "R_parenthesis")
		{
			error_deal(12);
			return;
		}
			
		if (common.SYM != "ident")
			error_deal(12);
		else
		{
			i = position();//ȡ������
			if (i == -1)
				error_deal(25);
			else if (table[i].kind == procedure)
				error_deal(25);
			else
			{
				Gen("opr", 0, 16);//�������ж���������ջ��
				Gen("sto", lev - table[i].level, table[i].adr);//ȡ��ջ��ֵ���賣��
			}
			GETSYM();
		}
		while (common.SYM != "R_parenthesis")
		{
			int n(0);
			if (common.SYM == "comma")
			{
				GETSYM();
				i = position();
				if (table[i].level > lev)
				{
					Gen("opr", 0, 16);//�������ж���������ջ��
					Gen("lod", lev - table[i].level, table[i].adr);
				}
				else
					error_deal(25);
			}
				
			else if (common.SYM == "ident")
			{
				error_deal(11);
				GETSYM();
			}
				
			else if (common.SYM == "endsym"||common.SYM=="semicolon")
			{
				error_deal(15);
				break;
			}
			else
			{
				error_deal(19);//���Ϸ��ַ�
				GETSYM();
			}
			n++;
			if (n > 10)
				break;
		}
		GETSYM();
		return;
	}
	if (common.SYM == "writesym")
	{
		GETSYM();
		if (common.SYM != "L_parenthesis")
			error_deal(14);
		else
			GETSYM();
		if (common.SYM == "R_parenthesis")
		{
			error_deal(12);
			return;
		}
		exp_check();
		Gen("opr", 0, 14);//�������Ļ
		Gen("opr", 0, 15);//�������
		while (common.SYM != "R_parenthesis")
		{
			int n(0);
			if (common.SYM == "comma")
			{
				GETSYM();
				exp_check();
				Gen("opr", 0, 14);//�������Ļ
				Gen("opr", 0, 15);//�������
			}
			else if (common.SYM == "endsym" || common.SYM == "semicolon")
			{
				error_deal(15);
				break;
			}
			else
			{
				error_deal(22);//���Ϸ��ַ�
				GETSYM();
			}
			n++;
			if (n > 10)
				break;
		}
		GETSYM();
		return;
	}
	int zero(0);//
	if (common.SYM == "beginsym")
		body_check(zero,zero);
	if (file.peek() == EOF)
		return;
}
void const_check()
{
	if (common.SYM != "ident")
		error_deal(8);//ȱ�ٳ�����
	else
	{
		Enter(constant);
		GETSYM();
	}
		
	if (common.SYM != "become")
		error_deal(9);//ȱ��:=
	else
		GETSYM();
	if (common.SYM != "number")
		error_deal(10);
	else
	{
		table[tx].val = common.NUM;
		GETSYM();
	}
		
}
void condecl_check(int &dx)
{
	int n(0);//ѭ������
	GETSYM();
	const_check();
	while (common.SYM != "semicolon")
	{
		if (common.SYM == "comma")
		{
			GETSYM();
			const_check();
		}
		if (common.SYM == "ident")
		{
			error_deal(11);//ȱ��comma
			const_check();
		}
		if (common.SYM == "varsym" || common.SYM == "proceduresym" || common.SYM == "beginsym")
		{
			error_deal(6);
			return;
		}
		n++;
		if (n > 20)
			break;
	}
	GETSYM();
}
void vardecl_check(int &dx)
{
	int n(0);
	GETSYM();
	if (common.SYM != "ident")
		error_deal(12);//ȱ�ٱ�����
	else
	{
		dx++;
		Enter(variable,dx);
		GETSYM();
	}
		
	while (common.SYM != "semicolon")
	{
		if (common.SYM == "comma")
		{
			GETSYM();
			if (common.SYM != "ident")
				error_deal(12);//ȱ�ٱ�����
			else
			{
				dx++;
				Enter(variable,dx);
				GETSYM();
			}
		}
		if (common.SYM == "ident")
		{
			error_deal(11);
			GETSYM();
		}
		if (common.SYM == "proceduresym" || common.SYM == "beginsym")
		{
			error_deal(6);
			return;
		}
		n++;
		if (n > 10)
			break;
	}
	GETSYM();
}
void body_check(int tx0,int &dx)
{
	int cx0(0);//cx��ֵ
	cx0 = cx;
	/////////////
	if (common.SYM != "beginsym")
		error_deal(16);//ȱ��begin
	else
		GETSYM();
	while (common.SYM != "endsym")
	{
		int sign;
		sign = 0;
		statement_check();
		if (common.SYM != "semicolon"&& common.SYM != "endsym"&&common.SYM!="beginsym")
		{
			error_deal(6);
		}
		if (common.SYM == "semicolon")
		{
			GETSYM();
			sign = 1;
		}
		if (common.SYM == "endsym")
		{
			if (sign == 1)
				error_deal(23);//���˷ֺ�
			common.SYM = "semicolon";
			return;
		}
		
		if (common.SYM == "beginsym")
		{
			error_deal(20);
			return;
		}
			
	}
	Gen("opr", 0, 0);//���ص��õ㲢��ջ
	GETSYM();
	if (file.peek() == EOF)
		return;
}
void proc_check()
{
	int num(0);//��¼�����ĸ���
	lev++;
	/////////////////
	int n(0);
	GETSYM();
	if (common.SYM != "ident")
		error_deal(13);//ȱ�ٹ�����
	else
	{
		Enter(procedure);
		GETSYM();
	}
	if (common.SYM != "L_parenthesis")
		error_deal(14);//ȱ��������
	else
		GETSYM();
	if (common.SYM == "R_parenthesis")
		GETSYM();
	else if (common.SYM == "ident")
	{
		num++;
		Enter(variable, 3+num);
		GETSYM();
	}
	while (common.SYM != "R_parenthesis")
	{
		if (common.SYM == "comma")
		{
			GETSYM();
			if (common.SYM == "ident")
			{
				num++;
				Enter(variable, 3+num - 1,0);
				GETSYM();
			}
			else
			{
				error_deal(12);
			}
		}
		if (common.SYM == "ident")
		{
			error_deal(11);
			GETSYM();
		}
		if (common.SYM == "semicolon")
		{
			error_deal(15);//ȱ��������
			break;
		}
		n++;
		if (n > 10)
			break;
	}
	table[tx-num].adr = num;
	GETSYM();
	if (common.SYM != "semicolon")
		error_deal(6);
	else
		GETSYM();
	block_check(num);
	if (file.peek() == EOF)
		return;
	if (common.ID == ";")
	{
		GETSYM();
		proc_check();
	}
	if (common.SYM == "procedure")
	{
		error_deal(6);
		proc_check();
	}
	lev--;
	if (file.peek() == EOF)
		return;
}

void block_check(int num=0)
{
	int dx(0);//������ƫ����
	int tx0(0);//tx��ֵ
	dx = 3+num;
	tx0 = tx-num;//������ǰtable��ָ��ֵ
	table[tx-num].adr = cx;
	Gen("jmp", 0, 0);
	////////////////////
	if (common.SYM == "constsym")
		condecl_check(dx);
	if (common.SYM == "varsym")
	{
		vardecl_check(dx);
		/*int i;
		for ( i = tx; i > 0; i--)
		{
			if (table[i].kind == procedure)
				break;
		}
		table[i].size = sz;*/
	}
	if (common.SYM == "proceduresym")
		proc_check();
	code[table[tx0].adr].a = cx;//������ڻ���
	table[tx0].adr = cx;//��¼����λ��
	table[tx0].size = dx;//��¼
	Gen("inte", 0, dx);

	body_check(tx0,dx);
	Gen("opr", 0, 0);
	GETSYM();
	if (file.peek() == EOF)
		return;
}
void gen_display()
{
	int i;
	for (i = 0; i < cx; i++)
		cout << i << ": " << code[i].f << " " << code[i].l << " " << code[i].a << endl;
}
void Grammar()
{
	GETSYM();
	if (common.SYM != "programsym")
		error_deal(4);//ȱ��program
	else
		GETSYM();
	if (common.SYM != "ident")
		error_deal(5);//ȱ�ٳ�����
	else
		GETSYM();
	if (common.SYM != "semicolon")
		error_deal(6);//ȱ��';'
	else
		GETSYM();
	block_check();
}
//#######################�﷨����+�������###################//
//############################ִ�д���#######################//
//ÿ��block���뿪�ٵ�sl(��̬��:ָ����ù��̵�ֱ�����������ʱ�������ݶ˵�
//����ַ),dl(��̬��:ָ����øù���ǰ�������й��̵����ݶλ���ַ),ra(���ص�ַ:
//��¼���øù���ʱĿ�����Ķϵ�,�����ù���ָ�����һ��ָ��ĵ�ַ).
//lit:0,lod:1,sto:2,inte:3,jmp:4,jpc:5,opr:6
//����ָ����
int sel(instruction in)
{
	if (in.f == "lit")
		return 0;
	else if (in.f == "lod")
		return 1;
	else if (in.f == "sto")
		return 2;
	else if (in.f == "inte")
		return 3;
	else if (in.f == "jmp")
		return 4;
	else if (in.f == "jpc")
		return 5;
	else if (in.f == "cal")
		return 6;
	else if (in.f == "opr")
		return in.a + 7;
	else return false;
}
void interpret()
{
	int stack[1000] = { 0 };//����ģ��ջ�ռ�
	int t = 0, b = 0, p = 0;//�ֱ�Ϊ��ǰջ��ָ��Ĵ���,�����ù��̵Ļ���ַ,������ڵ�ַ
	int select,j;
	int b_last;//��ȥ�Ĺ��̻���ַ
	while (p < cx)
	{
		select = sel(code[p]);
		switch (select)
		{
		case 0://lit
			t++;
			stack[t] = code[p].a;
			break;
		case 1://lod
			b_last = b;
			j = code[p].l;
			for (int k = 0; k < j; k++)
				b_last = stack[b_last];
			t++;
			stack[t]=stack[b_last + code[p].a-1];
			break;
		case 2://sto
			b_last = b;
			j = code[p].l;
			if (j < 0)
				stack[t + code[p].a+1] = stack[t];
			else
			{
				for (int k = 0; k < j; k++)
					b_last = stack[b_last];
				stack[b_last + code[p].a-1] = stack[t];
			}
			break;
		case 3://inte
			b = t;//��¼��ǰ���̵Ļ���ַ
			t = t + code[p].a-1;//����ջ��ָ��
			break;
		case 4://jmp
			p = code[p].a-1;
			break;
		case 5://jpc
			if (!stack[t])
				p = code[p].a-1;
			break;
		case 6://cal             
			b_last = b;
			t++;
			stack[t] = stack[b_last];
			stack[t + 1] = b;
			stack[t + 2] = p + 1;
			p = code[p].a-1;
			break;
		case 7://opr 00
			if (p + 1 >= cx)
				break;
			p = stack[b + 2]-1;
			t = b ;
			b = stack[b + 1];
			break;
		case 8://opr 01
			stack[t] = -stack[t];
			break;
		case 9://opr 02
			stack[t - 1] += stack[t];
			t = t - 1;
			break;
		case 10://opr 03
			stack[t - 1] -= stack[t];
			t = t - 1;
			break;
		case 11://opr 04
			stack[t - 1] *= stack[t];
			t = t - 1;
			break;
		case 12://opr 05
			stack[t - 1] /= stack[t];
			t = t - 1;
			break;
		case 13://opr 06
			stack[t] %= 2;
			break;
		case 14://opr 07
			break;
		case 15://opr 08
			stack[t-1]=(stack[t - 1] == stack[t]) ? 1 : 0;
			t = t - 1;
			break;
		case 16://opr 09
			stack[t-1]=(stack[t - 1] == stack[t]) ? 0 : 1;
			t = t - 1;
			break;
		case 17://opr 010
			stack[t-1]=(stack[t - 1] < stack[t]) ? 1 : 0;
			t = t - 1;
			break;
		case 18://opr 011
			stack[t-1]=(stack[t - 1] >= stack[t]) ? 1 : 0;
			t = t - 1;
			break;
		case 19://opr 012
			stack[t-1] = (stack[t - 1] > stack[t]) ? 1 : 0;
			t = t - 1;
			break;
		case 20://opr 013
			stack[t-1] = (stack[t - 1] <= stack[t]) ? 1 : 0;
			t = t - 1;
			break;
		case 21://opr 014
			cout << stack[t] << endl;
			break;
		case 22://opr 015
			cout << endl;
			break;
		case 23://opr 016
			cout << "������num: ";
			t++;
			cin >> stack[t];
			cout << endl;
		}
		p++;
	}
}
//############################ִ�д���#######################//
int main()
{
	file.open("testCode.txt", ios::in);
	if (file.fail())
	{
		cout << "open file failed!" << endl;
		exit(0);
	}
	Initial_Key_w();
	Grammar();
	/*while (file.peek() != EOF)
	{
		GETSYM();
	}*/
	file.close();
	gen_display();
	interpret();
	return 0;
}