#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][5],b[100005],ans;
void bp(int step,int sum,int p1,int p2,int p3)
{
	if (p1>n/2||p2>n/2||p3>n/2)
		return;
	if (step==n)
	{
	    if (p1<n/2)
            ans=max(sum+a[step][1],ans);
        if (p2<n/2)
            ans=max(sum+a[step][2],ans);
        if (p3<n/2)
            ans=max(sum+a[step][3],ans);
		return;
	}
	bp(step+1,sum+a[step][1],p1+1,p2,p3);
	bp(step+1,sum+a[step][2],p1,p2+1,p3);
	bp(step+1,sum+a[step][3],p1,p2,p3+1);
}
bool checkA()
{
    for (int i=1;i<=n;i++)
    {
        if (a[i][2]!=0||a[i][3]!=0)
            return false;
    }
    return true;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T--)
	{
	    ans=0;
		cin >> n;
		for (int i=1;i<=n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			b[i]=a[i][1];
		}
		if (checkA())
        {
            sort(b+1,b+n+1);
            for (int i=n/2+1;i<=n;i++)
                ans+=b[i];
            cout << ans << endl;
        }
		bp(1,0,0,0,0);
		cout << ans << endl;
	}
	return 0;
}
