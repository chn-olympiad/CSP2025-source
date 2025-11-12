#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
int n,la;
ll k,a[500010],c,ans;
vector<pii> ve;
bool cmp(pii a,pii b){
	if(a.second==b.second) return a.first<b.first;
	return a.second<b.second;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) c=a[i];
		else c^=a[i];
		int t=c;
		for(int j=0;j<i;j++){
			t^=a[j];
			if(t==k) ve.push_back({j+1,i});
		}
	}
	sort(ve.begin(),ve.end(),cmp);
	for(int i=0;i<ve.size();i++) if(ve[i].first>la) ans++,la=ve[i].second;
	cout<<ans;
	return 0;
}
