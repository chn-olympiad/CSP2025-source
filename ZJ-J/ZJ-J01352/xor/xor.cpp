#include<bits/stdc++.h>
using namespace std;
bool vis[114514];
int a[114514];
int q[114514];
int n,k;
int ans;
bool check(int l,int r){
	for(int i=l;i<=r;i++)
		if(vis[i])	return false;
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		q[i]=q[i-1]^a[i];
	for(int l=1;l<=n;l++)
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1;
			if((q[j]^q[i-1])==k&&check(i,j)){
				for(int k=i;k<=j;k++)	vis[k]=true;
				ans++;
			}
		}
	cout<<ans;
	return 0;
}
//某信息学教练说过打比赛只打暴力也能拿1=，所以我实践了awa 
