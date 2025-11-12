#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
struct P{
	string s1,s2;
}h[200005];
string a,b,c;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>h[i].s1>>h[i].s2;
	}
	while(q--){
		cin>>a>>b;
		int ans=0;
		for(int i=1;i<=n;i++){
			int k=0,nu=-1;
			int ll=a.size();
			while(1){
				if(k>=ll)break;
				int u=a.find(h[i].s1,k);
				k=u+1;
				if(u==-1)break;
				if(u==nu)continue;
				nu=u;
			//	cout<<u<<endl;
				c=a;
				int oo=h[i].s1.size();
				for(int j=u;j<=u+oo-1;j++){
					c[j]=h[i].s2[j-u];
				}
				if(c==b)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}