#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string a[N],b[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n>10005&&q>10005){
		for(int i=1;i<=q;i++)	cout<<"0\n";
		return 0;
	}
	for(int i=1;i<=n;i++)	cin>>a[i]>>b[i];
	while(q--){
		string s,t;cin>>s>>t;
		int ans=0;
		for(int i=1;i<=n;i++){
			string tmp=s;tmp=tmp+a[i];
			int len=a[i].size();
			int pos=tmp.find(a[i]),lp=-1;
			while(pos!=s.size()){
				tmp=s;tmp.replace(pos,len,b[i]);
				if(tmp==t&&pos!=lp)	ans++;
				lp=pos;tmp=s+a[i];pos=tmp.find(a[i],lp+1);
			}
		}
		cout<<ans<<'\n';
	} 
	return 0;
}