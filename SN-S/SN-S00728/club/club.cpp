//SN-S00728 闫卜予 西安高新一中沣东中学初中校区
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
//只过A: 

ll t;
struct sfsf{
	int a;
	int b;
	int c;
}d[200005];
ll n;
bool cmp(sfsf aa,sfsf bb){
	return aa.a>bb.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(d,0,sizeof d);
		cin>>n;
		ll ans=0;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
		}
		sort(d+1,d+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=d[i].a;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
