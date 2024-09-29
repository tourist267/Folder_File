// Project_IO_File_Printf.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Project_IO_File.h"
/*  
	读取初始化文件内容
*/
static string Read_File_Data(string startString, string EndString)
{
	std::string rangeContent;
	ifstream inputFile("Data.ini");

	if (!inputFile.is_open()) {
		std::cerr << "无法打开文件" << std::endl;
		return "Error";
	}

	// 读取文件内容到字符串中
	stringstream buffer;
	buffer << inputFile.rdbuf();
	std::string fileContent(buffer.str());

	// 在文件内容中查找起始和结束字符串之间的内容
	size_t startPos = fileContent.find(startString);
	size_t endPos = fileContent.find(EndString);
	if (startPos != std::string::npos && endPos != std::string::npos) {
		rangeContent = fileContent.substr(startPos + startString.length(), endPos - startPos - startString.length());
	//	std::cout << "读取的范围内容: " << rangeContent << std::endl;
	}
	else {
		std::cout << "参数错误,未找到有效数据" << std::endl;
	}
	// 关闭文件
	inputFile.close();

	return rangeContent;
}
/*
	检测字符串是否是数字
*/
bool isNumber(const std::string& str) {
	try {
		std::stoi(str);
		return true;
	}
	catch (std::invalid_argument& e) {
		// 如果字符串不是数字，则会抛出异常
		return false;
	}
}
/*
	检测IO端口数字是否正确
*/
bool isIO_Right(const string *str, string* RightIO)
{
	for (int i = 0; *str != "END"; i++)
	{
		if (*str == *RightIO)
			return true;
		str++;

		if (i >= 100) { break; }

	}
	return false;
}

bool IO_Check(const string str, const string Start, const string end)
{
	
	string Return_Data = Read_File_Data(Start, end);
	istringstream iss(Return_Data);

	/* 检测IO口端口号是否有效*/
	while (getline(iss, Return_Data, ','))
	{
		/* 将读取到的字符串里面的\n删除 */
		size_t pos = Return_Data.find("\n");
		while (pos != std::string::npos)
		{
			Return_Data.erase(pos, 1);
			pos = Return_Data.find("\n", pos);
		}
		/* 有效的话就直接退出 */
		if (stoi(Return_Data) == stoi(str))
		{
			return 1;
		}		
	}

	return 0;
}

/*
	检测IC名称是否正确
*/
static string  IC_Check(string IC,string Start,string end)
{
	int i, num, temp = 0, Parameter1 = 0;
	int Data[20];
	string Return_Data, NameIC[20];

	/* 输入的IC型号是空则直接退出 */
	if (IC == "\0") { return ""; }

	Return_Data = Read_File_Data(Start, end);
	istringstream iss(Return_Data);

	/* 获得IC数组和IC个数 */
	num = 0;
	while (getline(iss, Return_Data, ','))
	{
		/* 将读取到的字符串里面的\n删除 */
		size_t pos = Return_Data.find("\n");
		while (pos != std::string::npos)
		{
			Return_Data.erase(pos, 1);
			pos = Return_Data.find("\n", pos);
		}
		/* 保存读取的数据 */
		NameIC[num] = Return_Data;
		num++; 
		
	}
	temp = 0;
	/* 遍历获取IC在IC数组的元素下标 */
	for (i = 0; i <= (num - 1); i++)
	{
		if (NameIC[i].find(IC) != std::string::npos)
		{
			Data[temp] = i;
			temp++;
		}
	}
	/* 清空字符串 */
	Return_Data = "";

	if (temp > 1)
	{
		cout << "有多个结果,请确认\n" << endl;

		for (i = 0; i < temp; i++)
		{
			cout << i << "、 " << NameIC[Data[i]] << "; \n" << endl;
		}

		cin >> Parameter1;
		switch (Parameter1)
		{
		case 0:Return_Data = NameIC[Data[0]]; break;
		case 1:Return_Data = NameIC[Data[1]]; break;
		case 2:Return_Data = NameIC[Data[2]]; break;
		case 3:Return_Data = NameIC[Data[3]]; break;
		case 4:Return_Data = NameIC[Data[4]]; break;
		case 5:Return_Data = NameIC[Data[5]]; break;
		case 6:Return_Data = NameIC[Data[6]]; break;
		case 7:Return_Data = NameIC[Data[7]]; break;
		case 8:Return_Data = NameIC[Data[8]]; break;
		case 9:Return_Data = NameIC[Data[9]]; break;
		default:Return_Data = "0"; break;
		}
	}
	else if(temp == 1)
	{
		Return_Data = NameIC[Data[temp - 1]];
	}
	else
	{
		Return_Data = ERROE_FLAG;
	}

	return Return_Data;
}

