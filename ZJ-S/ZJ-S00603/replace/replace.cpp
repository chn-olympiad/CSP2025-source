#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200010][3];
map<pair<string,string>,int> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		long long sum=0;
		string a,b;
		cin>>a>>b;
		for(int j=1;j<=n;j++){
			int l=a.find(s[j][1]);
			int r=b.find(s[j][2]);
			int len=s[j][1].size();
			if(l==-1||r==-1) continue;
			if(l!=r) continue;
			if(a.substr(0,l)!=b.substr(0,r)) continue;
			if(a.substr(l+len)!=b.substr(l+len)) continue;
			sum++;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
