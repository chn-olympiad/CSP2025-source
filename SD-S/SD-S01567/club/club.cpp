#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=100005;
int n,T,a[N][4],ans,ct[4],fl[N],id;
struct node{int x,i1,i2;};
vector<node> v;
bool operator<(const node& x,const node& y){
	return x.x>y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdin);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n,ans=0,v.clear(),ct[1]=ct[2]=ct[3]=0,memset(fl,0,sizeof(fl));
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)cin>>a[i][j];
		for(int i=1;i<=n;i++){
			if(a[i][1]==max({a[i][1],a[i][2],a[i][3]}))ct[1]++,ans+=a[i][1];
			else if(a[i][2]==max({a[i][1],a[i][2],a[i][3]}))ct[2]++,ans+=a[i][2];
			else ct[3]++,ans+=a[i][3];
		}
		if(ct[1]<=n/2&&ct[2]<=n/2&&ct[3]<=n/2){
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=3;i++)if(ct[i]>n/2)id=i;
		for(int i=1;i<=n;i++)if(a[i][id]==max({a[i][1],a[i][2],a[i][3]})){
			if(id^1)v.push_back({a[i][1]-a[i][id],1,i});
			if(id^2)v.push_back({a[i][2]-a[i][id],2,i});
			if(id^3)v.push_back({a[i][3]-a[i][id],3,i});
		}
		sort(v.begin(),v.end());
		for(int i=0;i<(int)v.size();i++){
			if(fl[v[i].i2])continue;
			if(ct[v[i].i1]==n/2)continue;
			fl[v[i].i2]=1,ans+=v[i].x,ct[id]--,ct[v[i].i1]++;
			if(ct[id]<=n/2)break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
