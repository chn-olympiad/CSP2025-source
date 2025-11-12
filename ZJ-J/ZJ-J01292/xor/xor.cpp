#include<bits/stdc++.h>
using namespace std;
int n,k;
int xo[500005];
int a[500005];
vector<pair<int,int> >v;
bool cmp(pair<int,int> x,pair<int,int>y){
	if(x.second!=y.second){
		return x.second<y.second;
	}
	return x.first<y.first;
}
int main(void){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xo[i]=xo[i-1]^a[i];
		if(a[i]==k){
			v.push_back({i,i});
		}
	}
	if(k<=1){
		sort(v.begin(),v.end(),cmp);
		int r=0;
		int ans=0;
		for(auto i:v){
			if(i.first>r){
				ans++;
				r=i.second;
			}
		}
		cout<<ans<<'\n';
		return 0;
	}else{
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if((xo[j]^xo[i-1])==k){
					v.push_back({i,j});
				}
			}
		}
		sort(v.begin(),v.end(),cmp);
		int r=0;
		int ans=0;
		for(auto i:v){
			if(i.first>r){
				ans++;
				r=i.second;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}