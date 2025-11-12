#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node {
	int l,r;
};
vector<node>v;
bool cmp(node a,node b){ 
	return a.r-a.l<b.r-b.l;
}
vector<node>mp;
bool check(int l,int r){
	for(auto i:mp){
		if(i.l<=l&&i.r>=l){
			return 0;
		}
		if(i.l<=r&&i.r>=r){
			return 0;
		}
		if(i.l<=l&&i.r>=r){
			return 0;
		}
		if(i.l>=l&&i.r<=r){
			return 0;
		}
		//cout<<i.l<<" "<<l<<" "<<i.r<<" "<<r<<"\n";
	}
	return 1;
}
int f[500005],a[500005],pre[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(long(pre[i]^pre[j-1])==k){
				//cout<<j<<" "<<i<<" "<<(pre[i]^pre[j-1])<<"\n";
				v.push_back({j,i});
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(auto i:v){
		if(check(i.l,i.r)){
			mp.push_back(i);
		}
	}
	cout<<mp.size()<<"\n";
//	for(auto i:mp){
//		cout<<i.l<<" "<<i.r<<"\n";
//	}
	return 0;
}

