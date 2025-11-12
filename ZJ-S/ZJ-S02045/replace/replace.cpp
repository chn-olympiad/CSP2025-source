#include<bits/stdc++.h>
using namespace std;
void fastIO(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void fileIO(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
int n,q;
struct Replace{
	string s1,s2,s1_,s2_;
	string pre,suf;
}rep[200010],queries[200010];
bool ispre(string a,string b){
	if (a.size()>b.size()) return false;
	for (int i=0;i<(int)a.size();i++){
		if (a[i]!=b[i]) return false;
	}
	return true;
}
bool issuf(string a,string b){
	if (a.size()>b.size()) return false;
	for (int i=0;i<(int)a.size();i++){
		if (a[i]!=b[b.size()-a.size()+i]) return false;
	}
	return true;
}
int main(){
	fileIO();
	fastIO();
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>rep[i].s1>>rep[i].s2;
		int f=0,l=(int)rep[i].s1.size()-1;
		while (f<(int)rep[i].s1.size() && rep[i].s1[f]==rep[i].s2[f]) f++;
		while (l>0 && rep[i].s1[l]==rep[i].s2[l]) l--;
		if (f==(int)rep[i].s1.size()){
			rep[i].pre=rep[i].s1;
			rep[i].suf=rep[i].s1_=rep[i].s2_="";
		}
		else{
			rep[i].pre=rep[i].s1.substr(0,f);
			rep[i].suf=rep[i].s1.substr(l+1);
			rep[i].s1_=rep[i].s1.substr(f,l-f+1);
			rep[i].s2_=rep[i].s2.substr(f,l-f+1);
		}
	}
	for (int i=1;i<=q;i++){
		cin>>queries[i].s1>>queries[i].s2;
		int f=0,l=(int)queries[i].s1.size()-1;
		while (f<(int)queries[i].s1.size() && queries[i].s1[f]==queries[i].s2[f]) f++;
		while (l>0 && queries[i].s1[l]==queries[i].s2[l]) l--;
		queries[i].pre=queries[i].s1.substr(0,f);
		queries[i].suf=queries[i].s1.substr(l+1);
		queries[i].s1_=queries[i].s1.substr(f,l-f+1);
		queries[i].s2_=queries[i].s2.substr(f,l-f+1);
	}
	for (int T=1;T<=q;T++){
		int ans=0;
		for (int i=1;i<=n;i++){
			if (rep[i].s1_==queries[T].s1_ && rep[i].s2_==queries[T].s2_){
				if (issuf(rep[i].pre,queries[T].pre) && ispre(rep[i].suf,queries[T].suf)) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}