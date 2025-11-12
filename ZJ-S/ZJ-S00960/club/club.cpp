#include<bits/stdc++.h>
#define max(a,b) ((a>b)?a:b)
using namespace std;
const int N=1e5+10;
int n;
struct Node{
	int b[4];
	int Max(){
		int res=0;
		for(int i=1;i<=3;i++){
			res=max(res,b[i]);
		}
		return res;
	}
	int Maxi(){
		int id=0;
		for(int i=1;i<=3;i++){
			if(b[i]>b[id]){
				id=i;
			}
		}
		return id;
	}
	int De(){
		int id1=0;
		for(int i=1;i<=3;i++){
			if(b[i]>b[id1]){
				id1=i;
			}
		}
		int id2=0;
		for(int i=1;i<=3;i++){
			if(i!=id1&&b[i]>b[id2]){
				id2=i;
			}
		}
		return b[id1]-b[id2];
	}
};
Node a[N];
void input(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i].b[j];
		}
	}
}
int v[4][N],cnt[4];
int ANS;
bool cmp(int i,int j){
	return a[i].De()<a[j].De();
}
void solve(){
	for(int i=1;i<=n;i++){
		ANS+=a[i].Max();
		v[a[i].Maxi()][++cnt[a[i].Maxi()]]=i;
	}
	bool flag=0;
	int ni;
//	for(int i=1;i<=3;i++){
//		cout<<cnt[i]<<'\n';
//	}
	for(int i=1;i<=3;i++){
		if(cnt[i]>n/2){
			flag=1;
			ni=i;
		}
	}
	if(!flag){
		return;
	}
//	puts("OK");
	sort(v[ni]+1,v[ni]+cnt[ni]+1,cmp);
	for(int i=1;i<=(cnt[ni]-n/2);i++){
		ANS-=a[v[ni][i]].De();
	}
}
main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		input();
		solve();
		cout<<ANS<<'\n';
		ANS=0;
		memset(v,0,sizeof v);
		memset(cnt,0,sizeof cnt);
	}
}