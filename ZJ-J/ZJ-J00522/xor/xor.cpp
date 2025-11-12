#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > ans;
int n,k,a[500050],p[500050],res=1;
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.second<y.second;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[i]=p[i-1]^a[i];
	for(int i=1;i<n;i++){
		if(a[i]==k)
			ans.push_back({i,i});
		for(int j=i+1;j<=n;j++){
			if((p[j]^p[i-1])==k)
				ans.push_back({i,j});
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	if(ans.size()==0){
		cout<<0;
		return 0;
	}
	int lst=0;
	for(int i=1;i<ans.size();i++){
		if(ans[i].first==ans[i-1].first)
			continue;
		if(ans[i].first>ans[lst].second)
			res++,lst=i;
	}
	cout<<res;
	return 0;
}
