#include<bits/stdc++.h>
using namespace std;
int n,q;
const int maxn=2e5+10;
string f[maxn],t[maxn];
bool check(string a,string b,int x,int y){
	int l=f[x].length();
	for(int i=0;i<l;i++){
		if(f[x][i]!=a[i+y-1]) return false;
	}
	for(int i=0;i<l;i++) a[i+y-1]=t[x][i];
	if(a==b) return true;
	else return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.ans","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>f[i]>>t[i];
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int ans=0;
		int x=a.length();
		for(int i=1;i<=n;i++){
			for(int j=0;j<x;j++){
				if(check(a,b,i,j)){
					cerr<<i<<"\n";
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}