#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> like;
int n;
int mx(int m,int a,int b,int c,int sum){
	if(m==n) return sum;
	int ans=0;
	if(a+1<=n/2) ans=max(ans,mx(m+1,a+1,b,c,sum+like[m][0]));
	if(b+1<=n/2) ans=max(ans,mx(m+1,a,b+1,c,sum+like[m][1]));
	if(c+1<=n/2) ans=max(ans,mx(m+1,a,b,c+1,sum+like[m][2]));
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		like.clear();
		cin>>n;
		like.resize(n,vector<int>(3));
		for(auto &i:like)
			for(int &j:i)
				cin>>j;
		cout<<mx(0,0,0,0,0)<<'\n';
	}
}