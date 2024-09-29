#ifndef PROJECT_IO_FILE_H
#define PROJECT_IO_FILE_H

#include <iostream>
#include <direct.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>

using namespace std;

#define IO_SPCAE			"			          "
#define CODE_START			"#define IO_"

#define FILE_NAME			"define.h"	

#define VESER_RECORD "版本修改记录.txt"
#define REQUESTION		"需求.txt"
#define	JOINPEOPLE	"参与人员.txt"
#define FF			"\\"

#define MC_STSRT		"MC_IO_START"
#define MC_END			"MC_IO_END"

#define CMS_STSRT		"CMS_IO_START"
#define CMS_END			"CMS_IO_END"

#define CMS_SC8_STSRT		"CMS_SC8_IO_START"
#define CMS_SC8_END			"CMS_SC8_IO_END"

#define SN_STSRT		"SN_IO_START"
#define SN_END			"SN_IO_END"

#define ERROE_FLAG				"ERROR"
#define END_FLAG				"END"


#define INT_TYPE			1
#define STRING_TYPR			2


void Creat_Project_Fold(string project, string IC);

bool isIO_Right(const string* str, string* RightIO);
bool isNumber(const std::string& str);
bool IO_Check(const string str, const string Start, const string end);

void  CMS_Code_Creat(string Code, string IO_Number);
void  MC_Code_Creat(string Code, string IO_Number);
void  SN_Code_Creat(string Code, string IO_Number);
void  CMS_SC8_Code_Creat(string Code, string IO_Number);
void  OTP_Code_Creat(string Code, string IO_Number);
#endif
