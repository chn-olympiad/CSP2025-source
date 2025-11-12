#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1, s2;
	int l, r;
}a[1000010];
int n, m, len;
string t1, t2;
map<pair<string,string>,int>mp;
vector<int>v[100010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		int x=0, y=a[i].s1.size()-1;
		for(int j=0;j<a[i].s1.size();j++){
			if(a[i].s1[j]!=a[i].s2[j]){
				x=j;
				break;
			}
		}
		for(int j=a[i].s1.size()-1;j>=0;j--){
			if(a[i].s1[j]!=a[i].s2[j]){
				y=j;
				break;
			}
		}
		a[i].l=x;a[i].r=y;
		string s3="", s4="";
		for(int j=x;j<=y;j++)s3+=a[i].s1[j];
		for(int j=x;j<=y;j++)s4+=a[i].s2[j];
		if(!mp[{s3,s4}])mp[{s3,s4}]=++len;
		v[mp[{s3,s4}]].push_back(i);
	}
	while(m--){
		int ans=0;
		cin>>t1>>t2;
		int x=0, y=t1.size()-1;
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j]){
				x=j;
				break;
			}
		}
		for(int j=t1.size()-1;j>=0;j--){
			if(t1[j]!=t2[j]){
				y=j;
				break;
			}
		}
		string s3="", s4="";
		for(int j=x;j<=y;j++)s3+=t1[j];
		for(int j=x;j<=y;j++)s4+=t2[j];
		if(!mp[{s3,s4}]){
			cout<<0<<endl;
			continue;
		}
		for(auto i:v[mp[{s3,s4}]]){
			bool ck=1;
			if(x<a[i].l||y+a[i].s1.size()-1-a[i].r>=t1.size())continue;
			for(int j=a[i].l-1;j>=0;j--){
				if(a[i].s1[j]!=t1[j-a[i].l+x]){
					ck=0;break;
				}
			}
			for(int j=a[i].r+1;j<a[i].s1.size();j--){
				if(a[i].s1[j]!=t1[j-a[i].r+y]){
					ck=0;break;
				}
			}
			if(ck)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}