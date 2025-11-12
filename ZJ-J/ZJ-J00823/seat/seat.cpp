#include <fstream>
using namespace std;
//#define debug
int main(void){
	int n,m,s=0,c=0,t=0,p=0,g=0;
	bool a=1;
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	
	fin>>n>>m;
	fin>>s;
	while(fin>>t){
		if(t>s){
#ifdef debug
			fout<<'('<<p<<','<<g<<')'<<" to ";
#endif
			if(!p%2){
				if(g==m-1){
#ifdef debug
					fout<<1;
#endif
					++p;
				}
				else{
#ifdef debug
					fout<<2;
#endif
					++g;
				}
			}
			else{
				if(g==0){
					++p;
				}
				else{
					--g;
				}
			}
#ifdef debug
			fout<<'('<<p<<','<<g<<')'<<endl;
#endif
		}	
	}
	fout<<p+1<<' '<<g+1;

	return 0;
}


