#include "Project_IO_File.h"

string Hard = "00.硬件设计";
string Soft = "01.软件设计";
string Instr = "02.说明文档";
string Ref = "03.参考代码";



static int  CreatFold(std::string name)
{
	int val;

	if (0 == _mkdir(name.c_str()))
	{
		val = _mkdir(name.c_str());
		cout << "文件夹" + name + "创建成功" << endl;
	}
	else
	{
		val = _mkdir(name.c_str());
		cout << "文件夹" + name + "创建失败" << endl;
	}

	return val;
}



static void CreatFlie(string filename)
{
	ofstream outfile;

	/* 新建版本修改记录文件 */
	outfile.open(filename);

	if (filename.find(VESER_RECORD) != -1)
	{
		outfile << "项目名称:"  + filename  << endl;
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
		outfile << "软件 : 林洪欣" << endl;
		outfile << "硬件 : " << endl;
		outfile << "结构 : " << endl;
		outfile << "业务 : " << endl;
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

	/* 创建项目主文件夹 */
	val = CreatFold(name);
	if (val)
	{
		/* 建立参与人员和需求文件 */
		CreatFlie(name + "\\" + JOINPEOPLE);

		val = CreatFold(name + "\\" + Hard);

		/* 建立内部文件夹 */

		//硬件文件夹
		if (val)
		{
			path = name + "\\" + Hard + "\\";
			CreatFold(path + "V1.0");
		}

		//软件文件夹
		val = CreatFold(name + '\\' + Soft);
		if (val)
		{	/*建立文件夹和版本记录文件*/
			//V1.0
			path = name + "\\" + Soft + "\\" + "V1.0" + "\\";
			CreatFold(path);
			CreatFold(path + name + "-" + "V1.0" + "-" + IC);
			CreatFlie(path + VESER_RECORD);
		}
		val = CreatFold(name + '\\' + Instr);
		val = CreatFold(name + '\\' + Ref);
	}

	if (val) { cout << "项目文件夹创建成功" << endl; }
	else { cout << "项目文件夹创建失败" << endl; }

}
