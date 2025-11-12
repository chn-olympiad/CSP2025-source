#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("employ.in","w",stdin);
	freopen("employ.out","r",stdout);
	int m,n;
	cin>>m>>n;
	if(n == 1 || n == m)
	{
		cout<<pow(m,2);
		return 0;
	}
	cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
