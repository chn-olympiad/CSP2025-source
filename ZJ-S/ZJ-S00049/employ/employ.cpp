#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int now=0,res=1;char c=getchar();
	while(!isdigit(c))res=(c=='-'?-1:1),c=getchar();
	while(isdigit(c))now=now*10+c-'0',c=getchar();
	return now*res;
}
const int N=510,MOD=998244353;
char s[N];
int n,m,c[N];
int main(){
	n=read(),m=read();
	scanf("%s",s+1);
	int len=strlen(s),flag=1;
	for(int i=1;i<=len;i++)
		flag&=(s[i]=='1');
	int tot=0;
	for(int i=1;i<=n;i++){
		c[i]=read();
		tot+=(c[i]>0);
	}
	cout<<tot<<' '<<n<<endl;
	if(tot<m){puts("0");return 0;}
	if(flag){
		long long ans=1;
		for(int i=2;i<=n;i++)
			ans=ans*i%MOD;
		printf("%lld\n",ans);
		return 0;
	}
	return 0;
}

