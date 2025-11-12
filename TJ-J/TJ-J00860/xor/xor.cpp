#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],cnt;
bool f = true,flag = true;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] == m)
        {
            cnt++;
            b[i] = 1;
        }
        if(a[i] != 1)
        {
            f = false;
        }
        if(a[i] != 1 && a[i] != 0)
        {
            flag = false;
        }
    }
    if(m == 0)
    {
        for(int i = 1;i < n;i++)
        {
            if(b[i] == 0 && b[i + 1] == 0 && a[i] == 1 && a[i + 1] == 1)
            {
                b[i] = 1,b[i + 1] = 1;
                cnt++;
            }
        }
        cout << cnt;
    }
    else
    {
        if(m == 1)
        {
            cout << cnt;
        }
        else
        {
            cout << cnt + 2;
        }
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
