#include<iostream>
#include<cmath>
using namespace std;
	int a[1005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-48;
			j++;
		}
	}
	int sum=0;
	while(1)
	{
		sum=0;
		for(int i=1;i<j;i++)
		{
			if(a[i]>a[i-1]){
				swap(a[i],a[i-1]);
				sum++;
			}
		}
		if(sum==0) break;
	}
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}