#include<bits/stdc++.h>
using namespace std;
string a;
int sum=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int b[1000005];
	int len=a.size();
	for(int i=1;i<=len-1;i++)
	{
		if(a[i]>='1'&&a[i]<='9')
		{
			b[sum]=a[i]-'1'+1;
			sum++;
		}
	}
	(b+1,b+sum+1,cmp);
	int ant;
	for(int i=1;i<=sum;i++)
	{
		ant=ant*10+b[i];
	}
	cout<<ant<<endl;
	return 0;
}