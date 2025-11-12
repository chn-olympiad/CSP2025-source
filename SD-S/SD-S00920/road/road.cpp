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

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	
	
	return 0;
}
