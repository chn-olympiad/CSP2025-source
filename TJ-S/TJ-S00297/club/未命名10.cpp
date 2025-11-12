#include<bits/stdc++.h>
using namespace std;

int t,n,hx[4];
long long ans;//十年OI一场空，不开longlong见祖宗。 
string ch;
int f;

struct pr
{
	int w,v;
};
struct stu
{
	pr p[4];
	int k;
} s[100005];

int cmp(pr a,pr b)
{
	return a.w > b.w;
}

//int ccf(stu a,stu b)
//{
//	return a.p[1].v == f and b.p[1].v == f and a.k < b.k  or  a.p[1].v == f and b.p[1].v != f;
//} //依旧遗物

int check()
{
	//if(hx[1] > n/2 or hx[2] > n/2 or hx[3] > n/2) return 0; //旧时代的遗物 
	if(hx[1] > n/2) return 1;
	if(hx[2] > n/2) return 2;
	if(hx[3] > n/2) return 3;
	return 0;
}

void suan()
{
	int o[100005],ji = 1;
	for(int i = 1;i <= n;i++)
	{
		if(s[i].p[1].v != f) continue;
		s[i].k = s[i].p[1].w - s[i].p[2].w;
		o[ji] = s[i].k;
		ji++;
		//cout << s[i].k << endl;
	}
	//sort(s+1,s+n+1,ccf);
	sort(o + 1,o + ji);
	int xl = hx[f] - (n/2);
	for(int i = 1;i <= xl;i++)
	{
		ans -= o[i];
	}
	return;
}

int main()
{
	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_osteam_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	//cout << t << endl;
	while(t--)
	{
		ans = 0;
		for(int i = 1;i <= 3;i++) hx[i] = 0;
		cin >> n;
		//cout << n << endl;
		for(int i = 1;i <= n;i++)
		{
			//input("%d,%d,%d",#s[i].p[1].w,s[i].p[2].w,s[i].p[3].w);
//			for(int j = 1;j <= 3;j++)
//			{
//				cin >> ch;
//				int x = ch.size();
//				for(int i = 1;i <= x;i++)
//				{
//					s[i].p[j].w = s[i].p[j].w << 1 + s[i].p[j].w << 3;
//					s[i].p[j].w += int(ch[x-1] - '0');
//				}
//			}
			cin >> s[i].p[1].w >> s[i].p[2].w >> s[i].p[3].w;
			cin.tie(0);
			cout.tie(0);
			//cout << s[i].p[1].w << " " << s[i].p[2].w << " " << s[i].p[3].w << endl;
			s[i].p[1].v = 1;
			s[i].p[2].v = 2;
			s[i].p[3].v = 3;
			
			sort(s[i].p+1,s[i].p+4,cmp);
			
			//cout << s[i].p[1].w << endl;
			hx[s[i].p[1].v]++;
			ans += s[i].p[1].w;
		}
		//cout << hx[1] << " " << hx[2] << " " << hx[3] << endl;
		//cout << ans << endl;
		//cout << endl;
//		for(int i = 1;i <= n;i++)
//		{
//			cout << s[i].p[1].w << " " << s[i].p[2].w << " " << s[i].p[3].w << endl;
//		}
		if(!check())
		{
			cout << ans << '\n';
			continue;
		}
		else
		{
			f = check();
			suan();
//			int xl = hx[check()] - (n/2);
//			for(int i = 1;i <= xl;i++)
//			{
//				ans -= s[i].k;
//			}
			cout << ans << '\n';
		}
	}
	return 0;
}
