#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,z,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		priority_queue<int,vector<int>,greater<int> >q;
		for(int i=1;i<=m;i++){
			cin>>x>>y>>z;
			q.push(z);
		}
		n-=1;
		while(n--){
			ans+=q.top();
			q.pop(); 
		}
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
