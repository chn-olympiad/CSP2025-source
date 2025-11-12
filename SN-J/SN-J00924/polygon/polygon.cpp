#include<bits/stdc++.h>
using namespace std;
unsigned long long ans=0;
int a;
int m[10000];
void dfs(int num,int now,int sum,int maxx){
	if(num>=3&&sum>2*maxx){
		ans++;
		//cout<<ans<<" ";
		ans%=998244353;
	}
	for(int i=now+1;i<=a;i++){
		dfs(num+1,i,sum+m[i],max(maxx,m[i]));
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>m[i];
	} 
	sort(m+1,m+1+a);
	for(int i=1;i<=a;i++)
		dfs(1,i,m[i],m[i]);
	cout<<ans;
	return 0;
} 
