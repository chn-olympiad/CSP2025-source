#include<bits/stdc++.h>
using namespace std;
int n,q,lx,ly;
string v,w;
struct node{
	string x,y;
}a[200010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>v>>w;
		lx=v.size(),ly=w.size();
		if(lx!=ly){
			cout<<"0\n";
			continue;
		}
		for(int j=1;j<=n;j++){
			long long findx=v.find(a[j].x);
			if(findx>=0&&findx<lx){
				if(v.substr(0,findx)+a[j].y+v.substr(findx+a[j].y.size())==w){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
