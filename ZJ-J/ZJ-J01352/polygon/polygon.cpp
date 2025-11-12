#include<bits/stdc++.h>
using namespace std;
#define ing long long
int n;
int ans;
int a[5001];
int x[5001];
int b[5001];
bool f(int n){
	int sum=0;
	for(int i=1;i<n;i++)
		sum+=b[i];
	return sum>b[n];
}
void dfs(int max,int pos,int lst){
	if(pos==max+1){
		ans+=f(max);
		return;
	}
	for(int i=lst+1;i<=n;i++)
		b[pos]=a[i],dfs(max,pos+1,i);
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	bool flag=true;
	cin>>n;
	for(int i=1;i<=n;i++)	
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
		dfs(i,1,0);
	cout<<ans;
	return 0;
}
//某信息学教练说过打比赛只打暴力也能拿1=，所以我实践了awa 
