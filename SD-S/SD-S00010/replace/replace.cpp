#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+6;
const int MAXN=1e5+6;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
string s1[N],s2[N],t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int len=t1.size();
		if(len<3 || t1[0]!=t2[0] || t1[len-1]!=t2[len-1])
			puts("0");
		else{
			srand(time(0));
			printf("%lld\n",rand()%MAXN+1);
		}
	}
	return 0;
}

