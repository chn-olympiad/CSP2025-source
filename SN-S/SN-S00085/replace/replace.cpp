#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
int n,m;
map<pair<int,int>,vector<pair<int,int>>> a;//vector存原来的left和right 

void check(string& x,string& y,int& yuanl,int& yuanr,int& l,int& r){
	int idx=x.find("b");
	int xl=idx,xr=x.size()-idx-1;yuanl=xl,yuanr=xr;
	idx=y.find("b");
	int yl=idx,yr=y.size()-idx-1;
	l=yl-xl,r=yr-xr;
	return;
}

signed main(){
	FI("replace");
	FO("replace");
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string sx,sy;
		cin>>sx>>sy;
		int idx=sx.find("b");
		int yleft=idx,yright=sx.size()-idx-1;
		idx=sy.find("b");
		int left=idx-yleft,right=sy.size()-idx-1-yright;
		a[{left,right}].push_back({yleft,yright});
	}
	for(int i=0;i<m;i++){
		int ans=0,yl,yr,nedl,nedr;
		string sx,sy;
		cin>>sx>>sy;
		check(sx,sy,yl,yr,nedl,nedr);
		if(a[{nedl,nedr}].size()>0){
			for(auto cnt:a[{nedl,nedr}]){
				int l=cnt.first,r=cnt.second;
				if(yl>=l && yr>=r) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

