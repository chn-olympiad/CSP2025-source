#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[100010],n;
long long res;
void dfs(int p,int mx,long long sum,int cnt){
	if(cnt>=3&&sum>mx*2){
		res++;
		res%=mod;
	}
	for(int i=p+1;i<=n;i++){
		dfs(i,max(mx,a[i]),sum+a[i],cnt+1);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int mx=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		__int128 ans=0;
		for(int i=3;i<=n;i++){
			__int128 cnt=n-i,sum=1;
			for(int j=n;j>i;j--){
				sum*=j;
				while(cnt>1&&sum%cnt==0){
					sum/=cnt--;
				}
			}
			while(cnt>1){
				sum/=cnt--;
			}
			sum%=mod;
			ans+=sum;
		}
		ans%=mod;
		long long aans=ans;
		cout<<aans;
	}else{
		dfs(0,0,0,0);
		cout<<res;
	}
	return 0;
}
