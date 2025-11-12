//SN-J01181 高思童 西安滨河学校
#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	int n;
	int k;
	int a[10000];
	cin>>n>>k;
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
		k=a[i];
	}
	n=a[0];
	cout<<(n+k)*k/2;
	return 0;
 } 

