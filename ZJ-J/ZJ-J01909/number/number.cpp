#include <bits/stdc++.h>
using namespace std;
const int N=1000001,M=1001;
int n,f[M];
char a[N];
int main ()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);cout.tie (0);
	cin >>a+1;
	n=strlen (a+1);
	for (int i=1;i<=n;i++)
		if (a[i]>='0'&&a[i]<='9') f[a[i]-'0']++;
	for (int i=9;i>=0;i--)
		while (f[i]!=0) cout <<i,f[i]--;
	return 0;
}
