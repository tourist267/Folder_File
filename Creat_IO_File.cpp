#include "Project_IO_File.h"

void  OTP_Code_Creat(string Code, string IO_Number)
{
	string  Code_IO, Code_OUT;
	int IO_Number_Tmp = 0;

	ofstream file("define.h", ios::app);
	IO_Number_Tmp = stoi(IO_Number);
	if (IO_Number_Tmp < 10) { IO_Number = "0" + to_string(IO_Number_Tmp); }
	/* 输出语句生成  */
	Code_IO = "#define "+ Code + IO_SPCAE + "FP" + IO_Number + "\n";
	Code_OUT = "#define " + Code+"M" + IO_SPCAE + "FP" + IO_Number + "M" + "\n";

	if (file.is_open())
	{
		/* 将数据写到文件里面 */
		file << Code_IO;
		file << Code_OUT;
		file << "\n \n";

		/* 数据输出显示到屏幕 */
		cout << Code_IO;
		cout << Code_OUT;

		file.close();
	}
	else
	{
		std::cout << "无法打开文件 \n \n \n " << std::endl;
	}

}

void  CMS_SC8_Code_Creat(string Code, string IO_Number)
{
	string  Code_IO, Code_OUT, Code_ON, Code_OFF, Code_IN;
	int En_f = 1, IO_Number_Tmp = 0;
	unsigned int GPIO_Num = 0;

	GPIO_Num = stoi(IO_Number);
	

	/* 检测IO端口号是否正确 */
	if (IO_Check(IO_Number, CMS_SC8_STSRT, CMS_SC8_END) == 0)
	{
		cout << " 端口数错误 \n \n\n" << endl;
		En_f = 0;
	}
	
	ofstream file("define.h", ios::app);

	if (En_f == 1)
	{
		IO_Number_Tmp = stoi(IO_Number);
		if (IO_Number_Tmp < 10) { IO_Number = "A" + to_string(IO_Number_Tmp); }
		else if (IO_Number_Tmp < 20) { IO_Number = "B" + to_string(IO_Number_Tmp%10);}
		else if (IO_Number_Tmp < 30) { IO_Number = "C" + to_string(IO_Number_Tmp % 10); }

		/* 输出语句生成  */
		Code_IO = "#define " + Code + IO_SPCAE + "	R" + IO_Number + "\n";
		Code_OUT = "#define " + Code + "_OUT  " + IO_SPCAE + "TRIS" + IO_Number + " = 0\n";
		Code_ON = "#define " + Code + "_ON   " + IO_SPCAE + Code + " = 1\n";
		Code_OFF = "#define " + Code + "_OFF  " + IO_SPCAE + Code + " = 0\n";
		Code_IN = "#define " + Code + "_IN   " + IO_SPCAE + "TRIS" + IO_Number + " = 1\n";

		if (file.is_open())
		{
			/* 将数据写到文件里面 */
			file << Code_IO;
			file << Code_OUT;
			file << Code_ON;
			file << Code_OFF;
			file << Code_IN;
			file << "\n \n";

			/* 数据输出显示到屏幕 */
			cout << Code_IO;
			cout << Code_OUT;
			cout << Code_ON;
			cout << Code_OFF;
			cout << Code_IN;

			file.close();
		}
		else
		{
			std::cout << "无法打开文件 \n \n \n " << std::endl;
		}

	}

}


void  SN_Code_Creat(string Code, string IO_Number)
{
	string  Code_IO, Code_OUT, Code_ON, Code_OFF, Code_IN;
	int En_f = 1;
	unsigned int GPIO_Num = 0;

	GPIO_Num = stoi(IO_Number);
	/* 如果IO口号小于10,在前面加个0 */
	if (GPIO_Num < 10)
	{
		IO_Number = "0" + IO_Number;
	}

	/* 检测IO端口号是否正确 */
	if (IO_Check(IO_Number, SN_STSRT, SN_END) == 0)
	{
		cout << " 端口数错误 \n \n\n" << endl;
		En_f = 0;
	}
	

	ofstream file("define.h", ios::app);

	if (En_f == 1)
	{
		/* 输出语句生成  */
		Code_IO = "#define " + Code + IO_SPCAE + "	P" + IO_Number + "\n";
		Code_OUT = "#define " + Code + "_OUT  " + IO_SPCAE + "P" + to_string(GPIO_Num / 10) + "M |= BIT" + to_string(GPIO_Num % 10) + "\n";
		Code_ON = "#define " + Code + "_ON   " + IO_SPCAE + Code + " = 1\n";
		Code_OFF = "#define " + Code + "_OFF  " + IO_SPCAE + Code + " = 0\n";
		Code_IN = "#define " + Code + "_IN   " + IO_SPCAE + "P" + to_string(GPIO_Num / 10) + "M &= ~BIT" + to_string(GPIO_Num % 10) + ";P" + \
			to_string(GPIO_Num / 10) + "UR |= BIT" + to_string(GPIO_Num % 10) + "\n";
		if (file.is_open())
		{
			/* 将数据写到文件里面 */
			file << Code_IO;
			file << Code_OUT;
			file << Code_ON;
			file << Code_OFF;
			file << Code_IN;
			file << "\n \n";

			/* 数据输出显示到屏幕 */
			cout << Code_IO;
			cout << Code_OUT;
			cout << Code_ON;
			cout << Code_OFF;
			cout << Code_IN;

			file.close();
		}
		else
		{
			std::cout << "无法打开文件 \n \n \n " << std::endl;
		}

	}

}

