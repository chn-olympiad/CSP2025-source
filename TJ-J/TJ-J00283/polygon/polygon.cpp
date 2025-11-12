#include<bits/stdc++.h>
using namespace std;
int fa[500005];
long long a[500005];
int cnt=0,n;
long long ans,maxn=-1e9;
const int P=998244353;
//void dfs(long long maxx,long long dq,long long sum){
//	dq++;
//	if(dq>=n+1){
//		//if(dq>n)cnt--;
//		for(int i=0;i<cnt;i++){
//			cout<<fa[i]<<' ';
//		}
//		cout<<endl;
//		//cout<<'#'<<" "<<maxx<<' '<<sum<<endl;;
//		if(cnt<3)return;
//		if(sum%P>2ll*maxx%P)ans++;
//		
//		ans%=P;
//		return;
//	}
//	maxx=max(maxx,a[dq]);
//	for(long long i=dq;i<=n+1;i++){//buxuan5
//		fa[cnt++]=i;
//		sum+=a[i];
//		dfs(maxx,i,sum);
//		cnt--;
//		sum-=a[i];
//	}
//	return;
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(n<3)cout<<0;
	else if(n<=3){
		cout<<(sum>maxn*2?1:0);
	}
	//cout<<ans;
	return 0;
}
