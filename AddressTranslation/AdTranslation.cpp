#include "AdTranslation.h"
#include <iostream>
#include <bitset>

void AdTranslation::Translation_16()
{
	const string page_number=virtual_address_.substr(0,6);//取得前6位页号
	for (map<string, string>::iterator iterator = page.begin();iterator!=page.end();++iterator)
	{
		if (page_number==(*iterator).first)
		{
			physics_adress_ = (*iterator).second+virtual_address_.substr(6);
		}
	}
	
}

void AdTranslation::Translation_32()
{
	const string root_page_number=virtual_address_.substr(0,10);//根页号
	const string page_number = virtual_address_.substr(10, 10);
	Page *user_page = nullptr;


	//现在缓冲区查找,如果没有再去系统页面查找
	for (Page::iterator iterator = TLB.begin(); iterator != TLB.end(); ++iterator)
	{
		if (page_number == (*iterator).first)
		{
			physics_adress_ = (*iterator).second + virtual_address_.substr(20);
			return;
		}
	}
	//找到用户页
	for (map<string, Page>::iterator iterator =root_page.begin();iterator!=root_page.end();++iterator)
	{
		if (root_page_number==(*iterator).first)
		{
		
			user_page = &(*iterator).second;
			
			break;
		}
	}

	for (Page::iterator iterator=user_page->begin();iterator!=user_page->end();++iterator)
	{
		if (page_number==(*iterator).first)
		{
			TLB.insert(*iterator);//将最近访问的页面加入缓冲区
			physics_adress_ = (*iterator).second + virtual_address_.substr(20);
		}
	}
}
string AdTranslation::BinToHex(string &strBin, bool bIsUpper)
{
	string result="";
	int len = strBin.length() % 4;
	while (len!=0)
	{
		len = strBin.length() % 4;
		strBin.insert(0, len, '0');
	}
	
	cout << strBin << endl;
	for (int i=0;i<strBin.length();)
	{
		string temp = strBin.substr(i, i + 4);
		int n = pow(2, 3)*(temp[0] - '0') +
					pow(2, 2)*(temp[1] - '0' )+
					pow(2, 1)*(temp[2] - '0' )+
					pow(2, 0)*(temp[3] - '0');
		char a[2];
		_itoa_s(n, a, 16);
		result += a;
		i += 4;
	}
	return  result;
}
string AdTranslation::HexToBin(const  string &strHex)
{
	long  long  int n=0;
	int len = strHex.length();
	for ( int i=0;i<strHex.length();i++)
	{
		if (strHex[i]<='9'&&strHex[i] >= '0')
		{
			n += (strHex[i] - '0')* pow(16, len - i - 1);
		}
		else
		{
			n += (strHex[i] - 'a' + 10)* pow(16, len - i - 1);
			
		}
	
	}
	bitset<32>sss(n);
	string result = sss.to_string();
	return  result;
}
AdTranslation::AdTranslation()
{
	Page first;
	first.insert(pair<string, string>("1010110011", "10010001110101101110"));
	first.insert(pair<string, string>("0000000002", "000000000021"));
	first.insert(pair<string, string>("0000000003", "000000000022"));
	first.insert(pair<string, string>("0000000004", "000000000023"));
	first.insert(pair<string, string>("0000000005", "000000000024"));
	Page second;
	second.insert(pair<string, string>("6", "30"));
	second.insert(pair<string, string>("7", "31"));
	second.insert(pair<string, string>("8", "32"));
	second.insert(pair<string, string>("9", "33"));
	second.insert(pair<string, string>("10", "34"));
	Page third;
	third.insert(pair<string, string>("6", "30"));
	third.insert(pair<string, string>("7", "31"));
	third.insert(pair<string, string>("8", "32"));
	third.insert(pair<string, string>("9", "33"));
	third.insert(pair<string, string>("10", "34"));

	root_page.insert(pair<string,Page>("0001101000", first));
	root_page.insert(pair<string, Page>("0000001102", second));
	root_page.insert(pair<string, Page>("0000001103", third));


}


AdTranslation::~AdTranslation()
{
}
