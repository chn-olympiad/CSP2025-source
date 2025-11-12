#include <iostream>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;

struct node
{
	int a,b,c;
	int fi()
	{
		if(a >= b && a >= c) return 1;
		if(b >= a && b >= c) return 2;
		if(c >= a && c >= b) return 3;
		return 0;
	}
	int se()
	{
		if(fi() == 1)
		{
			if(b >= c) return 2;
			return 3;
		} 
		if(fi() == 2)
		{
			if(a >= c) return 1;
			return 3;
		}
		if(fi() == 3)
		{
			if(a >= b) return 1;
			return 2;
		} 
		return 0;
	}
}d[100005],tmp[100005];

int e1[100005];
int e2[100005];
int e3[100005];

bool cmp(int a,int b)
{
	int X = d[a].fi();
	int Y = d[b].fi();
	switch(X)
	{
		case 1: X = d[a].a;break;
		case 2: X = d[a].b;break;
		case 3: X = d[a].c;break;
	} 
	switch(Y)
	{
		case 1: Y = d[b].a;break;
		case 2: Y = d[b].b;break;
		case 3: Y = d[b].c;break;
	} 
	int XX = d[a].se();
	int YY = d[b].se();
	switch(XX)
	{
		case 1: XX = d[a].a;break;
		case 2: XX = d[a].b;break;
		case 3: XX = d[a].c;break;
	} 
	switch(YY)
	{
		case 1: YY = d[b].a;break;
		case 2: YY = d[b].b;break;
		case 3: YY = d[b].c;break;
	} 
	return X - XX > Y - YY;
}

void Main()
{
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> d[i].a >> d[i].b >> d[i].c;
	}
	int cnt[5] = {};
	for(int i = 1;i <= n;i++)
	{
		if(d[i].fi() == 1) e1[++cnt[1]] = i;
		if(d[i].fi() == 2) e2[++cnt[2]] = i;
		if(d[i].fi() == 3) e3[++cnt[3]] = i;
	}
//	cout << "G1:";
//	for(int i = 1;i <= cnt[1];i++)
//	{
//		cout << e1[i] << " ";
//	}
//	cout << endl;
//	cout << "G2:";
//	for(int i = 1;i <= cnt[2];i++)
//	{
//		cout << e2[i] << " ";
//	}
//	cout << endl;
//	cout << "G3:";
//	for(int i = 1;i <= cnt[3];i++)
//	{
//		cout << e3[i] << " ";
//	}
//	cout << endl;
	if(cnt[1] > n / 2)
	{
//		cout << "G1: too many." << endl;
		sort(e1 + 1,e1 + cnt[1] + 1,cmp);
//		for(int i = 1;i <= cnt[1];i++) /////////////
//		{
//			cout << e1[i] << " ";
//		}
//		cout << endl; ///////////////
		for(int i = n / 2 + 1;i <= cnt[1];i++)
		{
			tmp[i - n / 2] = d[e1[i]];
		}
		for(int i = 1;i <= cnt[1] - n / 2;i++)
		{
			if(tmp[i].se() == 2) e2[++cnt[2]] = e1[i + n/2];
			if(tmp[i].se() == 3) e3[++cnt[3]] = e1[i + n/2];
		}
		cnt[1] = n / 2;
	}
	if(cnt[2] > n / 2)
	{
//		cout << "G2: too many." << endl;
		sort(e2 + 1,e2 + cnt[2] + 1,cmp);
//		for(int i = 1;i <= cnt[2];i++) /////////////
//		{
//			cout << e2[i] << " ";
//		}
//		cout << endl; ///////////////
		for(int i = n / 2 + 1;i <= cnt[2];i++)
		{
			tmp[i - n / 2] = d[e2[i]];
		}
		for(int i = 1;i <= cnt[2] - n / 2;i++)
		{
			if(tmp[i].se() == 1) e1[++cnt[1]] = e2[i + n/2];
			if(tmp[i].se() == 3) e3[++cnt[3]] = e2[i + n/2];
		}
		cnt[2] = n / 2;
	}
	if(cnt[3] > n / 2)
	{
//		cout << "G3: too many." << endl;
		sort(e3 + 1,e3 + cnt[3] + 1,cmp);
//		for(int i = 1;i <= cnt[3];i++) /////////////
//		{
//			cout << e3[i] << " ";
//		}
//		cout << endl; ///////////////
		for(int i = n / 2 + 1;i <= cnt[3];i++)
		{
			tmp[i - n / 2] = d[e3[i]];
		}
		for(int i = 1;i <= cnt[3] - n / 2;i++)
		{
			if(tmp[i].se() == 1) e1[++cnt[1]] = e3[i + n/2];
			if(tmp[i].se() == 2) e2[++cnt[2]] = e3[i + n/2];
		}
		cnt[3] = n / 2;
	}
	int ans = 0;
//	cout << "G1:";
	for(int i = 1;i <= cnt[1];i++)
	{
		ans += d[e1[i]].a;
//		cout << e1[i] << " ";
	}
//	cout << endl;
//	cout << "G2:";
	for(int i = 1;i <= cnt[2];i++)
	{
		ans += d[e2[i]].b;
//		cout << e2[i] << " ";
	}
//	cout << endl;
//	cout << "G3:";
	for(int i = 1;i <= cnt[3];i++)
	{
		ans += d[e3[i]].c;
//		cout << e3[i] << " ";
	}
//	cout << endl;
	cout << ans << endl;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	for(;T--;)
	{
//		cout << "Test #" << T << ":\n";
		Main();
	}
	return 0;
}
