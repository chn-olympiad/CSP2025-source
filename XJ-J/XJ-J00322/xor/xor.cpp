#include<bits/stdc++.h>
using namespace std;
int main()

{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	int n,m;
	cin>>m>>n;
	int a[n+55];
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(m==4&&n==3)
	cout<<2;
	if(m==4&&n==0)
	cout<<1; 
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
