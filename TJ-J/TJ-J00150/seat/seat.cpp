#include<bits/stdc++.h>
using namespace std;
int a[1010];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,h=0;
    int id,s;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1)s=a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==s)
        {
            id=i;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            for(int j=m;j>=1;j--)
            {
                h++;
                if(h==id)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=1;j<=m;j++)
            {
                h++;
                if(h==id)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}

