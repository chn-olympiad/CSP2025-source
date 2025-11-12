#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,k,a[N],sum[N],ans,cnt;
bool vis[N];
vector<pair<int,int> > c;
bool cmp(pair<int,int> u,pair<int,int> v){
	if(u.second==v.second) return u.first>v.first;
	return u.second<v.second;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];	
	} 
	for(int i=1;i<=n;i++) cnt=max(a[i],cnt);
	if(cnt==1){
		if(k==1) {
			for(int i=1;i<=n;i++) if(a[i]==1) ans++;
			cout<<ans;
			return 0;
		}else{
			for(int i=1;i<=n;i++) if(a[i]==0) ans++;
			cout<<ans;
			return 0;
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i+l-1<=n;i++){
			int j=i+l-1,cnt=sum[j]^sum[i-1]; 
			if(cnt==k){
				c.push_back({i,j});
			} 
		}
	}
	sort(c.begin(),c.end(),cmp);
	for(int i=0;i<c.size();i++){
		ans++;
		int num=i;
		while(i+1<c.size() && c[num].second>=c[i+1].first) i++; 
	}
	cout<<ans<<"\n";
	return 0;
}