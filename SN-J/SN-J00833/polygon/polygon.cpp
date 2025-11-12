//SN-J00833 白敬轩 西安高新一中沣东中学 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a,b,c,maxx,sum;
	cin >> n >> a >> b >> c;
	sum = a+ b + c;
	if(a > b)maxx=a;
	else maxx =b;
	if(c > maxx)maxx=c;
	
	if(maxx * 2 < sum)
	{
		cout << 1;
	}
	else
		cout << 0;
 } 
