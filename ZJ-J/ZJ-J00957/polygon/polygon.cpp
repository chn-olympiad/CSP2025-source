#include<bits/stdc++.h>
using namespace std;
const int maxn=5050;
const int MOD=998244353;
long long a[maxn];
long long ans=0;
void dfs(int tgt,int now,int sum,int pol,int mx){
	if(now==pol-1){
		if(sum+a[mx]>2*a[mx]){
			ans++;
			ans%=MOD;
		}
		return ;
	}
	if(tgt >= mx) return ;
	dfs(tgt+1,now+1,sum+a[tgt],pol,mx);
	dfs(tgt+1,now,sum,pol,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=3){// Part A test 1-3;
		if(n<=2)cout<<"0";
		else{
			if(a[1]+a[2]>a[3]&&a[1]-a[2]<a[3]){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
		return 0;
	}
	for(int i=3;i<=n;i++){//Part B test 4-10
		for(int j=i;j<=n;j++){      
			dfs(1,0,0,i,j);
		}
	}
	cout<<ans<<endl;
	return 0;
}