#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
const int M=114514;
int n;
struct T {int v,k;}t[M][3];
bool cmp(T a,T b) {return a.v>b.v;}
int c[M];
int d[3][M],len[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ms(c,0),ms(len,0);
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++) scanf("%d",&t[i][j].v),t[i][j].k=j;
			sort(t[i],t[i]+3,cmp),c[t[i][0].k]++,ans+=t[i][0].v;
			d[t[i][0].k][++len[t[i][0].k]]=t[i][0].v-t[i][1].v;
		}
		for(int j=0;j<3;j++)
		{
			if(c[j]<=n/2) continue;
			sort(d[j]+1,d[j]+1+len[j]);
			int k=1;
			while(c[j]>n/2) ans-=d[j][k],k++,c[j]--;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*

*/
