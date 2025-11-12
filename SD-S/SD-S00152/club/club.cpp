#include <bits/stdc++.h>
using namespace std;


const int NN=100005;
int a1[NN],a2[NN],a3[NN],n,hn;
long long ans=-1,num=0; //¿¼ÂÇlonglong 

void dfs(int p,int c1,int c2,int c3)
{
	if(p>n) ans=max(ans,num);
	
	if(c1<hn)
	{
		num+=a1[p];
		dfs(p+1,c1+1,c2,c3);
		num-=a1[p];
	} 
	if(c2<hn)
	{
		num+=a2[p];
		dfs(p+1,c1,c2+1,c3);
		num-=a2[p];
	} 
	if(c3<hn)
	{
		num+=a3[p];
		dfs(p+1,c1,c2,c3+1);
		num-=a3[p];
	} 
	
	
	return;
}

bool mycmp(int a,int b)
{
	return a>b;
}

void Start()
{
	int n;
	cin>>n;
	hn=n/2;
	memset(a1,0,sizeof(a1));
	memset(a2,0,sizeof(a2));
	memset(a3,0,sizeof(a3));
	ans=num=0;//////
	for(int i=1;i<=n;i++)
		cin>>a1[i]>>a2[i]>>a3[i];
	
	if(n<=30) 
		dfs(1,0,0,0);
	else
	{
		sort(a1+1,a1+n+1,mycmp);
		for(int i=1;i<=hn;i++)
			ans+=a1[i];
	}
	
	cout<<ans<<endl;
	
	return;
}


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin>>T;
	while(T--)
		Start();
	
	return 0;
}
