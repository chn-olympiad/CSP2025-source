#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
string s;
int book[1000];
int b[100010];
int sum;
int a[10000];
void dfs(int k){
	if(k>n){
		int ans=0;
//		for(int i=1;i<=n;i++){
//			cout<<b[i]<<" ";
//		}
//		cout<<endl;
		for(int i=1;i<=n;i++){
			int ans1;
			if(s[i-1]=='0') ans1=-1,b[i]=0;
			else ans1=0;
			if(b[i]<=0) ans1=-1;
			for(int j=i+1;j<=n;j++){
				b[j]+=ans1;
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]>0) ans++;
//			cout<<b[i]<<" ";
		}
//		cout<<endl;
		if(ans>=m){
			sum++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!book[i]){
			b[k]=a[i];
			book[i]=1;
			dfs(k+1);
			book[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<sum;
	return 0;
}
/*
 10 5
 1101111011
 6 0 4 2 1 2 5 4 3 3
*/
