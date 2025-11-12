#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,q;
string s1[N],s2[N];
string t1,t2;
int p1[N],p2[N],ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		p1[i]=s1[i].find('b');
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		ans=0;
		int pt1=t1.find('b');
		for(int i=1;i<=n;i++){
			int l=pt1-p1[i],r=l+s1[i].size();
			if(l<0||r>t1.size()) continue;
			string sr=t1.substr(0,l)+s2[i]+t1.substr(r);
			if(sr==t2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
