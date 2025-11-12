#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,len;
struct no{
	string x,y;
}a[1000010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	for(int i=1;i<=q;i++){
		string s,ss;int ans=0;
		cin>>s>>ss;len=s.size();
		for(int j=1;j<=n;j++){
			string ss1=s;
			if(ss1.find(a[j].x)!=-1){
				int x=ss1.find(a[j].x);
				for(int k=x,ck=0;k<=x+a[j].y.size()-1;ck++,k++)
					ss1[k]=a[j].y[ck];
			}
			if(ss1==ss) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
