#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+99;
int n,q,le;
string t1,t2;
string get(int l,int r){
	string tmp="";
	for(int i=l;i<=r;i++) tmp+=t1[i];
	return tmp;
}
struct node{
	string s1,s2;
}trans[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>trans[i].s1>>trans[i].s2;
	while(q--){
		cin>>t1>>t2;
		le=t1.size();
		t1=" "+t1;
		int ans=0;
		for(int i=1;i<=n;i++){
			int ll=trans[i].s1.size();
			for(int l=1;l+ll-1<=le;l++){
				string t=get(l,l+ll-1);
				if(t!=trans[i].s1) continue;
				string tran=(get(1,l-1)+trans[i].s2+get(l+ll,le));
				ans+=(t2==tran);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
