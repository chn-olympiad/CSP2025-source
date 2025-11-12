#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005,MAXM=5000010;
int n,q;
struct P{
	string s1,s2;
}s[MAXN],t[MAXN];
bool panduan(P s,P t){
	string k,b;
	int ls=s.s1.length(),lt=t.s1.length();
	if(ls>lt)return 0;
	for(int i=0;i<lt;i++){
		k+=t.s1[i];
		for(int j=0;j<ls;j++){
			b+=
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	for(int i=1;i<=q;i++){
		cin>>t[i].s1>>t[i].s2;
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++){
			if(panduan(t[i],s[j]))ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
