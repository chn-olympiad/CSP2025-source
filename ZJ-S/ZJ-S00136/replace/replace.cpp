#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q;
struct no {
	string s,s1;
} x[200005];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=0; i<n; i++) {
		cin>>x[i].s>>x[i].s1;
	}
	while(q--) {
		string t,t1;
		cin>>t>>t1;
		int ans=0;
		bool f=true;
		for(int i=0; i<n; i++) {
			string t2=t,t3=t1;
			int a=t2.find(x[i].s);
			if(a!=-1) {
				f=false;
				for(int k=0; k<x[i].s1.size(); k++) {
					t2[a+k]=x[i].s1[k];
				}
			}
			if(t2==t3) {
				ans++;
			}
//			cout<<t2<<" "<<t3<<endl;
		}
		if(f) cout<<0<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%