void  CMS_Code_Creat(string Code, string IO_Number)
{
	string  Code_IO, Code_OUT, Code_ON, Code_OFF, Code_IN;
	int En_f = 1;
	unsigned int GPIO_Num = 0;

	GPIO_Num = stoi(IO_Number);
	/* 如果IO口号小于10,在前面加个0 */
	if (GPIO_Num < 10)
	{
		IO_Number = "0" + IO_Number;
	}

	/* 检测IO端口号是否正确 */
	if (IO_Check(IO_Number, CMS_STSRT, CMS_END) == 0)
	{
		cout << " 端口数错误 \n \n\n" << endl;
		En_f = 0;
	}
	
	ofstream file("define.h", ios::app);

	if (En_f == 1)
	{
		/* 输出语句生成  */
		Code_IO = "#define " + Code + IO_SPCAE + "	P" + IO_Number + "\n";
		Code_OUT = "#define " + Code + "_OUT  " + IO_SPCAE + "P" + IO_Number + "CFG = 0x00;P" + to_string(GPIO_Num / 10) + "TRIS |= BIT" + to_string(GPIO_Num % 10) + "\n";
		Code_ON = "#define " + Code + "_ON   " + IO_SPCAE + Code + " = 1\n";
		Code_OFF = "#define " + Code + "_OFF  " + IO_SPCAE + Code + " = 0\n";
		Code_IN = "#define " + Code + "_IN   " + IO_SPCAE + "P" + IO_Number + "CFG = 0x00;P" + to_string(GPIO_Num / 10) + "TRIS &= ~BIT" + \
			to_string(GPIO_Num % 10) + ";P" + to_string(GPIO_Num / 10) + "UP |= BIT" + to_string(GPIO_Num % 10) + "\n";

		if (file.is_open())
		{

			/* 将数据写到文件里面 */
			file << Code_IO;
			file << Code_OUT;
			file << Code_ON;
			file << Code_OFF;
			file << Code_IN;
			file << "\n \n";

			/* 数据输出显示到屏幕 */
			cout << Code_IO;
			cout << Code_OUT;
			cout << Code_ON;
			cout << Code_OFF;
			cout << Code_IN;

			file.close();
		}
		else
		{
			std::cout << "无法打开文件 \n \n \n " << std::endl;
		}

	}

}


void  MC_Code_Creat(string Code,string IO_Number)
{
	string  Code_IO, Code_OUT, Code_ON, Code_OFF, Code_IN;
	int En_f = 1;

	/* 如果IO口号小于10,在前面加个0 */
	if (stoi(IO_Number) < 10)
	{
		IO_Number = "0" + IO_Number;
	}

	/* 检测IO端口号是否正确 */
	if (IO_Check(IO_Number, MC_STSRT, MC_END) == 0)
	{
		cout << " 端口数错误 \n \n\n" << endl;
		En_f = 0;
	}
	
	ofstream file("define.h", ios::app);

	if (En_f == 1)
	{
		/* 输出语句生成  */
		Code_IO = "#define " + Code + IO_SPCAE + "P" + IO_Number + "D\n";
		Code_OUT = "#define " + Code + "_OUT  " + IO_SPCAE + "P" + IO_Number + "_PUSHPULL_MODE\n";
		Code_ON = "#define " + Code + "_ON   " + IO_SPCAE + Code + " = 1\n";
		Code_OFF = "#define " + Code + "_OFF  " + IO_SPCAE + Code + " = 0\n";
		Code_IN = "#define " + Code + "_IN   " + IO_SPCAE + "P" + IO_Number + "_INPUTHIZ_MODE;" + "P" + IO_Number + "_INPUT_PULLUPZ\n";

		if (file.is_open())
		{

			/* 将数据写到文件里面 */
			file << Code_IO;
			file << Code_OUT;
			file << Code_ON;
			file << Code_OFF;
			file << Code_IN;
			file << "\n \n";

			/* 数据输出显示到屏幕 */
			cout << Code_IO;
			cout << Code_OUT;
			cout << Code_ON;
			cout << Code_OFF;
			cout << Code_IN;

			file.close();
		}
		else
		{
			std::cout << "无法打开文件 \n \n \n " << std::endl;
		}

	}
	
}
