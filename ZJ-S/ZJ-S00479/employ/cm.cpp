#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define G(i,l,r) for(int i=(l),i##end=(r);i>=i##end;--i)
#define ep emplace_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

int main()
{
	int t=0;
	while(++t)
	{
		cerr<<t<<'\n';
		system("./gen >1.in");
		system("./bf <1.in >1.ans");
		system("./employ <1.in >1.out");
		if(system("diff 1.out 1.ans"))break;
	}
	return 0;
}
