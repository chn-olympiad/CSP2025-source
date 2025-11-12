#include<iostream> 
#include<cstring>
#include<algorithm> 
#include<cstdio> 

using namespace std;
struct abc
{
	int a,b,c;
}d[100005];
int max3(abc x)
{
	if(x.a>=x.b&&x.a>=x.c)
		return x.a;
	if(x.b>=x.a&&x.b>=x.c)
		return x.b;
	if(x.c>=x.b&&x.c>=x.a)
		return x.c;
}
int min3(abc x)
{
	if(x.a<=x.b&&x.a<=x.c)
		return x.a;
	if(x.b<=x.a&&x.b<=x.c)
		return x.b;
	if(x.c<=x.b&&x.c<=x.a)
		return x.c;
}
int db(abc x)
{
	return x.a+x.b+x.c-max3(x)-min3(x);
}
bool cmp(abc x,abc y)
{
	//if((max(max(x.a,x.b),x.c)-db(x))!=(max(max(y.a,y.b),y.c)-db(y)))
	return (max(max(x.a,x.b),x.c)-db(x))>(max(max(y.a,y.b),y.c)-db(y));
	//return max(max(x.a,x.b),x.c)>max(max(y.a,y.b),y.c);
}
int k(abc x)
{
	if(x.a==max(max(x.a,x.b),x.c))
		return 0;
	else if(x.b==max(max(x.a,x.b),x.c))
		return 1;
	else if(x.c==max(max(x.a,x.b),x.c))
		return 2;
}
int cl(abc x,int y)
{
	if(y==0)
		return max(x.b,x.c);
	if(y==1)
		return max(x.a,x.c);
	if(y==2)
		return max(x.a,x.b);
		
} 
int main()
{
	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,cnt[3],l,m;
	long long ans=0;
	cin>>t;
	while(t--)
	{
		ans=0;l=0;m=0;
		//memset(d,0,sizeof(d));
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=0;i<n;i++)
		{
			/*cin>>d[i].a>>d[i].b>>d[i].c;
			*/ 
			scanf("%d %d %d",&d[i].a,&d[i].b,&d[i].c);/* 
			cout<<d[i].a<<' '<<d[i].b<<' '<<d[i].c<<endl;
			cout<<max3(d[i])<<' '<<min3(d[i])<<' '<<d[i].a+d[i].b+d[i].c<<endl;
			cout<<max3(d[i])-(d[i].a+d[i].b+d[i].c-max3(d[i])-min3(d[i]))(max(max(d[i].a,d[i].b),d[i].c)-db(d[i])<<endl;*/
		}
		sort(d,d+n,cmp);
		for(int i=0;i<n;i++)
		{
			if(cnt[0]<n/2&&cnt[1]<n/2&&cnt[2]<n/2)
			{
				l=k(d[i]);
				cnt[l]++;
				if(cnt[l]==n/2)
					m=l;
				ans+=max(max(d[i].a,d[i].b),d[i].c);
			}
			else
			{
				ans+=cl(d[i],m);
			}
			//cout<<i<<' '<<cnt[0]<<' '<<cnt[1]<<' '<<cnt[2]<<' '<<d[i].a<<' '<<d[i].b<<' '<<d[i].c<</*' '<<ans<<endl;*/
		}
		cout<<ans<<endl;
	} 
	return 0;
} 
