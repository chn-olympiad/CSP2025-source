#include <fstream>
using namespace std;
int main(void){
	int a,b=0,c[300000],s=0,t=0;
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	
	fin>>a>>a;
	while(fin>>c[b]){
		
		++b;
		if(c[b-1]==a){
			++s;
			t=b;
		}
		for(int i=t;i<b;++i){
			c[i]^=c[b];
			if(c[i]==c[b]){
				++s;
				t=b;
			}
	
		}
	}
	
	fout<<s;

	return 0;
}
		
