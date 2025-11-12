#include <bits/stdc++.h>
#define Mod 998244353
#define int long long
using namespace std;
const int N=5e2+1e1;
inline void read(int &x)
{
 char c=getchar();	x=0;
 while(c<'0'||c>'9')	c=getchar();
 while(c>='0'&&c<='9')
 	x=(x<<3)+(x<<1)+c-48,c=getchar();
}
char s[N];
int f[2][20][1<<18],c[N],n,m;
inline void point1_to_point5()
{
 int sum=0,ans=0;	scanf("%s",s+1);	queue< pair<int,int> > q[2];
 q[0].push(make_pair(0,0)),f[0][0][0]=1;
 for(int i=1;i<=n;i++)	read(c[i]);
 for(int i=1;i<=n;i++)
 {
 	while(!q[(i-1)%2].empty())
 	{
 		int x=q[(i-1)%2].front().first,y=q[(i-1)%2].front().second;	q[(i-1)%2].pop();
 		for(int j=1;j<=n;j++)
 			if((y&(1<<j-1))==0)	
 			{
 				if(f[i%2][x+((s[i]=='1')&&(c[j]>i-1-x))][y|(1<<j-1)]==0)	q[i%2].push(make_pair((x+((s[i]=='1')&&(c[j]>i-1-x))),(y|(1<<j-1))));
 				f[i%2][x+((s[i]=='1')&&(c[j]>i-1-x))][y|(1<<j-1)]+=f[(i-1)%2][x][y],f[i%2][x+((s[i]=='1')&&(c[j]>i-1-x))][y|(1<<j-1)]%=Mod;
			}
		f[(i-1)%2][x][y]=0;
	}
 }
 for(int i=m;i<=n;i++)	ans+=f[n%2][i][(1<<n)-1],ans%=Mod;
 printf("%lld\n",ans);
 return ;
}
bool specialA=true;	
int number[N],F[N][N];
inline void special_A()
{
 for(int i=1;i<=n;i++)
 	if(c[i]==0)	specialA=false;
 if(specialA)
 {
	int ans=1;
	for(int i=1;i<=n;i++)
		ans=ans*i,ans%=Mod;
	printf("%lld\n",ans);
	return ;
 }
 for(int i=1;i<=n;i++)	number[c[i]]++;
 for(int i=1;i<=n;i++)
 	number[i]+=number[i-1];
 int ans=0;	F[0][0]=1;
 for(int i=0;i<=n-1;i++)
 {
 	for(int j=0;j<=i;j++)
 	{
 		if(n-number[j]-(i-j)>0)	F[i+1][j]+=F[i][j]*(n-number[j]-(i-j)%Mod,F[i+1][j]%=Mod;
 		if(number[j]-j>0)		F[i+1][j+1]+=F[i][j]*(number[j]-j)%Mod,F[i+1][j+1]%=Mod;
	}
 }
 for(int i=0;i<=n-m;i++)	ans+=F[n][i],ans%=Mod;
 printf("%lld\n",ans);
 return ;
}
signed main()
{
 freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
 read(n),read(m);
 if(n<=18)
 {
 	point1_to_point5();
 	return 0;
 }
 scanf("%s",s+1);
 for(int i=1;i<=n;i++)
 	specialA&=(s[i]=='1');
 for(int i=1;i<=n;i++)	read(c[i]);
 if(n==m)
 {
	for(int i=1;i<=n;i++)
		if(c[i]==0)	specialA=false;	
 	if(!specialA)
 	{
 		printf("0\n");
 		return 0;
	}
	else
	{
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*i,ans%=Mod;
		printf("%lld\n",ans);
		return 0;
	}
 }
 if(specialA)	
 {
 	special_A();
 	return 0;
 }
 return 0;
}