typedef enum {
	SN_IC = 1,
	CMS_IC,
	CMS_SC8_IC,
	MC_IC,
	SC9_IC,
	OTP_IC,
};

static int IO_File(void)
{
	string Parameter[10], IC_Name = "", Code, Code_IO_Num, Inuput, Type_Name;
	int Create_IO_Num = 0, i = 0,IC = 0, Parameter_Num=0, IO_Time;
	int Input_Buff_Change_f = 1,return_tmp=0;

	cout << "输入主控IC:" << endl;
	cin >> Inuput;
	
	for (auto& c : Inuput) {
		c = std::toupper(c);
	}
	/* 检测输入的IC型号 */
	IC_Name = IC_Check(Inuput, "IO_FILE_IC_Name_Start","IO_FILE_IC_Name_End");
	/* 输入错误 */
	while (IC_Name == ERROE_FLAG)
	{
		cout << "IC未找到请重新输入" << "\n" << endl;
		cout << "输入主控IC:" << endl;
		cin >> Inuput;
		IC_Name = IC_Check(Inuput, "IO_FILE_IC_Name_Start", "IO_FILE_IC_Name_End");

		if (++return_tmp > 5) {
			cout << "输入错误,退出:" << endl;
			return 0; 
		}
		
	}

	cout << "选择IC型号为:" << IC_Name << "\n" << endl;
	if (IC_Name == "CMS6053D" || IC_Name == "SN8P2501D") { IC = OTP_IC; }
	else
	{
		if (IC_Name.find("SN") == 0) { IC = SN_IC; }/* 松翰系列 */
		if (IC_Name.find("CMS") == 0) { IC = CMS_IC; }/* 中微8051系列 */
		if (IC_Name.find("SC8") == 0)
		{
			IC = CMS_SC8_IC;
			cout << "注:A口:0-7,B口:10-17,C口:21-27;\n" << endl;
		}/* 中微RIV系列 */
		if (IC_Name.find("MC") == 0) { IC = MC_IC; }/* 晟矽微系列 */
		if (IC_Name.find("SC9") == 0) { IC = SC9_IC; }/* 赛元系列 */
	}

	
	while (1)
	{
		cout << " 输入IO名称和IO口\n" << endl;
		if (Input_Buff_Change_f)
		{
			Input_Buff_Change_f = 0;
			cin.ignore();
		}
		getline(cin, Inuput);
		if (Inuput == END_FLAG) {
			cout << " 退出\n" << endl;
			return 1; }
		istringstream iss(Inuput);
		while (iss >> Code) {

			Parameter[Parameter_Num] = Code;
			Parameter_Num++;
		}
		Parameter_Num--;


		if (isNumber(Parameter[Parameter_Num]) && isNumber(Parameter[Parameter_Num - 1]))
		{
			// 倒数第一第二个都是数字,则表示要生成多个IO语句
			Create_IO_Num = stoi(Parameter[Parameter_Num]);

			/* 获得IO口名称 */
			for (i = 0; i < (Parameter_Num - 1); i++)
			{
				Type_Name += Parameter[i];
				if (i < (Parameter_Num - 2))
				{
					Type_Name += "_";
				}

			}
		}
		else if (isNumber(Parameter[Parameter_Num]))
		{
			// 仅最后一个是数字,则表示要生成单个IO语句
			Create_IO_Num = 1;
			/* 获得IO口名称 */
			for (i = 0; i < (Parameter_Num); i++)
			{
				Type_Name += (Parameter[i]);
				if (i < (Parameter_Num - 1))
				{
					Type_Name += "_";
				}
			}
		}
		else
		{
			//最后没有数字的话表示参数有问题
			Create_IO_Num = 0;
			cout << "参数错误" << endl;
		}

		

		if (Create_IO_Num)
		{

			/* 将IO名称转化成大写 */
			for (auto& c : Type_Name) {
				c = std::toupper(c);
			}
			for (i = 0; i < Create_IO_Num; i++)
			{

				if (Create_IO_Num > 1)//要生成多个IO语句
				{
					Code = "IO_" + Type_Name + to_string(i + 1);
					Code_IO_Num = Parameter[Parameter_Num - 1];
				}
				else//要生成单个IO语句
				{
					Code = "IO_" + Type_Name;
					Code_IO_Num = Parameter[Parameter_Num];
				}

				/* 将代码写到文件里面 */
				switch (IC)
				{
					/* 松翰系列IC */
					case SN_IC:
								SN_Code_Creat(Code, Code_IO_Num); break;

					/* 中微8051系列IC */
					case CMS_IC:
								CMS_Code_Creat(Code, Code_IO_Num); break;

					/* 中微RISV系列IC */
					case CMS_SC8_IC:
									CMS_SC8_Code_Creat(Code, Code_IO_Num); break;

					/* 晟矽微系列IC */
					case MC_IC:
								MC_Code_Creat(Code, Code_IO_Num); break;

					/* 赛元系列 */
					case SC9_IC:break;

					/* 一次性系列 */
					case OTP_IC:
								OTP_Code_Creat(Code, Code_IO_Num); break;

				}

				/* 多个IO相同类型的IO语句重新输入端口号 */
				if (i < (Create_IO_Num - 1))
				{
					Input_Buff_Change_f = 1;
					cout << "输入IO口号\n " << endl;
					cin >> IO_Time;
					Parameter[(Parameter_Num - 1)] = to_string(IO_Time);
				}
			}
		}
			

		/* 结束后清零变量 */
		Parameter_Num = 0;
		Code = "\0";
		Code_IO_Num = "\0";
		Type_Name = "\0";
		for (i = 0; i < 10; i++) { Parameter[i] = "\0"; }
	}

}
static int Fold(void)
{
	string Parameter, Parameter1;
	int return_temp = 0;

	cout << "输入项目型号:" << endl;
	cin >> Parameter1;
	cout << "输入主控IC:" << endl;
	cin >> Parameter;
	Parameter = IC_Check(Parameter,"IO_FOLD_IC_Name_Start","IO_FOLD_IC_Name_End");

	while (Parameter == ERROE_FLAG)
	{
		cout << "IC未找到请重新输入" << "\n" << endl;
		cout << "输入主控IC:" << endl;
		cin >> Parameter;
		Parameter = IC_Check(Parameter, "IO_FILE_IC_Name_Start", "IO_FILE_IC_Name_End");

		if (++return_temp > 5)
		{
			cout << "输入错误,退出" << "\n" << endl;
			return 0;
		}
		
	}

	cout << "选择IC型号为:" << Parameter << "\n" << endl;
	Creat_Project_Fold(Parameter1, Parameter);
	return 1;
}

