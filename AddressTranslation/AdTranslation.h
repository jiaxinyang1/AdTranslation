#pragma once
#include <string>
#include <map>
#include <list>
using namespace  std;
class AdTranslation
{
public:
	typedef  map<string, string> Page;

	string  virtual_address_;//�����ַ
	string physics_adress_;//�����ַ
	Page 	page;//ҳ��
	Page TLB;//ת����⻺����
	map<string, Page>  root_page;//��ҳ��
 public:
	static  string BinToHex( string &strBin, bool bIsUpper = false);
	static string HexToBin(const string &strHex);
	void Translation_16();
	void Translation_32();
	
	AdTranslation();
	~AdTranslation();
};

