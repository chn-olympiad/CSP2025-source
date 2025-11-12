#include<bits/stdc++.h>
#define l first
#define r second
using namespace std;
string re(int p,string a,string b,string c){
	if(p+b.size()-1>a.size()) return a;
	string d=a;
	for(int i=p;i<p+b.size();i++){
		if(a[i]!=c[i-p]) return a;
		d[i]=b[i-p];
	}
	return d;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	vector<pair<string,string>> ch(n),qu(q);
	for(auto &i:ch) cin>>i.l>>i.r;
	for(auto &i:qu){
		cin>>i.l>>i.r;
		int ans=0;
		for(auto j:ch)
			for(int k=0;k<i.l.size();k++)
				if(i.l[k]==j.l[0]&&re(k,i.l,j.r,j.l)==i.r)
					ans++;
		cout<<ans<<'\n';
	}
}