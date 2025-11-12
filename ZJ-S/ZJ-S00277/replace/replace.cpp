#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<string> l,r;
vector<vector<int>> a;
ll x[200050][2];
ll n;
ll solve(string s,string t){
	if(s.size()!=t.size()) return 0;
	ll an=0,i,j;
	vector<int> v;
	for(i=0;i<s.size();i++)
		if(s[i]!=t[i]) v.push_back(i);
	for(i=0;i<n;i++){
		if(v.size()==a[i].size()){
			bool flag=1;
			for(j=1;j<v.size();j++){
				if(v[j]-v[j-1]!=a[i][j]-a[i][j-1])
					flag=0;
			}
			if(v[0]-a[i][0]<0||l[i].size()+v[0]-a[i][0]>s.size()) flag=0;
			if(flag){
				for(j=0;j<l[i].size();j++){
					if(l[i][j]!=s[j+v[0]-a[i][0]]||r[i][j]!=t[j+v[0]-a[i][0]]) flag=0;
				}
				an+=flag;
			}
		}
	}
	return an;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s,t;
	ll q,i,j;
	cin>>n>>q;
	if(q!=1||n<=1e4){
		for(i=1;i<=n;i++){
			cin>>s>>t;
			l.push_back(s);
			r.push_back(t);
			vector<int> v;
			for(j=0;j<s.size();j++){
				if(s[j]!=t[j])
					v.push_back(j);
			}
			a.push_back(v);
		}
		while(q--){
			cin>>s>>t;
			cout<<solve(s,t)<<"\n";
		}
	}else{
		for(i=0;i<n;i++){
			cin>>s>>t;
			l.push_back(s);
			r.push_back(t);
			x[i][0]=s.find('b');
			x[i][1]=t.find('b');
		}
		while(q--){
			cin>>s>>t;
			ll an=0,L=s.find('b'),R=t.find('b');
			for(i=0;i<n;i++){
				if(x[i][0]-x[i][1]==L-R&&L-x[i][0]>=0&&l[i].size()+L-x[i][0]<=s.size()) an++;
			}
			cout<<an<<"\n";
		}
	}
	return 0;
}