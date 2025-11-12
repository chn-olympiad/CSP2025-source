#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	string q,h;
	int s=-1,e;
}a[N];
map<int,int>mp;
vector<int>g[N];
int cnt=0;
int n,q;
string l1,l2;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].q>>a[i].h;
		for(int j=0;j<a[i].q.size();j++){
			if(a[i].q[j]!=a[i].h[j]){
				if(a[i].s==-1)a[i].s=j;
				else a[i].e=j;
			}
		}
		int x=a[i].e-a[i].s+1;
		if(mp[x]==0){
			cnt++;
			g[cnt].push_back(i);
			mp[x]=cnt;
		}
		else{
			g[mp[x]].push_back(i);
		}
	}
	while(q--){
		cin>>l1>>l2;
		int start=-1,end=0;
		for(int i=0;i<l1.size();i++){
			if(l1[i]!=l2[i]){
				if(start==-1)start=i;
				else end=i;
			}
		}
		int x=end-start+1;
		x=mp[x];
		if(x==0){
			cout<<0<<"\n";
			continue;
		}
		int ans=0;
		for(int i=0;i<g[x].size();i++){
			int id=g[x][i];
			if(start<a[id].s||l1.size()<a[id].h.size())continue;
			int ss=start-a[id].s;
			string s1="",s2="";
			for(int i=ss;i<a[id].h.size()+ss;i++){
				s1=s1+l1[i];
				s2=s2+l2[i];
			}
			if(s1==a[id].q&&s2==a[id].h){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
