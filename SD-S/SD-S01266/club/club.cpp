#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][4],A,B,C;
struct abc{
	int ch,wh;
}p[N];
int se(int a,int b,int c){
	int f[5]={a,b,c};
	sort(f,f+3);
	return f[1];
}
int cmp(const abc &h,const abc &k){
	if (h.ch<k.ch) return 1;
	return 0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while (T--){
		A=B=C=0;
		int n,ans=0;
		cin>>n;
		for (int i=1;i<=n;++i){
			int x,y,z;
			cin>>x>>y>>z;
			p[i].ch=max(max(x,y),z)-se(x,y,z);
			ans+=max(max(x,y),z);
			if (x>=y&&x>=z) A++,p[i].wh=1;
			else if (y>=x&&y>=z) B++,p[i].wh=2;
			else C++,p[i].wh=3;
		}
		sort(p+1,p+n+1,cmp);
		int mr=max(max(A,B),C);
		mr-=n/2;
		int opt;
		if (A>=B&&A>=C) opt=1;
		else if (B>=A&&B>=C) opt=2;
		else opt=3;
		for (int i=1,j=1;i<=mr;++i,++j) {
			if (opt!=p[j].wh) {
				i--;
				continue;
			}
			ans-=p[j].ch;
		}
		printf("%d\n",ans);
	}
	return 0;
}

