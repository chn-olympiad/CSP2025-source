#include<bits/stdc++.h>
using namespace std;
long long ans,ans1,m,pd[100010],pdp[4];
long long T,pp;
struct peo1 {
	int lk1,bh1;
} p1[100010];
struct peo2 {
	int lk2,bh2;
} p2[100010];
struct peo3 {
	int lk3,bh3;
} p3[100010];
bool cmp1(peo1 a,peo1 b) {
	return a.lk1>b.lk1;
}
bool cmp2(peo2 a,peo2 b) {
	return a.lk2>b.lk2;
}
bool cmp3(peo3 a,peo3 b) {
	return a.lk3>b.lk3;
}
void dfs(int a) {
	if(a>m) {
		ans=max(ans,ans1);
		return;
	}
	if(pdp[1]!=-1) {
		ans1+=p1[a].lk1;
		pdp[1]++;
		if(pdp[1]>=m/2)pdp[1]=-1;
		dfs(a+1);
		ans1-=p1[a].lk1;
		if(pdp[1]==-1)pdp[1]=m/2;
	}
	if(pdp[2]!=-1) {
		ans1+=p2[a].lk2;
		pdp[2]++;
		if(pdp[2]>=m/2)pdp[2]=-1;
		dfs(a+1);
		ans1-=p2[a].lk2;
		if(pdp[2]==-1)pdp[2]=m/2;
	}
	if(pdp[3]!=-1) {
		ans1+=p3[a].lk3;
		pdp[3]++;
		if(pdp[3]>=m/2)pdp[3]=-1;
		dfs(a+1);
		ans1-=p3[a].lk3;
		if(pdp[3]==-1)pdp[3]=m/2;
	}

}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>m;
		for(int i=1; i<=m; i++) {
			cin>>p1[i].lk1>>p2[i].lk2>>p3[i].lk3;
			p1[i].bh1=i;
			p2[i].bh2=i;
			p3[i].bh3=i;
			if(p2[i].lk2!=0)pp=1;
		}
		if(pp==0) {
			sort(p1+1,p1+m,cmp1);
			sort(p2+1,p2+m,cmp2);
			sort(p3+1,p3+m,cmp3);
			for(int i=1; i<=m/2; i++)ans+=p1[i].lk1;
			cout<<ans<<endl;
		} else {
			dfs(1);
			cout<<ans<<endl;
		}
		ans=0;pp=0;
		for(int i=1; i<=m; i++) {
			p1[i].lk1=0;
			p2[i].lk2=0;
			p3[i].lk3=0;
			pd[i]=0;
		}
		for(int i=1; i<=3; i++)pdp[i]=0;
	}
	return 0;
}
