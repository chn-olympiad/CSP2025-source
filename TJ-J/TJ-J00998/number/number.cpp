#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
char a[maxn];
char c[maxn];
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	int ln = strlen(a);
	int cnt=0;
	for(int i=0;i<ln;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
            c[cnt]=a[i];
			cnt++;
		}
    }
	sort(c,c+cnt);
	for(int i=cnt-1;i>=0;i--)
	{
		cout << c[i];
	}
	return 0;
 }
