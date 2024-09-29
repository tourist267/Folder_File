// project.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Spire.Xls.o.h"

using namespace Spire::Xls;

int main()
{
	std::wstring output_path = L"OUTPUTPATH/";
	std::wstring outputFile = output_path + L"HelloWorld2.xlsx";

	//Create a workbook
	intrusive_ptr<Workbook> workbook = new Workbook();
	//Get the first sheet
	intrusive_ptr<Worksheet> sheet = dynamic_pointer_cast<Worksheet>(workbook->GetWorksheets()->Get(0));

	dynamic_pointer_cast<CellRange>(sheet->GetRange(L"B10"))->SetText(L"Hello World");
	dynamic_pointer_cast<CellRange>(sheet->GetRange(L"B10"))->AutoFitColumns();

	//Save to file
	workbook->SaveToFile(outputFile.c_str(), ExcelVersion::Version2013);
	workbook->Dispose();
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
