#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int T;
int n, a[N][4],q[N],f[2][N];

vector<int> s1,s2,s3;
long long ans;
unsigned long long cnt;

void dfs(int cur)
{
	cnt ++;
	if(cur == n)
	{
		long long res = 0;
		for(int i = 0;i < s1.size();i ++)res += s1[i];
		for(int i = 0;i < s2.size();i ++)res += s2[i];
		for(int i = 0;i < s3.size();i ++)res += s3[i];
		
		if(s1.size() > n / 2 || s2.size() > n / 2 || s3.size() > n / 2 )
			return;
		if(res > ans)
			ans = res;
		return;
	}
	if(s1.size() + 1 <= n / 2){
		s1.push_back(a[cur + 1][1]);
		dfs(cur + 1);
		s1.pop_back();
	}
	if(s2.size() + 1 <= n / 2){
		s2.push_back(a[cur + 1][2]);
		dfs(cur + 1);
		s2.pop_back();
	}
	if(s3.size() + 1 <= n / 2){
		s3.push_back(a[cur + 1][3]);
		dfs(cur + 1);
		s3.pop_back();
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d",&n);
		bool A = false, B = false;
		
		for(int i = 1;i <= n;i ++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2] != 0 || a[i][3] != 0)
				A = true;
			if(a[i][3] != 0)
				B = true;
		}
		if(!A)
		{
			for(int i = 1;i <= n;i ++)
				q[i] = a[i][1];
			sort(q + 1,q + 1 + n);
			for(int i = 1;i <= n / 2;i ++)
				ans += q[i];
		}else if(!B)
		{
			for(int i = 1;i <= n;i ++)
				for(int j = n / 2;j >= 1;j --)
				{
					
				}
		}
		
		dfs(0);
		
		cout << ans << endl;
		ans = 0;
	}	
	
	return 0;
}
