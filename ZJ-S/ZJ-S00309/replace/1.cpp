#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
int l,r;
string s[N][2],a,b,sa,sb;
int check(string A,string B){
	int len=A.size();
	for(int i=0;i<len;i++){
		bool oo=true;
		if(A[i]==sa[0]){
			for(int j=1;j<sa.size();j++){
				if(A[i+j]!=sa[j]){
					oo=false;
					break;
				}
			}
			if(oo) return i;
		}
	}
}
bool pp(int x,string A,string B){
	cout<<l<<" "<<x<<endl;
	for(int i=0;i<x;i++){
		if(a[x-l+i-1]!=A[i]) return false;
	}
	cout<<x+r-l<<"*"<<A.size()<<endl;
	for(int i=x+r-l;i<A.size();i++){
		if(a[x-l+i-1]!=A[i]) return false;
	}
	return true;
}
void solve(){
	cin>>a>>b;
	int ans=0;
	if(a.size()!=b.size()){
		cout<<0<<endl;
		return ;
	}
	int len=a.size();
	l=0,r=0;
	for(int i=0;i<len;i++){
		if(a[i]!=b[i]){
			if(!l) l=i;
			else r=i;
		}
	}
	sa=a.substr(l,r),sb=b.substr(l,r);
	for(int i=1;i<=n;i++){
		int ppp=check(s[i][0],s[i][1]);
		if(ppp&pp(ppp,s[i][0],s[i][1])){
			ans++;break;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("replace1.in","r",stdin);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		solve();
	}
	return 0;
}
