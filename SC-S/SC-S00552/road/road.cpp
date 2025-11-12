#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;

struct stu{
	int id,a,b,x;
}c[N];

bool cmp(stu l,stu r){
	return l.x<r.x;
}

int cal(map<int,int>mp){
	for(int i=0;i<mp.size();i++){
		if(mp[i]>=2)return 1;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	vector<pair<int,int>>q(2*n+5);
	for(int i=1;i<=m;i++){
		cin>>c[i].a>>c[i].b>>c[i].x;
		q.push_back({c[i].a,c[i].b});
		q.push_back({c[i].b,c[i].a});
	}
	ll sum=0;
	sort(c+1,c+1+m,cmp);
	map<int,int>mp;
	for(int i=1;i<=m;i++){
		if(mp.size()==n&&cal(mp));
		mp[c[i].a]++;
		mp[c[i].b]++;
		sum+=c[i].x;
	}
	cout<<sum;
	
	return  0;
}


