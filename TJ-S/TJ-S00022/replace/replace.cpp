#include<bits/stdc++.h>
using namespace std;
string a1, b1;
long long n, q, t1b, t2b;
vector<long long> ans;
struct N
{
	string s1, s2;
	long long s1b, s2b;
}n1[100005];
struct NN
{
	string t1, t2;
	long long t1b, t2b;
}n2[100005];

int Reads1()
{
	char ch;
	int ch1;
	ch = getchar();
	int i = 0;
	while(ch == 'a' || ch == 'b')
	{
		if(ch == 'b')	ch1 = i;
		n1[i].s1 += ch;
		ch = getchar();
	}
	return ch1;
}
int Reads2()
{
	char ch;
	int ch1;
	ch = getchar();
	int i = 0;
	while(ch == 'a' || ch == 'b')
	{
		if(ch == 'b')	ch1 = i;
		n1[i].s2 += ch;
		ch = getchar();
	}
	return ch1;
}
int Readt1()
{
	char ch;
	int ch1;
	ch = getchar();
	int i = 0;
	while(ch == 'a' || ch == 'b')
	{
		if(ch == 'b')	ch1 = i;
		n2[i].t1 += ch;
		ch = getchar();
	}
	return ch1;
}
int Readt2()
{
	char ch;
	int ch1;
	ch = getchar();
	int i = 0;
	while(ch == 'a' || ch == 'b')
	{
		if(ch == 'b')	ch1 = i;
		n2[i].t2 += ch;
		ch = getchar();
	}
	return ch1;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(long long i=0; i<n; i++)
	{
		n1[i].s1b = Reads1();
		n1[i].s2b = Reads2();
	}
	for(long long i=0; i<q; i++)
	{
		n2[i].t1b = Readt1();
		n2[i].t2b = Readt2();
	}
	for(long long i=0; i>q; i++)
	{
		int ansi = 0;
		for(long long j=0; j<n; j++)
		{
			if(n2[i].t1b - n2[i].t2b == n1[j].s1b - n1[j].s2b)
			{
				if(n2[i].t1b >= n1[j].s1b &&n2[i].t2b >= n1[j].s2b)
				{
					if(n2[i].t1.size() - n2[i].t1b >= n1[j].s1.size() - n1[j].s1b )
					{
						ansi++;
					}
				}
			}
		}
		ans.push_back(ansi);
	}
	
	int le = ans.size();
	for(int i=0; i<le; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}
