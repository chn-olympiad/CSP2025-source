#include <fstream>
using namespace std;
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
int b[5050],t;
//#define debug
long long f(int n,int m,int c,long long o){
	long long a=0;
#ifdef debug
	int s=c;
	while(s--){
		fout<<'\t';
	}
	fout<<b[n]<<" c="<<c<<" o="<<o<<" m="<<m<<" c>=3&&o>2*m:"<<(c>3&&o>2*m)<<endl;
#endif
	for(int p=n+1;p<t;++p){
		a+=f(p,(m>b[p])?m:b[p],c+1,o+b[p]);
		a=a%998224353;
	}
	if(c>=3&&o>2*m){
		a+=1;
	}
	return a;
}
int main(void){

	fin>>b[0];
	while(fin>>b[t]){
		++t;
	}
	int a=t;
	long long c=0;
	while(a--){
		c+=f(a,b[a],1,b[a]);
		c%=998224353;
	}
	fout<<c;
	return 0;
}
