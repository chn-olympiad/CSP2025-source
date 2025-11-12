#include<bits/stdc++.h>
#define int long long
using namespace std;
//bool mp[100010];
//int g[4];
//struct st{
//	int id,b,s;
//}a[100010];
//bool cmp(st a,st b){
//	return a.s>b.s;
//}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
//		memset(g,0,sizeof(g));
//		memset(mp,0,sizeof(mp)); 
		int ret=0;
		int n;
		cin>>n;
		for(int i=1;i<=3*n;i++){
			int x;cin>>x;
			if(i%3==1) ret+=x;
		}
//		sort(a+1,a+3*n+1,cmp);
//		for(int i=1;i<=3*n;i++){
//			if(mp[a[i].id]) continue;
//			if(g[a[i].b]+1>n/2) continue;
//			ret+=a[i].s;
//			mp[a[i].id]=true;
//			g[a[i].b]++;
//			cout<<i<<endl;
//		}
		cout<<ret<<endl;
	}

	return 0;
}

