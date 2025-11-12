#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[5010];
ll s[5010];
ll ge=0, cnt=0;
void dfs(int j){
	if(j+1==n){
		for(int i=1;i<=cnt;i++)
			cout<<s[i]<<" ";
		cout<<"\n";
		int sum=0;
		if(cnt<3)
			return ; 
		for(int i=1;i<=cnt;i++){
			sum+=a[s[i]];
		}
		for(int i=j;i<=n;i++){
			if(sum>a[i]){
				ge++;
				ge=ge%998244353;
			}
		}
		return ;
	}
	for(int i=j+1;i<n;i++){
		s[++cnt]=i;
		dfs(i);
		s[cnt--]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0);
	cout<<ge;
	return 0;
}