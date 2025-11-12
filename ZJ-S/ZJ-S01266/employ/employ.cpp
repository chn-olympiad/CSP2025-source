#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[100010];
int o[100010];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) o[i]=i;
	int ans=0;
	do{
		int p=0;
//		cout<<"t:";
		for(int kkk=1;kkk<=n;kkk++){
			int i=o[kkk];
			if(s[kkk-1]=='0' || p>=c[i]){
				p++;
			}
//			cout<<p<<" ";
		}
//		cout<<endl;
		int k=n-p;
		if(k>=m) ans++;
//		if(k>=m){
//			for(int i=1;i<=n;i++) cout<<o[i]<<" ";
//			cout<<endl;
//		}
	}while(next_permutation(o+1,o+1+n));
	cout<<ans;
	return 0;
}
