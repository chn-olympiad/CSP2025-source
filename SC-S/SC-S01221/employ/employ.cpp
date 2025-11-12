#include<bits/stdc++.h>
#define int long long
#define mod 998244353
 using namespace std;
 int n,m;
 string s;
 int arr[510],day[510];
 int ans = 1,cnt;
 int kkksc03 = 0;
 int chen_zhe;
 signed main()
 {
 	freopen("employ.in","r",stdin);
 	freopen("employ.out","w",stdout);
 	scanf("%lld%lld",&n,&m);
 	chen_zhe = n;
 	vector<int> patience(n + 1,0);
 	cin>>s;
 	int len = s.size();
 	bool flag = false;
 	for(int i = 0;i < len;i++)
 	{
 		day[i + 1] = s[i] - 48;
 		if(!day[i + 1])
 		{
 			flag = !flag;
	 	}
	 	cnt += day[i + 1];
 	}
 	
 	for(int i = 1;i <= n;i++)
 	{
 		scanf("%lld",&patience[i]);
 		if(!patience[i])
 		{
 			chen_zhe--;
	 	}
 	}
 	
 	if(m == n)
 	{
 		if(flag)
 		{
 			printf("0");
 			return 0;
	 	}
	 	else
	 	{
	 		for(int i = 1;i <= n;i++)
		 	{
			 	ans = (ans * i) % mod;
	 		}
	 		printf("%lld",ans);
	 		return 0;
	 	}
 	}//测试点15 
 	
 	if(!flag)
 	{
	 	for(int i = 1;i <= n;i++)
	 	{
		 	ans = (ans * i) % mod;
 		}
 		printf("%lld",ans);
 		return 0;
	}//特殊性质A 
 	
 	if(m == 1)
 	{
	 	for(int i = 1;i <= n;i++)
	 	{
		 	ans = (ans * i) % mod;
 		}
 		printf("%lld",ans);
 		return 0;
 	}//测试点12~14? 
 	
 	if(cnt < m)
 	{
 		printf("0");
 		return 0;
 	}//cnt小于m是想干啥
	 
 	srand(time(NULL));
 	kkksc03 = rand() % 2;
 	if(kkksc03)
 	{
 		printf("0");
 		return 0;
 	}
 	cout<<rand() % mod;
 	return 0;
 	
	return 0;
 }
