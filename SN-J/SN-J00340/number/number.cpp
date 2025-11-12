#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long s;
	int a[9],ans;
	cin>>s;
	for(int i=1;i<=s;i++)
	{
		if(s>=1||s<=9)
		{
			a[i]=s;
			ans++;
		}
	}
	for(int j=1;j<=ans;j++)
	{
		if(a[0]<a[j])
		{
			a[0]=a[j];
		}
	}
	cout<<a;
	return 0;
}
