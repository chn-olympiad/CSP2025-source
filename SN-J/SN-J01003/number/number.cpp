#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int a[1000000];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0;
	string s;
	cin>>s;
	for(int i=0;i<1000000;i++)
	{
		if(s[i]>=1&&s[i]<=9){
			a[i]=s[i];
			cnt++;
		}
	}
	sort(a,a+cnt+1);
	for(int i=cnt;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
