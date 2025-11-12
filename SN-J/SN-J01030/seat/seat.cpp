#include <bits/stdc++.h>
using namespace std;
int b[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin >> n >> m;
	for(int i = 1;i <= m*n;i++)
	{
		cin >> b[i];
	}
	int xiao = b[1];
	sort(b+ 1,b+m*n+1);
	int l=1,r=m*n,mid;
	int hang,lie;
	while(b[mid] != xiao)
	{
		for(int i = l;i <= r;i++)
		{
			mid = (i+r)/2;
			if(b[mid] > xiao) r = i;
			else if(b[mid] < xiao) l = i;
			else break;
		}
    }
    mid = m*n-mid+1;
    lie = int(mid*1.0/n+0.999);
    int hang1 = mid - (lie-1)*n;
    if(lie%2==1) hang = hang1;
    else hang = n - hang1+1;
	cout << lie << ' ' << hang;
	return 0;
}
