#include<bits/stdc++.h>
#define int long long
const int N=2e5+5;
using namespace std;
int n,t,a[N][4];
int gof[N];
int tot[4];
int ans;
int lst[N];
//爽！
//一口气打了70行一点没报，手感好到炸！！！ 
int mmex(int x){
	int mmax = max({a[x][1],a[x][2],a[x][3]});
	int mmin = min({a[x][1],a[x][2],a[x][3]});
	if(a[x][1] != mmax && a[x][1] != mmin){
		return a[x][1];
	}else if(a[x][2] != mmax && a[x][2] != mmin){
		return a[x][2];
	}else{
		return a[x][3];
	}
}
bool cmp(int x,int y){
	return a[x][gof[x]]-mmex(x) < a[y][gof[y]]-mmex(y);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans = 0;
		cin>>n;
		memset(tot,0,sizeof tot);
		lst[0] = 0;
		for(int i=1;i<=n;i++){
//			cin>>&a[i][1]>>&a[i][2]>>&a[i][3];
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			
			for(int j=1;j<=3;j++)
				if(a[i][j] > a[i][gof[i]])
					gof[i] = j;
			//存储每个人最优策略下去哪 
			tot[gof[i]]++;ans+=a[i][gof[i]];
		}
		bool flag = true;
		int gc;
		for(int i=1;i<=3;i++){
			if(tot[i] > n/2) gc=i,flag = false;
		}
		if(flag){
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(gof[i] == gc){
				lst[++lst[0]]=i;
			}
		}
		sort(lst+1,lst+1+lst[0],cmp);
//		for(int i=1;i<=lst[0];i++){
//			cout<<lst[i]<<" ";
//		}
		int del = tot[gc] - n/2;
		for(int i=1;i<=del;i++){
			ans -= a[lst[i]][gof[lst[i]]];
			ans += mmex(lst[i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//先全部按照最大贪心分配 
//然后把超过n/2的那个部门（只会有一个）的人调整到其他部门
//调整的代价为max_i - mex_i
//这样就保证了除了一小部分的以外，全部在最优策略上
//且这样的调整至多有一次，因为n/2以外的部分至多填满另一个部门到n/2 
