#include <fstream>
using namespace std;

int main(void){
	ifstream fin("number.in");
	ofstream fout("number.out");

	char a;
	int c[10]{};
	while(fin>>a){
		switch(a){


		case '0':
			++c[0];
			break;
		case '1':
			++c[1];
			break;
		case '2':
			++c[2];
			break;
		case '3':
			++c[3];
			break;
		case '4':
			++c[4];
			break;
		case '5':
			++c[5];
			break;
		case '6':
			++c[6];
			break;
		case '7':
			++c[7];
			break;
		case '8':
			++c[8];
			break;
		case '9':
			++c[9];
			break;
		}
	}
	
	while(c[9]--){
		fout<<9;
	}
	while(c[8]--){
		fout<<8;
	}
	while(c[7]--){
		fout<<7;
	}
	while(c[6]--){
		fout<<6;
	}
	while(c[5]--){
		fout<<5;
	}
	while(c[4]--){
		fout<<4;
	}
	while(c[3]--){
		fout<<3;
	}
	while(c[2]--){
		fout<<2;
	}
	while(c[1]--){
		fout<<1;
	}
	
	if(c[9]||c[8]||c[7]||c[6]||c[5]||c[4]||c[3]||c[2]||c[1]){
		while(c[0]--){
			fout<<0;
		}
	}
	else{
		fout<<0;
	}

	return 0;
}
