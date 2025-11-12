#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;

int T,n,a[maxn][5],cnt[5];
long long ans;
vector<int> ch[5],add;

void init(){
	ans=0;
	ch[0].clear();
	ch[1].clear();
	ch[2].clear();
	cnt[0]=0;
	cnt[1]=0;
	cnt[2]=0;
	add.clear();
}

void cg(int x){
	for (int i=0;i<(int)ch[x].size();i++){
		int j=ch[x][i];
		add.push_back(a[j][x]-max(a[j][(x+1)%3],a[j][(x+2)%3]));
	}
	sort(add.begin(),add.end());
	for (int i=0;i<cnt[x]-n/2;i++){
		ans-=add[i];
	}
}

int cal(int p,int q,int r){
	int res=max(p,max(q,r));
	if (res==p){
		return 0;
	}else if (res==q){
		return 1;
	}else{
		return 2;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		init();
		for (int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
			int tmp=cal(a[i][0],a[i][1],a[i][2]);
			ch[tmp].push_back(i);
			cnt[tmp]++;
			ans+=a[i][tmp];
		}
		if (cnt[0]>n/2){
			cg(0);
		}else if (cnt[1]>n/2){
			cg(1);
		}else if (cnt[2]>n/2){
			cg(2);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
