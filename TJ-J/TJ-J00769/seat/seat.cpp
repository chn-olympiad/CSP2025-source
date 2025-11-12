#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
	freopen("seat.in","r",stdin);
	
	freopen("seat.out","w",stdout);
    int me,m,n,mi=1;
	cin>>n>>m;
	cin>>me;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>me)
		{
			mi++;
		}
	}
	int myn=mi/n+1-(mi%n==0);
	int mym=mi%n;
	if(mym==0) mym=n;
	if(myn%2==0) cout<<myn<<' '<<n+1-mym;
	else cout<<myn<<' '<<mym;
    return 0;
}
