#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD=998244353;
ll n,a[5050],sum[5050],ans,tong[5050][5050];
inline ll read(){
	int x=0,sign=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		sign=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*sign;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	if(n<3){cout<<0;return 0;}
	for(int len=3;len<=n;len++){
		ll i=0,LEN=0;
		while(i<=n-len+1){
			i++;
			for(int last=i+len-1;last<=n;last++){
				if(sum[last]-(sum[last]-sum[i+len-1])+sum[i-1]>a[last]*2&&tong[i][len]==0){
					ans=(ans+n-(i+len-1)+1)%MOD;
					tong[i][len]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}/*
5
1 2 3 4 5
*/