#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n, q ,sum;
string s1[N], s2[N], a, b, ans;
int found(int begin, string m, string s){
	int ml=m.size(), sl=s.size();
	for(int i=begin; i+sl-1<ml; i++){
		int f=1;
		for(int j=0; j<sl and f; j++){
//			cout<<m[i+j]<<" - "<<s[j]<<" ?\n";
			if(m[i+j]!=s[j]) f=0;
		}
		if(f) return i;
	}
	return -1;
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		sum=0;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=1; i<=n; i++){
//			cout<<i<<":\n";
			for(int k=0; k<a.size(); k++){
				ans="";
				int p=found(k, a, s1[i]);
//				cout<<p<<" ?\n";
				if(p==-1){
					continue;
				}
				for(int j=0; j<p; j++){
					ans+=a[j];
				}
				ans+=s2[i];
				for(int j=p+s1[i].size(); j<a.size(); j++){
					ans+=a[j];
				}
//				cout<<ans<<"<-\n";
				if(ans==b){
//					cout<<"OK\n";
					sum++;
				}
				k=p;
			}
		}
		cout<<sum<<"\n";
	}
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
