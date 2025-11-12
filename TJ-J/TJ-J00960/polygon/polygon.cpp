#include <bits/stdc++.h>
using  namespace std;
int main ()
{
	freopen("polygon.in","r",stdin)
	freopen("polygon.out","w",stdout)
	int n[};
	int a,cnt,m;
	int maxn =0;
	cin >> a;
	for(int i = 1;i<= a;i++)
	{
		cin >> n[i];
		cnt +=i;
		if(i>maxn) maxn = i;
		if(cnt >2*maxn) m +=1;
	}
	cout << m;
	
	
	return 0;
}
