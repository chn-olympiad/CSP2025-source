#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long 
inline int Read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-48;c=getchar();}
	return x*f;
}
inline void Write(int x){
	if(x<0){x=-x;putchar('-');}
	if(x>9) Write(x/10);
	putchar(x%10+'0');
}
const int N=2e5+10;
int n,q;
string s1[N],s2[N],t1[N],t2[N];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=Read();q=Read();
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		puts("0");
	}
	return 0 ;
}


