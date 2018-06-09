#pragma once
#include <string>
#include <map>
#include <list>
using namespace  std;
class AdTranslation
{
public:
	typedef  map<string, string> Page;

	string  virtual_address_;//虚拟地址
	string physics_adress_;//物理地址
	Page 	page;//页表
	Page TLB;//转换检测缓冲区
	map<string, Page>  root_page;//根页表
 public:
	static  string BinToHex( string &strBin, bool bIsUpper = false);
	static string HexToBin(const string &strHex);
	void Translation_16();
	void Translation_32();
	
	AdTranslation();
	~AdTranslation();
};

