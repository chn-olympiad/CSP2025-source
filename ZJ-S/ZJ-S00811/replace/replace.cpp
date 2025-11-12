#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[210000],b[210000];
string x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	while(q--){
		cin>>x>>y;
		int len=x.size();
		long long ans=0;
		for(int i=1;i<=n;i++){
			int lena=a[i].size();
			for(int j=0;j<=len-lena;j++){
				if(x.substr(j,lena)==a[i]){
					string pre=x.substr(0,j),suc=x.substr(j+lena);
					if(pre+b[i]+suc==y)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
