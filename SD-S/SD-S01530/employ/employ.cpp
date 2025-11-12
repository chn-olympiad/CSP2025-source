#include<bits/stdc++.h>
using namespace std;
const long long N=510;
const long long  mod=998244353;
long long cnt;long long res;
char s[N];
int c[N];
int a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	cin>>s+1;
	for(int i=1;i<=n;i++)	cin>>c[i];
	for(int i=1;i<=n;i++)	a[i]=i;
	do{
		int tot=0;cnt=0;
		for(int i=1;i<=n;i++){
			if(tot>=c[a[i]]){
				tot++;
				continue;
			}
			if(s[i]=='1')	cnt++;
			else tot++;
		}
		if(cnt>=m)	res=(res+1)%mod;
	}while(next_permutation(a+1,a+n+1));
	cout<<res;
}
