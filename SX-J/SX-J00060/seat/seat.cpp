#include<bits/stdc++.h>
using namespace std;
struct ren
{
	int cj,n,m;
}r[150];
int main()
{
	//freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m,ll,mc=0,c,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
    	cin>>r[i].cj;
        ll=r[i].cj;
	}
	sort(r+1,r+n*m+1);
	for(int i=1;i<=n*m;i++)
    {
        mc++;
    	if(r[i].cj==ll)
    	{
    		break;
		}
	}
	mc=(n*m-mc)+1;
    if(mc==1) cout<<"1"<<" "<<"1";
    else if()
    {

	}
	return 0;
}