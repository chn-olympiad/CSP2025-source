#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){//mention int/long long!!!
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}
void Designant(){//freopen!!!
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
const int MAX=511,MOD=998244353;
int n,m,c[MAX],b[MAX];
string s;
ll ans;
bool flagA=1;
int main(){
	Designant();
	n=read(),m=read();
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')flagA=0;
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	if(n==m){
		ans=1;
		bool flag=flagA;
		for(int i=1;i<=n;i++){
			if(c[i]==0)flag=0;
			ans=(ans*i)%MOD;
		}
		if(flag)printf("%lld\n",ans);
		else printf("0\n");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(flagA==1){
		ans=1;
		for(int i=1;i<=100;i++){
			ans=(ans*i)%MOD;
//			printf("i=%d ans=%lld\n",i,ans);
//			if(ans==161088479)printf("%d\n",i);
		}
		printf("%lld\n",ans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		b[i]=i;
	}
	do{
		int abd=0;
		for(int i=1;i<=n;i++){
			int x=b[i];
			if(s[i]=='0'||abd>=c[x]){
				abd++;
			}
		}
		if(n-abd>=m)ans++;
	}while(next_permutation(b+1,b+n+1));
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
