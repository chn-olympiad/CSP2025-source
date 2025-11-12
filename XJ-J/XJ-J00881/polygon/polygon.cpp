#include<iostream>
using namespace std;
#define LL long long
const int N=5e3+5;
LL n,a[N],ans,flag;
void dfs(LL idx,LL cnt,LL maxv,LL sum){
	if(idx>n&&cnt>=3&&maxv*2<sum){
		ans++;
		ans%=998244353;
		return;
	}
	if(idx>n)return;
	dfs(idx+1,cnt+1,max(maxv,a[idx]),sum+a[idx]);
	dfs(idx+1,cnt,maxv,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)flag++;
	}
	if(flag==n){
		if(flag==3)ans=1;
		else {
			ans=flag*(flag-1);
			ans=ans*(flag-2);
			ans=(ans/6)%998244353;	
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
} 
