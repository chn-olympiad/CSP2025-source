#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int t,n;
int a[N],b[N][2],op[N];
bool flaga;
//int a[N][5];
struct node
{
	int id,team,val;
	friend bool operator < (const node &x,const node &y) {return x.val>y.val;}
};
struct figure
{
	int id,team,val;
} x[N][5];
priority_queue <node> q[5];
inline int read()
{
	int k=0;
	char c=getchar();
	while(c<48 || c>57) c=getchar();
	while(c>=48 && c<=57) k=(k<<3)+(k<<1)+c-48,c=getchar();
	return k;
}
inline bool cmp(figure x,figure y) {return x.val>y.val;}
//inline void clean()
//{
//	
//}
int main()
{
	freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		//clean();
		n=read();
		flaga=1;
		int lim=n/2,ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) x[i][j].val=read(),x[i][j].id=j,x[i][j].team=i;
			sort(x[i]+1,x[i]+4,cmp);
			if(x[i][2].val || x[i][3].val) flaga=0;
		}
		if(n==2)
		{
			if(x[1][1].id==x[2][1].id) printf("%d\n",max(x[1][1].val+x[2][2].val,x[1][2].val+x[2][1].val));
			else printf("%d\n",x[1][1].val+x[2][1].val);
			continue;
		}
		if(flaga)
		{
			for(int i=1;i<=n;i++) a[i]=x[i][1].val;
			sort(a+1,a+n+1, greater<int>() );
			for(int i=1;i<=lim;i++) ans+=a[i];
			printf("%d\n",ans);
			continue;
		}
		if(n<=30)
		{
			//cout<<lim<<endl;
			for(int i=1;i<=n;i++) b[i][0]=x[i][1].val,b[i][1]=x[i][2].val;
			//for(int i=1;i<=n;i++) cout<<b[i][0]<<" "<<b[i][1]<<endl;
			for(int i=1;i<=lim;i++) ans+=b[i][0],op[i]=0;
			for(int i=lim+1;i<=n;i++) ans+=b[i][1],op[i]=1;
			for(int i=1;i<=n;i++)
			{
				//cout<<ans<<" ";
				for(int j=1;j<=n;j++)
				{
					if(op[i]==op[j]) continue;
					if(ans-b[i][op[i]]-b[j][op[j]]+b[i][op[i]^1]+b[j][op[j]^1]>ans) 
					{
						ans=ans-b[i][op[i]]-b[j][op[j]]+b[i][op[i]^1]+b[j][op[j]^1];
						op[i]^=1;
						op[j]^=1;
					}
				}
			}
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			q[x[i][1].id].push((node){x[i][1].id,x[i][1].team,x[i][1].val});
			int siz=q[x[i][1].id].size();
			///cout<<siz<<endl;
			if(siz>lim)
			{
				node k=q[x[i][1].id].top(); q[x[i][1].id].pop();
				int id=k.id,team=k.team,val=k.val;
				q[x[team][2].id].push((node){x[team][2].id,x[team][2].team,x[team][2].val});
			}
		}
		while(!q[1].empty()) ans+=q[1].top().val,q[1].pop();
		while(!q[2].empty()) ans+=q[2].top().val,q[2].pop();
		while(!q[3].empty()) ans+=q[3].top().val,q[3].pop();
		printf("%d\n",ans);
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