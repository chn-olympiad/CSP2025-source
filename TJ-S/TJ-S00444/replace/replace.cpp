#include<bits/stdc++.h>
using namespace std;
int n,q;

struct lan
{
	string a;
	string b;
	int delta;
	int fo,ba;
}lans[200009];

bool usd[200009];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>lans[i].a>>lans[i].b;
		string a = lans[i].a;
		string b = lans[i].b;
		int posA = a.find("b");
		int posB = b.find("b");
		int delta = posA-posB;
		lans[i].delta = abs(delta);
		int fo = posA;
		int ba = posB;
		lans[i].fo = fo;
		lans[i].ba = a.size() - ba;
	}
	for(int qqq = 0;qqq<q;++qqq)
	{
		string sa,sb;
		cin>>sa>>sb;
		memset(usd,0,sizeof(usd));
		int posA = sa.find("b");
		int posB = sb.find("b");
		int cdt = posA - posB;
		int cur_ans = 0;
		for(int i=1;i<=n;++i)
		{
			if(usd[i]) continue;	
			if(abs(lans[i].delta) == abs(cdt) && posA >= lans[i].fo && sa.size() - posB >= lans[i].ba)
			{
				cur_ans++;
				usd[i] = 1;
			}
		}
		cout<<cur_ans<<"\n";
	}
	return 0;
} 
