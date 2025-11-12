#include <bits/stdc++.h>
using namespace std;
int n,s[5010],alli[5010];
long long int canping = 0;
bool isA=0;
bool ispol(int alld[],int end)
{
	long long int maxn = -1,sum=0;
	for (int i=0;i<=end;i++)
	{
		sum += s[alld[i]];maxn = max(maxn,(long long int)(s[alld[i]]));
		//cout << s[alld[i]] << " "; 
	}
	return sum > maxn * 2;
}
void te(int i)
{
	long long int ad = 1,ad2=1;
	long long int ad3 = 1,ad4=1;
	for (int j=1;j<=i;j++)
	{
		if (ad *= j < ad) ad3 *= j;
		else ad *= j;
		if (ad2 *= (n-(j-1)) < ad2) ad4 *= j;
		else ad2 *= (n-(j-1));
		if (ad > 1e9 or ad2 > 1e9)
		{
			long long int ndd = __gcd(ad,ad2);
			ad /= ndd;
			ad2 /= ndd;
		}
		if (ad3 > 1e9 or ad4 > 1e9)
		{
			long long int ndd = __gcd(ad3,ad4);
			ad3 /= ndd;
			ad4 /= ndd;
		}
	}
	canping = canping + (ad2 / ad);
	if (canping > 998244353)
	{
		canping = canping % 998244353;
	}
}
void solve(int cnt,int Scnt)
{
	if (cnt+1 == Scnt)
	{
		if (isA == 1)
		{
			canping += (n - alli[cnt-1]);
			if (canping > 998244353)
			{
				canping = canping % 998244353;
			}
			return ;
		}
		for (int i=alli[cnt-1]+1;i<n;i++)
		{
			alli[cnt] = i;
			canping += ispol(alli,cnt);
			if (canping > 998244353)
			{
				canping = canping % 998244353;
			}
			//cout << "canping: " << canping << endl;
		}
		return ;
	}
	int st = 0;
	if (cnt > 0) st = alli[cnt-1]+1;
	for (alli[cnt]=st;alli[cnt]<n;alli[cnt]++)
	{
		solve(cnt+1,Scnt);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int maxx = -1;
	for (int i=0;i<n;i++)
	{
		cin >> s[i];
		maxx = max(maxx,s[i]);
	}
	if (maxx == 1) isA = true;
	//cout << maxx;
	for (int i=3;i<=n;i++)
	{
		if (isA)
		{
			te(i);
			//solve(0,i);
		}
		else
		{
			solve(0,i);
		}
	}
	cout << canping % 998244353;
	return 0;
} 
