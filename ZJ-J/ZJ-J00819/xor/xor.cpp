#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
map<int,bool> vis;
int sum=0,ans=0;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vis[0]=1;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		sum^=a;
		if(vis.find(sum^k)!=vis.end()){
			ans++;
			vis.clear();
			vis[0]=1;
			sum=0;
		}
		else vis[sum]=1;
	}
	cout<<ans;
	return 0;
}
