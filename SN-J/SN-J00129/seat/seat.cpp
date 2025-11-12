#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r,s[10005];
	cin>>c>>r;
	for(int i=0;i<c;i++)
	{
		cin>>s[i];
	}
	for(int j=1;j<=c;j++)
	{
		cin>>s[j];
	}
	cout<<c<<endl;
	return 0;
    fclose(stdin);
    fclose(stdout);
}
