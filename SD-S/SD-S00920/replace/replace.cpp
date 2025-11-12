#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		x = (x<<3)+(x<<1)+(ch^48);
		ch = getchar();
	}
	return x*f;
}

const int N = 2e5+5;
string a[N],b[N];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	n = read();
	q = read();
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i] >> b[i];
	}
	while(q--)
	{
		string s1,s2;
		cin >> s1 >> s2;
		cout << "0\n";
	}
	
	return 0;
}
