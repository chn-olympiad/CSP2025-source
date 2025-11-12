#include<bits/stdc++.h>
#define scnaf scanf
using namespace std;
const int N=1e5+5;
//int a1[N],a2[N],a3[N],f[105][105][105];
struct P{
	int x,y,z,w,c;
	pair<int,int> mc[4];
}a[N];
bool cmp(P x,P y){
	if((x.w!=1)||(y.w!=1)){
		if(x.w==y.w)return x.mc[2].first>y.mc[2].first;
		return x.w>y.w;
	}
	else{
		if(x.c!=y.c)return x.c>y.c;
		else return x.mc[2].first>y.mc[2].first;
	}
}
bool cmpt(pair<int,int> x,pair<int,int> y){
	return x.first<y.first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			pair<int,int> tmp[3]={{a[i].x,1},{a[i].y,2},{a[i].z,3}};
			sort(tmp,tmp+3,cmpt);
			a[i].c=tmp[2].first-tmp[1].first;
			a[i].mc[2]=tmp[2];
			a[i].mc[1]=tmp[1];
			a[i].mc[0]=tmp[0];
			if(a[i].mc[2].first==a[i].mc[1].first)a[i].w=0;
			else a[i].w=1;
//			cout<<a[i].mc[0].first<<a[i].mc[1].first<<a[i].mc[2].first<<endl;
		}
		sort(a+1,a+1+n,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].c<<endl;
//		}
		int cnt[4]={0,0,0,0},ans=0;
		for(int i=1;i<=n;i++){
			if(cnt[a[i].mc[2].second]*2<n){
				cnt[a[i].mc[2].second]++;
				ans+=a[i].mc[2].first;
			}
			else ans+=a[i].mc[1].first;
		}
		cout<<ans<<endl;
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
/*
18
4
13
*/
