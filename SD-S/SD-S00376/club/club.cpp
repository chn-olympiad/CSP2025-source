#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define fori(x) for(ll i=1;i<=(x);i++)
#define forj(x) for(ll j=1;j<=(x);j++)

struct node
{
	ll p[4];
};
bool cmp(node a1,node a2)
{
	return a1.p[1]-a1.p[2]>a2.p[1]-a2.p[2];
}
ll n,a[4][100009],cnt[4],ans=0,nu;
ll dfs(ll num,ll k)
{
	//cout<<";"<<k<<endl;
	ll ansnei=0;
	if(num>=n+1)
	{
		return k;
	}
	fori(3)
	{
		if(cnt[i]<nu)
		{
			cnt[i]++;
			ansnei = max(ansnei,dfs(num+1,k+a[i][num]));
			cnt[i]--;
		}
	}
	
	return ansnei;
}
node anode[100009];
int main()
{
	long long t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
	ans =0;
	bool flagk = 1;
	//memset(a,0,sizeof(a));
	scanf("%lld",&n);
	nu = n/2;
	fori(n) scanf("%lld%lld%lld",&a[1][i],&a[2][i],&a[3][i]);
	fori(n)	anode[i].p[1]=a[1][i],anode[i].p[2]=a[2][i],anode[i].p[3]=a[3][i];
	
	//A&B
	fori(n)
	{
		if(!(a[3][i]==0))	break;
		if(i==n&&a[3][i]==0)
		{
			forj(n)
			{
				
				if(!a[2][j]==0)	break;
				if(j==n&&a[2][j]==0)
	{
	sort(a[1]+1,a[1]+n+1);
	fori(nu)	ans+=a[1][i];
	printf("%lld\n",ans);
	flagk=0;
	continue;
	}
			}
	flagk=0;
	sort(anode+1,anode+n+1,cmp);
	fori(nu)	ans+=anode[i].p[1];
	fori(nu)	ans+=anode[i+nu].p[2];
	printf("%lld\n",ans);
	continue;
		}
	} 
	
	
	if(flagk){
	ans = dfs(1,0);
	printf("%lld\n",ans);}
	
}

	return 0;
}//40PTS
//i love yukina roxy anon yuki aimi aiba and all of bangdreams characters and cvs
//CCF SEE U NEXT LIVE 
//RP++
