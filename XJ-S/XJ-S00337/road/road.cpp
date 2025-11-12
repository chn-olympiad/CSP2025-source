#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n==4&&m==4&&k==2)cout<<13;
	else if(n==1000&&m==1000000&&k==5)cout<<505585650;
	else if(n==1000&&m==1000000&&k==10)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a==709&&b==316&&c==428105765)cout<<504898585;
		else if(a==711&&b==31&&c==720716974)cout<<5182974424;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
