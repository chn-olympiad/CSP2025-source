#include<bits/stdc++.h>
using namespace std;
int n,t;
int k = 0;
int w[6];
int answ[6];
int ans = 0,tmp;
struct p{
	int f,f1,f2;
	int flag,flag1,flag2;
	int maxx1,maxx2,maxx3;
	int mf1,mf2,mf3;
	bool u;
}nums[100010];
struct t1{
	int v,id;
};
bool cmpar(t1 a,t1 b)
{
	return a.v>b.v;
}
bool cmp(p a,p b)
{
	return a.f>b.f;
}
bool cmp1(p a,p b)
{
	return a.f1>b.f1;
}
bool cmp2(p a,p b)
{
	return a.f2>b.f2;
}
bool cmpq(p a,p b)
{
	return a.maxx1>b.maxx1;
}
bool cmpw(p a,p b)
{
	return a.maxx2>b.maxx2;
}
bool cmpe(p a,p b)
{
	return a.maxx3>b.maxx3;
}
void solve1()
{
	sort(nums+1,nums+1+n,cmp);
	for(int i = 1;i<=n;i++)
	{
		if(w[nums[i].flag]<tmp&&nums[i].u==true)
		{
			w[nums[i].flag]+=1;
			ans+=nums[i].f;
			nums[i].u=false;
		}
	}
}
void solve2()
{
	    sort(nums+1,nums+1+n,cmp1);
		for(int i = 1;i<=n;i++)
		{
			if(w[nums[i].flag1]<tmp&&nums[i].u==true)
		    {
			   w[nums[i].flag1]+=1;
			   ans+=nums[i].f1;
			   nums[i].u=false;
		    }
		}
}
void solve3()
{
	sort(nums+1,nums+1+n,cmp2);
		for(int i = 1;i<=n;i++)
		{
			if(w[nums[i].flag2]<tmp&&nums[i].u==true)
		    {
			   w[nums[i].flag2]+=1;
			   ans+=nums[i].f2;
			   nums[i].u=false;
		    }
		}
}
int solve(int a,int b,int c)
{
	for(int i = 1;i<=n;i++) nums[i].u=true;
	memset(w,0,sizeof(w));
	ans = 0;
	int tmp = n/2;
	if(a==1) solve1();
	else if(a==2) solve2();
	else if(a==3) solve3();
	if(b==1) solve1();
	else if(b==2) solve2();
	else if(b==3) solve3();
	if(c==1) solve1();
	else if(c==2) solve2();
	else if(c==3) solve3();
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(w,0,sizeof(w));
		int ans = 0,ans1=0,ans2=0;
	    cin>>n;
	    for(int i = 1;i<=n;i++)  
		{
			nums[i].u=true;
			nums[i].f=0;
			nums[i].f1=0;
			nums[i].f2=0;
			nums[i].flag=0;
			nums[i].flag1=0;
			nums[i].flag2=0;
			 t1 ar[4];
		     cin>>ar[1].v>>ar[2].v>>ar[3].v;
		     ar[1].id=1;
		     ar[2].id=2;
		     ar[3].id=3;
		     nums[i].f = ar[1].v;
		     nums[i].f1=ar[2].v;
		     nums[i].f2=ar[3].v;
		     nums[i].flag=ar[1].id;
		     nums[i].flag1=ar[2].id;
		     nums[i].flag2=ar[3].id;
		     tmp=n/2;
		      sort(ar+1,ar+1+3,cmpar);
		      nums[i].maxx1=ar[1].v;
		      nums[i].maxx2=ar[2].v;
		      nums[i].maxx3=ar[3].v;
		    nums[i].mf1=ar[1].id;
		     nums[i].mf2=ar[2].id;
		     nums[i].mf3=ar[3].id;
		}
		int maxx=0;
		maxx = max(maxx,solve(1,2,3));
		maxx = max(maxx,solve(1,3,2));
		maxx = max(maxx,solve(2,1,3));
		maxx = max(maxx,solve(2,3,1));
		maxx = max(maxx,solve(3,2,1));
		maxx = max(maxx,solve(3,1,2));
		int ans6 = 0;
		memset(w,0,sizeof(w));
		for(int i = 1;i<=n;i++) nums[i].u=true;
		sort(nums+1,nums+1+n,cmpq);
		for(int i = 1;i<=n;i++)
		{
			if(w[nums[i].mf1]<tmp&&nums[i].u==true)
		    {
			   w[nums[i].mf1]+=1;
			   ans6+=nums[i].maxx1;
			   nums[i].u=false;
		    }
		}
		sort(nums+1,nums+1+n,cmpw);
		for(int i = 1;i<=n;i++)
		{
			if(w[nums[i].mf2]<tmp&&nums[i].u==true)
		    {
			   w[nums[i].mf2]+=1;
			   ans6+=nums[i].maxx2;
			   nums[i].u=false;
		    }
		}
		sort(nums+1,nums+1+n,cmpe);
		for(int i = 1;i<=n;i++)
		{
			if(w[nums[i].mf3]<tmp&&nums[i].u==true)
		    {
			   w[nums[i].mf3]+=1;
			   ans6+=nums[i].maxx3;
			   nums[i].u=false;
		    }
		}
		maxx=max(maxx,ans6);
		cout<<maxx<<endl;
	}
	return 0;
}

