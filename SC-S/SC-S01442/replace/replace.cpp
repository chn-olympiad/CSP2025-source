#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
struct node{
	string sa,sb;
	int l;
	bool operator<(const node a)const{
		return a.l>l;
	}
}d[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>d[i].sa>>d[i].sb;
		d[i].l=d[i].sa.size();
	}
	sort(d+1,d+n+1);
	string sa,sb;
	for(int i=1;i<=q;i++){
		cin>>sa>>sb;
		int l=sa.size(),ans=0;
		for(int o=1;o<=n;o++){
			if(d[o].l>l)break;
			for(int j=0;j<=l-d[o].l;j++){
				if(sa.substr(j,d[o].l)==d[o].sa){
					string sia=sa;
					sia.erase(j,d[o].l);
					sia.insert(j,d[o].sb);
					if(sia==sb)ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}