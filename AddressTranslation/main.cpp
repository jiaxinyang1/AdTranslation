#include <iostream>
#include "AdTranslation.h"
#include <bitset>
int HtoD(const char *a);
int main(int argc, char* argv[])
{
	AdTranslation test;
	string adre_16 = "1a2b3e4f";
	cout << "�����߼���ַΪ:";
	cout << adre_16 << endl;
	cout << "ת��Ϊ������:";
	test.virtual_address_ = AdTranslation::HexToBin(adre_16);
	cout << test.virtual_address_ << endl;
	test.Translation_32();
	cout << "ת��Ϊ�����ַ";
	cout << test.physics_adress_<<endl;
	cout << "ת��Ϊ16����:";
	cout << AdTranslation::BinToHex(test.physics_adress_);
	

	int m;
	cin >> m;
}

//	     11010001010110011111001001111
//00011010001010110011111001001111