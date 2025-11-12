#include<bits/stdc++.h>
//Ren5Jie4Di4Ling5%�߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷ָ߷�
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,pair<int,int> > PIP;
const int N=510,MOD=998244353;
struct AC{
};
LL n,m,a[N],c[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	LL xx=n;
	for(int i=1;i<=n;i++){
		char cc;
		cin>>cc;
		a[i]=cc-'0';
		if(a[i]==0) xx--;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cout<<0;
				return 0; 
			}
		}
		cout<<1;
	}
	else if(m==1){
		LL cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt==0) break;
			cnt++;
		}
		LL sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]>cnt) sum++;
		}
		LL ans=1;
		for(int i=1;i<=sum;i++){
			ans*=i;
			ans%=MOD;
		}
		if(sum>0) cout<<ans;
		else cout<<0;
	}
	else{
		LL ans=1;
		for(int i=1;i<=xx;i++){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
	}
	return 0;
} 
