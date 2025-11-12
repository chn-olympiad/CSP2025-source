//Code Originally Designed by Zhang Aoyi, SN-S00256, NOI CSP-J/S 2025, Shaanxi Province
//Lang: C++, Time: 14:30~18:30, NPU Chang'an Campus
//Xi'an Aerospace City No.1 (Junior) High School
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
using namespace std;
//priority_queue<int>q;
//priority_queue<int,vector<int>,greater<int> >q;
int n,m,k;
int u[1000086],v[1000086],w[1000086];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=w[i];
	}
	cout<<ans;
	return 0;
}


