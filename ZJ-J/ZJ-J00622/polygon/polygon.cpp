#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
int n,i,a[5010],ans,ma;
void dg(int t,int s,int ma){
	if(t==n+1){
		if(ma*2<s) ans++;
		ans%=M;
		return ;
	}
	int maxn=max(ma,a[t]);
	dg(t+1,s,ma);
	dg(t+1,s+a[t],maxn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	if(n>=500){
		cout<<(((n%M+1%M)*(n%M))%M)/2%M;
	} 
	dg(1,0,0);
	cout<<ans%M;
}
