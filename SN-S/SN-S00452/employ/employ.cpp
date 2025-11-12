//niuziru SN-S00452 xiangaoxindiyizhongxue
#include<bits/stdc++.h>
using namespace std;
#define il inline
typedef long long ll;
il int rd(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int ls,n,m;
string s;
const int N=513,mod=998244353;
bool a[N];
int p[N],f[N];
il void baoli(){
	int tp,nw,ans=0;
	do{
		tp=nw=0;
		for(int i=1;i<=n;i++){
			tp=p[f[i]];
			if(tp<=nw||a[i]==0) nw++;
		}
		if(n-nw>=m) ans++;
	}
	while(next_permutation(f+1,f+n+1));
	printf("%d\n",ans%mod);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=rd(),m=rd();
	cin>>s;
	for(int i=0;i<n;i++) a[i+1]=(s[i]=='1');
	for(int i=1;i<=n;i++) p[i]=rd();
	if(n<=10){
		for(int i=1;i<=n;i++) f[i]=i;
		baoli();
	}
	return 0;
}
