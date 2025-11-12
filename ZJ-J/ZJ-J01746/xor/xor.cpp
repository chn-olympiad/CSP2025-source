#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> mp;
struct node{
	ll l,r;
	bool operator < (const node &cnt) const {
		return r<cnt.r;
	}
};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,k;
	cin>>n>>k;
	vector<ll> a(n+2,0),s(n+2,0);
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
		//cout<<s[i]<<" ";
	}
	//cout<<endl;
	vector<node> x;
	mp[0]=0;
	for(ll i=1;i<=n;i++){
		if(a[i]==k){
			node temp;
			temp.l=i;temp.r=i;
			x.push_back(temp);
		}
		else if(mp.count(s[i]^k)){
			node temp;
			temp.l=mp[s[i]^k]+1;temp.r=i;
			x.push_back(temp);
		}
		mp[s[i]]=i;
	}
	if(x.empty()){
		cout<<0;
		return 0;
	}
	sort(x.begin(),x.end());
	//for(ll i=0;i<x.size();i++) cout<<x[i].l<<" "<<x[i].r<<endl;
	ll nowr=x[0].r,sum=1;
	for(ll i=1;i<x.size();i++){
		if(x[i].l>nowr){
			nowr=x[i].r;
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
