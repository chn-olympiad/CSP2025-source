#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,so,cnt=1;
    cin>>n>>m;
    cin>>so;
    for(int i = 2;i<=n*m;i++)
    {
        cin>>s;
        if(s>so)
            cnt++;
    }
    int mo=cnt/n+1;
    if(cnt%n==0)
    	mo--;
    cout<<mo<<" ";
    int v=cnt%n;
    if(v==0)v+=n;
    if(mo%2==1)
    {
        cout<<v;
    }
    else
    {
        cout<<n-v+1;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