#define FILE_ONLY						1
#define FOLD_ONLY						3
#define FILE_WITH_FOLD					2

int main()
{
	string Parameter1, Parameter, IC_Name;
	int Chooce = 0, Result = 0;;

	while (1)
	{
		switch (Chooce)
		{
			/* 仅建立IO文件 */
			case FILE_ONLY:
							Result = IO_File(); 
							/* 异常退出 */
							if (Result == 0) { Chooce = 0; return 0; }
							else { Chooce = 0; }/* 正常退出 */
							break;

				/* 建立IO文件和文件夹 */
			case FILE_WITH_FOLD:
							Result = Fold();
							/* 异常退出 */
							if (Result == 0) { Chooce = 0; return 0; }
							else { Chooce = 0; }/* 正常退出 */
							Result = IO_File(); 
							/* 异常退出 */
							if (Result == 0){Chooce = 0;return 0;}
							else{Chooce = 0;}/* 正常退出 */
							break;

				/* 仅建立文件夹 */
			case FOLD_ONLY:
							Result = Fold();
							/* 异常退出 */
							if (Result == 0) { Chooce = 0; return 0; }
							else { Chooce = 0; }/* 正常退出 */
							break;
							


			default:
								if (Chooce > FOLD_ONLY)
								{
									cout << "参数有误: \n" << endl;
								}
								cout << "\n\n" << endl;
								cout << "请输入以下参数: \n" << endl;
								cout << "1, 输入1,仅建立IO文件 \n" << endl;
								cout << "2, 输入2,建立文件夹和IO文件 \n" << endl;
								cout << "3, 输入3,仅建立文件夹 \n" << endl;
								cin >> Chooce;

								break;
		}
	}


}
