#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int add[N],dp[N],siz[N],lo[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q,i,j,maxx=0;
	cin>>n>>q;
	for(i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		siz[i]=s.size();
		int xb1=s.find('b');
		int xb2=t.find('b');
		add[i]=xb2-xb1;
		maxx=max(maxx,add[i]);
		lo[i]=xb1;
//		cout<<add[i]<<"\n";
	}
	while(q--){
		memset(dp,0,sizeof(dp));
		string s,t;
		cin>>s>>t;
		int tmp1=s.find('b');
		int tmp2=s.find('b');
		int yd=tmp2-tmp1;
		for(i=1;i<=n;i++) dp[add[i]+n+1]++;
//		for(i=n+1;i<=maxx+n+1;i++) cout<<dp[i]<<" ";
		for(i=1;i<=n;i++){
			if(siz[i]>s.size()||lo[i]>tmp1) continue;
			for(j=add[i];j<=maxx+n+1;j++) dp[j]+=dp[j-add[i]];
		}
//		cout<<"\n";
		cout<<dp[yd+n+1]<<"\n";
	}
	return 0;
}