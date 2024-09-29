#include "Project_IO_File.h"

string Hard = "00.Ӳ�����";
string Soft = "01.������";
string Instr = "02.˵���ĵ�";
string Ref = "03.�ο�����";



static int  CreatFold(std::string name)
{
	int val;

	if (0 == _mkdir(name.c_str()))
	{
		val = _mkdir(name.c_str());
		cout << "�ļ���" + name + "�����ɹ�" << endl;
	}
	else
	{
		val = _mkdir(name.c_str());
		cout << "�ļ���" + name + "����ʧ��" << endl;
	}

	return val;
}



static void CreatFlie(string filename)
{
	ofstream outfile;

	/* �½��汾�޸ļ�¼�ļ� */
	outfile.open(filename);

	if (filename.find(VESER_RECORD) != -1)
	{
		outfile << "��Ŀ����:"  + filename  << endl;
		outfile << "V10 :" << endl;
		outfile << "V1.0->V1.1 :" << endl;
		outfile << "V1.1->V1.2 :" << endl;
	}
	else if (filename.find(REQUESTION) != -1)
	{
		outfile << "V1.0 :" << endl;
	}
	else if (filename.find(JOINPEOPLE) != -1)
	{
		outfile << "��� : �ֺ���" << endl;
		outfile << "Ӳ�� : " << endl;
		outfile << "�ṹ : " << endl;
		outfile << "ҵ�� : " << endl;
	}
	else
	{
		;
	}

	outfile.close();
}



void Creat_Project_Fold(string project, string IC)
{
	int val;
	string name, path;

	name = project;

	/* ������Ŀ���ļ��� */
	val = CreatFold(name);
	if (val)
	{
		/* ����������Ա�������ļ� */
		CreatFlie(name + "\\" + JOINPEOPLE);

		val = CreatFold(name + "\\" + Hard);

		/* �����ڲ��ļ��� */

		//Ӳ���ļ���
		if (val)
		{
			path = name + "\\" + Hard + "\\";
			CreatFold(path + "V1.0");
		}

		//����ļ���
		val = CreatFold(name + '\\' + Soft);
		if (val)
		{	/*�����ļ��кͰ汾��¼�ļ�*/
			//V1.0
			path = name + "\\" + Soft + "\\" + "V1.0" + "\\";
			CreatFold(path);
			CreatFold(path + name + "-" + "V1.0" + "-" + IC);
			CreatFlie(path + VESER_RECORD);
		}
		val = CreatFold(name + '\\' + Instr);
		val = CreatFold(name + '\\' + Ref);
	}

	if (val) { cout << "��Ŀ�ļ��д����ɹ�" << endl; }
	else { cout << "��Ŀ�ļ��д���ʧ��" << endl; }

}
