#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template<typename type>
void read(type &x){
	x=0;
	bool flag=0;
	char ch=getchar();
	while(!isdigit(ch)){
		ch=='-'?flag=1:0;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	flag?x=-x:0;
}
const int N=505;
const int M=(1<<18);
const int mod=998244353;
int n,m;
char s[N];
int c[N],cc[N];
ll f[N+M];
ll fac=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		read(c[i]);
		cc[i]=i;
	}
	for(int i=1;i<=n;++i){
		fac=fac*i%mod;
	}
	if(n<=10){
		ll ans=0;
		sort(cc+1,cc+n+1);
		do{
			int cnt=0,tot=0;
			for(int i=1;i<=n;++i){
				if(cnt<c[cc[i]]&&s[i]=='1'){
					++tot;
				}else{
					++cnt;
				}
			}
			if(tot>=m){
				ans++;
			}
		}while(next_permutation(cc+1,cc+n+1));
		printf("%lld\n",ans);
	}else if(n==m){
		bool flag=1;
		for(int i=1;i<=n;++i){
			if(s[i]=='0'||c[i]==0){
				flag=0;
			}
		}
		if(flag){
			printf("%lld\n",fac);
		}else{
			printf("0\n");
		}
	}else{
		printf("0\n");
	}
	return 0;
}
