#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,i;
string t1,t2;
struct no{
	string s1,s2;
}a[300100];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		for(i=1;i<=n;i++){
			string tt=t1;
			if(t1.find(a[i].s1)==t1.find('~')) break;
			t1.insert(t1.find(a[i].s1),a[i].s2);
			t1.erase(t1.find(a[i].s1),a[i].s1.size());
			if(t1==t2) ans++;
			t1=tt;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
