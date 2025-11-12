#include<bits/stdc++.h>
using namespace std;
string a;
long long int i,b[1000006],k;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(i=0;i<a.size();i++)
	if(a[i]>='0'&&a[i]<='9')
	b[++k]=a[i]-'0';
	sort(b+1,b+1+k,greater<int>());
	for(i=1;i<=k;i++)
	cout<<b[i];
	return 0;
}
