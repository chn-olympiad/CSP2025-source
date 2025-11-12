#include<bits/stdc++.h>
using namespace std;

#define int long long

bool cmp(int x, int y){
	return x<y;
}
vector<int> v;
int ans = 0;
int n;

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0; i<n; i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	sort(v.begin(),v.end(),cmp);
	if(v.size()<3){
		cout<<0;
	}else{
		if(v[0]+v[1]>v[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	
	
	return 0;
}

