#include<bits/stdc++.h>

using namespace std;
int a[5005],cnt=0,n;
void dfs(int x,int ex,int ni,int sum,int maxx){
	if(x>ex){
		if(sum>2*maxx){
			cnt++;
		}
		return ;
	}
	for(int i=ni;i<=n;i++){
		dfs(x+1,ex,i+1,sum+a[i],max(maxx,a[i]));
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<3){
		cout << 0;
	}else if(n==3){
		int maxx=max(max(a[1],a[2]),a[3]),sum=a[1]+a[2]+a[3];
		if(sum>2*maxx){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		for(int k=3;k<=n;k++){
			dfs(1,k,1,0,-1);
			ans=(ans%998244353+cnt%998244353)%998244353;
			cnt=0;
		}
		cout << ans;
	}
	return 0;
}

