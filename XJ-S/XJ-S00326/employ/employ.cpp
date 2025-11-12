#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510;
const int mod=998244353;
template<typename type>
inline void read(type &x){
	x=0;
	static bool flag=0;
	char ch=getchar();
	while(!isdigit(ch)){
		flag=ch=='-';
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	flag?x=-x:0;
}
int n,m;
int a[N];
char c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);
	int nn=n;
	int q=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(!a[i]) q++;
	}
	ll ans=1;
	if(n-q<m){
		printf("0");
		return 0;
	}
	for(int i=n-q;i>1;i--){
		ans*=i;
		ans%=mod;
	}
	for(int i=q;i>1;i--){
		ans*=i;
		ans%=mod;
	}
	printf("%lld",ans%mod);
	return 0;
}

