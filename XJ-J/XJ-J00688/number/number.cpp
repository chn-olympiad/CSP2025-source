#include<bits/stdc++.h>
using namespace std;
long long s[10001],t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[10001];
	cin>>a;
	int maxx=0;
	for(int i=0;i<10001;i++)
	{
		int a[i];
		if(a[i]>maxx){
			maxx=a[i];
		}else if(a[i]=maxx){
			t=i;
		}
		
	 } 
	 cout<<a;
	return 0;
}
