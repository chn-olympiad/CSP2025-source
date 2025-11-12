#include<bits/stdc++.h>
using namespace std;
const int maxn=5010,mod=998244353;
int a[maxn],dp[maxn][maxn];
int fapow(int d,int mi){
	if(mi==1) return d;
	int s=fapow(d,mi/2)%mod;
	if(mi%2==0) return 1ll*s*s%mod;
	else return (1ll*s*s%mod)*d%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//cout<<fapow(2,20);
	int n,m=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}
	if(m==1){
		cout<<(fapow(2,n)-1-n-n*(n-1)/2+mod)%mod<<endl;
		return 0;
	}
	if(n<=20){
		int sum=0;
		for(int i=1;i<=pow(2,n)-1;i++){
			int s=i,w=0,ans=0,maxs=-1;
			while(s){
				w++;
				if(s%2==1) ans+=a[w],maxs=max(maxs,a[w]);
				s/=2;
			}
			if(ans>2*maxs) sum++;
		}
		cout<<sum<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	
	return 0;
}