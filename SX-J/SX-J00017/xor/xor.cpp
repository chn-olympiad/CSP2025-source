#include<bits/stdc++.h>
using namespace std;
int s[10010];
int main()
{
	int a,b;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
		cin>>s[i];
	if(b!=0)	cout<<"2";
	else		cout<<"1";
}