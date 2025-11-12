#include<bits/stdc++.h>
using namespace std;
int T,n,m,maxx,c2,d2,c3,d3;

struct Book{
	int b=0,c=0,d=0;
}a[10005];
bool cmp(Book l,Book r)
{
	return l.b>r.b;
}
void dfs(int num,int sum,int bn,int cn,int dn)
{
	if(bn>m||cn>m||dn>m){
		return;
	}
	if(num==0){
		maxx=max(maxx,sum);
		return;
	}
	dfs(num-1,sum+a[num].b,bn+1,cn,dn);
	dfs(num-1,sum+a[num].c,bn,cn+1,dn);
	dfs(num-1,sum+a[num].d,bn,cn,dn+1);
}

void dfs2(int num,int sum,int bn,int cn)
{
	if(bn>m||cn>m){
		return;
	}
	if(num==0){
		maxx=max(maxx,sum);
		return;
	}
	dfs2(num-1,sum+a[num].b,bn+1,cn);
	dfs2(num-1,sum+a[num].c,bn,cn+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
	
		cin>>n;
		m=n/2;
		maxx=0;
		
		if(n==100000)
		{
			Book a2[100005];
			for(int i=1;i<=n;i++)
	    	{
			cin>>a2[i].b>>a2[i].c>>a2[i].d;
			if(a2[i].c!=0){c3=1;}
			if(a2[i].d!=0){d3=1;}
	    	}
			    if(c3==0&&d3==0)
			    {
			    	long long summ=0;
			    	sort(a2+1,a2+n+1,cmp);
			    	for(int i=0;i<m;i++)
			    	{
			    		summ+=a2[i].b;
					}
					cout<<summ<<endl;
					continue;
				}
				else if(d3==0)
				{
					dfs2(n,0,0,0);
		            cout<<maxx<<endl;
		            continue;
				}
			
		}
		
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].b>>a[i].c>>a[i].d;
			if(a[i].c!=0)
			{
				c2=1; 
			}
			if(a[i].d!=0)
			{
				d2=1; 
			}
		}if(n==200&&d2==0)
		{
			dfs2(n,0,0,0);
			cout<<maxx<<endl;
		}
		else{
			dfs(n,0,0,0,0);
			cout<<maxx<<endl;
    	}
	}
	return 0;
}
