#include <bits/stdc++.h>
#define int long long
int t;
const int MAXN=2e5+5;
struct nod {
	int v,id;
};
struct node {
	nod qwq[8];
} a[MAXN];
int n;
int cmp(nod a1,nod b1) {
	if(a1.v==b1.v)return a1.id<b1.id;
	else return a1.v>b1.v;
}
void solve() {
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=3; j++) {
			scanf("%lld",&a[i].qwq[j].v);
			a[i].qwq[j].id=j;
		}
	}
	for(int i=1; i<=n; i++) {
		std::sort(a[i].qwq+1,a[i].qwq+4,cmp);
	}
	int tot1=0,tot2=0,tot3=0;
	int nowans=0;
	for(int i=1; i<=n; i++) {
		if(a[i].qwq[1].id==1)tot1++;
		if(a[i].qwq[1].id==2)tot2++;
		if(a[i].qwq[1].id==3)tot3++;
		nowans+=a[i].qwq[1].v;
	}
	std::vector<int> v;
	int maxx=std::max(tot1,std::max(tot2,tot3));
	int iddd=0;
	if(tot1==maxx)iddd=1;
	if(tot2==maxx)iddd=2;
	if(tot3==maxx)iddd=3;
//	std::cout<<nowans<<'\n';
	if(maxx>n/2) {
//		std::cout<<"Luotianyi\n";
		for(int i=1;i<=n;i++){
			if(a[i].qwq[1].id==iddd){
				v.push_back(a[i].qwq[1].v-a[i].qwq[2].v);
			}
		}
		std::sort(v.begin(),v.end());
		for(int i=0;i<maxx-n/2;i++){
			nowans-=v[i];
		} std::cout<<nowans<<'\n';
	} else {
		std::cout<<nowans<<'\n';
	}


}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	std::ios::sync_with_stdio(0);
//	std::cin.tie(0);
	std::cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}
//csps rp++!
//scanf 用lld!
//算算空间时间!
//Ren5Jie4Di4Ling5%
//如果所有成员全都在自己最喜欢的社团中
//考虑如何调剂
//如果一个社团的人数大于 n/2 显然只有一个
//那么其他社团全部不满足要求
//直接把最大次大差最小的k个调走即可
//对不对？
//对于ai,j=ai,k的怎么办
//考虑这样的话其就算错分 也会以0的代价被调剂
//看起来很对 复杂度 O( nlogn)
//14:47
//15:03
//没有问题了 
//难度：橙色
//输入量大致使用scanf即可 ios我不知道写在哪

