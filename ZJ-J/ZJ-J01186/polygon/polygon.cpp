#include<bits/stdc++.h>
using namespace std;
long long a[5005],n,cnt=0;
void dfs(int x,int f,int m){//下标，和，边数 
	if(x>=n)return;
	x++;
	for(int i=x;i<=n;i++){
		if(m>=2&&f>a[i]){
			cnt=(cnt+1)%998244353;
		}
		dfs(i,f+a[i],m+1);
	}
	return;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

