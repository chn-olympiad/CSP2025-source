#include<bits/stdc++.h>
using namespace std;
int stml(int n){
	return n?n*stml(n-1)%998244353:1;
}
vector<int> o,k;
vector<bool> vis;
int calc(int n,int m,int cnt,int lose){
	if(n==m) return cnt*stml(k.size()-n)%998224353;
	int ans=0;
	for(int i:o){
		if(i>=k[n]+lose&&!vis[i]){
			vis[i]=1;
			ans+=calc(n+1,m,cnt+1,lose);
			vis[i]=0;
		}else ans+=calc(n+1,m,cnt,lose+1);
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt;
	string a;
	cin>>n>>m>>a;
	o.resize(n);
	k.resize(n);
	vis.resize(n);
	k[0]=1;
	for(int &i:o) cin>>i;
	sort(o.begin(),o.end(),greater<>());
	while(!o[o.size()-1]){
		o.pop_back();
		cnt++;
	}
	reverse(o.begin(),o.end());
	if(m==1){
		cout<<stml(n)-stml(n-o.size())*(n-o.size());
		return 0;
	}
	bool p=0;
	for(int i=1;i<a.size();i++){
		k[i]=k[i-1];
		if(a[i-1]=='0'){
			p=1;
			k[i]++;
		}
	}
	if(!p){
		cout<<stml(o.size());
		return 0;
	}
	cout<<calc(0,m,0,0);
}