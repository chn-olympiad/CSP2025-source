#include<bits/stdc++.h>
using namespace std;
int n;
const int nn=1e5+5;
int a[nn][4],opt[nn],cnt[4];
inline void get(int i){
	int mx=max(a[i][1],max(a[i][2],a[i][3]));
	if(a[i][1]==mx) opt[i]=1;
	else if(a[i][2]==mx) opt[i]=2;
	else opt[i]=3;
}
inline void swp(int id){
	swap(cnt[1],cnt[id]);
	for(int i=1;i<=n;i++) swap(a[i][1],a[i][id]),get(i);
}
vector<int> ve;
#define pb push_back
inline void sol(){
	cin>>n;
	int res=0;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		get(i);
		cnt[opt[i]]++;
		res+=a[i][opt[i]];
	}
	int mx=max(cnt[1],max(cnt[2],cnt[3]));
	if(cnt[2]==mx) swp(2);
	else if(cnt[3]==mx) swp(3);
	if(cnt[1]<=n/2) return cout<<res<<endl,void();
//	else{
		ve.clear();
		for(int i=1;i<=n;i++){
			if(opt[i]==1){
				ve.pb(a[i][1]-max(a[i][2],a[i][3]));
			}
		}
		sort(ve.begin(),ve.end());
//		while(cnt[1]>n/2)/
		for(int i=0;i<cnt[1]-n/2;i++) res-=ve[i];
		cout<<res<<endl;
//	}
}
int ttt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>ttt;
	while(ttt--) sol();
	return 0;
}
