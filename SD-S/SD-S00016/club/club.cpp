#include<bits/stdc++.h>
#define pii pair<long long,long long> 
#define ll long long
using namespace std;
const int N = 1e5 + 9;
struct A{
	ll x,y,z;
}a[N]; 
int t,n,f1,f2,f3,sumx,sumy,sumz,sum,ans;
int cmp1(A a,A b)
{
	if(a.x != b.x) return a.x > b.x;
	else if(a.y != b.y) return a.y > b.y;
	else return a.z > b.z;
} 
int cmp2(A a,A b)
{
	if(a.y != b.y) return a.y > b.y;
	else if(a.x != b.x) return a.x > b.x;
	else return a.z > b.z;
}
int cmp3(A a,A b)
{
	if(a.z != b.z)return a.z > b.z;
	else if(a.x != b.x) return a.x > b.x;
	else if(a.y != b.y) return a.y > b.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1;i <= n;i ++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			f1 += a[i].x;
			f2 += a[i].y;
			f3 += a[i].z;
			sumx += a[i].x;
			sumy += a[i].y;
			sumz += a[i].z;
		}
		sum = 0;
		ans = 0;
		if(f2 == 0 && f3 == 0) 
		{
			sort(a + 1, a + n + 1,cmp1);
			for(int i = 1;i <= n / 2;i++)
			{
				sum += a[i].x; 
			}
			cout << sum << endl;
		}
		else if(f1 == 0 && f3 == 0) 
		{
			sort(a + 1, a + n + 1,cmp2);
			for(int i = 1;i <= n / 2;i++)
			{
				sum += a[i].y; 
			}
			cout << sum << endl;
		}
		else if(f2 == 0 && f1 == 0) 
		{
			sort(a + 1, a + n + 1,cmp3);
			for(int i = 1;i <= n / 2;i++)
			{
				sum += a[i].z; 
			}
			cout << sum << endl;
		}
		else if(f3 == 0) 
		{
			sort(a + 1, a + n + 1,cmp1);
			for(int i = 1;i <= n / 2;i++)
			{
				sum += a[i].x;
				ans += a[i].y;
			}
			ans = sumy - ans;
			sum += ans;
			sort(a + 1, a + n + 1,cmp2);
			int sum2 = 0,ans2 = 0;
			for(int i = 1;i <= n / 2;i++)
			{
				sum2 += a[i].y;
				ans2 += a[i].x;
			}
			ans2 = sumx - ans2;
			sum2 += ans2;
			if(sum > sum2) cout << sum << endl;
			else cout << sum2 << endl;
		}
		else if(f1 == 0) 
		{
			sort(a + 1, a + n + 1,cmp2);
			for(int i = 1;i <= n / 2;i++)
			{
				sum += a[i].y;
				ans += a[i].z;
			}
			ans = sumy - ans;
			sum += ans;
			sort(a + 1, a + n + 1,cmp3);
			int sum2 = 0,ans2 = 0;
			for(int i = 1;i <= n / 2;i++)
			{
				sum2 += a[i].z;
				ans2 += a[i].y;
			}
			ans2 = sumx - ans2;
			sum2 += ans2;
			if(sum > sum2) cout << sum << endl;
			else cout << sum2 << endl;
		}
		else if(f2 == 0) 
		{
			sort(a + 1, a + n + 1,cmp1);
			for(int i = 1;i <= n / 2;i++)
			{
				sum += a[i].x;
				ans += a[i].z;
			}
			ans = sumy - ans;
			sum += ans;
			sort(a + 1, a + n + 1,cmp3);
			int sum2 = 0,ans2 = 0;
			for(int i = 1;i <= n / 2;i++)
			{
				sum2 += a[i].z;
				ans2 += a[i].x;
			}
			ans2 = sumx - ans2;
			sum2 += ans2;
			if(sum > sum2) cout << sum << endl;
			else cout << sum2 << endl;
		}
		if(n == 2)
		{
			for(int i = 1;i <= 3;i++)
			{
				if(i == 1)
				{
					int h = max(a[1].x + a[2].y,a[1].x + a[2].z);
					sum = max(sum,h);
				}
				if(i == 2)
				{
					int h = max(a[1].y + a[2].x,a[1].y + a[2].z);
					sum = max(sum,h);
				}
				if(i == 3)
				{
					int h = max(a[1].z + a[2].x,a[1].z + a[2].y);
					sum = max(sum,h);
				}
			}
			cout << sum << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

