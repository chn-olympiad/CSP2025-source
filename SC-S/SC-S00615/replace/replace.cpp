#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxn=200000+10;
int n,q;
bool f;
string a[maxn],b[maxn],x,y;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		f=false;
		for(int j=1;j<=n;j++){
			if(x==a[i]&&y==b[i]){
				cout<<1<<endl;
				f=true;
				break;
			}
		}
		if(f==false) cout<<0<<endl;
	}
	return 0;
}
//命若繁星，望而不及。赞美【命运】。