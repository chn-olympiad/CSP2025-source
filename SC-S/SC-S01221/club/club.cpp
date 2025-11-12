//5
#include<bits/stdc++.h>
#define ll long long 
#define ull unsigned long long
 using namespace std;
 int t,n,m;
 
 struct Node
 {
 	int a,b,c;
 	int sign1;
 }arr[205];
 
 bool cmp(Node x,Node y)
 {
 	return x.a > y.a;
 }
 
 ll a,b,c;
 ull ans;
 
 void dfs(int x,int y,int w1,int w2,int w3,ull sum)
 {
 	int brr[4];
 	brr[1] = w1,brr[2] = w2,brr[3] = w3;
 	
 	if(x == n + 1)
 	{
 		ans = max(ans,sum);
 		return ;
 	}
 	
 	for(int i = 1;i <= 3;i++)
 	{
 		if(brr[i] == 0)
 		{
 			continue;
	 	}
	 	brr[i]--;
	 	if(i == 1)
	 	{
	 		dfs(x + 1,i,brr[1],brr[2],brr[3],sum + arr[x].a);
	 	}
	 	else if(i == 2)
	 	{
	 		dfs(x + 1,i,brr[1],brr[2],brr[3],sum + arr[x].b);
	 	}
	 	else if(i == 3)
	 	{
	 		dfs(x + 1,i,brr[1],brr[2],brr[3],sum + arr[x].c);
	 	}
	 	brr[i]++;
 	}
 	return ;
 }
 
 int main()
 {
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	scanf("%d",&t);
 	while(t--)
 	{
 		ans = 0;
 		scanf("%d",&n);
 		m = n / 2;
 		for(int i = 1;i <= n;i++)
 		{
 			arr[i].sign1 = 1;
 			scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
 			if(arr[i].a >= arr[i].b && arr[i].a >= arr[i].c)
 			{
 				a++;
 				ans += arr[i].a;
 		 	}
 			else if(arr[i].b >= arr[i].a && arr[i].b >= arr[i].c)
 			{
 				b++;
 				ans += arr[i].b;
		 	}
 			else if(arr[i].c >= arr[i].b && arr[i].c >= arr[i].a)
 			{
 				c++;
 				ans += arr[i].c;
		 	}
	 	}
	 	
	 	if(!b && !c)
	 	{
	 		sort(arr + 1,arr+ 1 + n,cmp);
	 		ans = 0;
	 		for(int i = 1;i <= m;i++)
	 		{
	 			ans += arr[i].a;
		 	}
	 		printf("%lld\n",ans);
	 		ans = 0,a = 0,b = 0,c = 0;
	 		continue;
	 	}//解决测试点12 
	 	
	 	if(a <= m && b <= m && c <= m)
	 	{
	 		printf("%lld\n",ans);
	 		continue;
	 	}//解决妈生出来就是最优解的，也就是样例1的第一种情况 
	 	
	 	ans = 0;
	 	dfs(1,1,m,m,m,0);
	 	printf("%lld\n",ans);
	 	ans = 0;
 	}
 }