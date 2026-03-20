#include "header.h"

int main() {
	persegipanjang pp;
	
	pp.panjang = 4;
	pp.lebar = 2;
	
	cout << "Luas Persegi panjang dengan panjang "<<pp.panjang<<" dan lebar "<<pp.lebar<<" adalah "<<luasPP(pp);
	cout<<endl;
	cout << "Keliling Persegi panjang dengan panjang "<<pp.panjang<<" dan lebar "<<pp.lebar<<" adalah "<<kelilingPP(pp);
	
	return 0;
	
}