#include<bits/stdc++.h>
using namespace std;
int mp[15][15],n,m,g[110];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
    for(int i=1;i<=n*m;i++)
        cin >> g[i];//g[1]为R成绩
    int p=g[1];
    sort(g+1,g+1+(n*m),cmp);
    int k=0;
    for(int i=1;i<=m;i++)//列
    {
        for(int j=1;j<=n;j++)//行
        {
            mp[i][j]=g[++k];
            if(mp[i][j]==p)
            {
                if(i%2==0)
                    cout << i << ' ' << n-j+1;
                else
                    cout << i <<' ' << j;
                return 0;
            }
        }
    }
	return 0;
}
 
