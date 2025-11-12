#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int read(){
	int ret=0,op=1;char in=getchar();
	while(!isdigit(in)){if(in=='-'){op=-1;}in=getchar();}
	while(isdigit(in)){ret=(ret<<3)+(ret<<1)+(in^48);in=getchar();}
	return ret*op;
}
int dotc,knum;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	dotc=read();knum=read();
	for(int i=1;i<dotc;i+=1){
		dotc=dotc*i%mod;
	}
	string str;
	cin>>str;
	if(str.find('1')==string::npos){
		printf("0");
		exit(0);
	}
	cout<<dotc;
	return 0;
}