#include<bits/stdc++.h>
using namespace std;
#define int long long
int randint(int x,int y)
{
	int t=(rand()<<15)+rand();
	return t%(y-x+1)+x;
}
signed main()
{
	srand(time(0));
	return 0;
}

