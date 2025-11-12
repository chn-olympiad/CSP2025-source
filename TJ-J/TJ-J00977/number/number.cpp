#include<iostream>
#include<algorithm>
using namespace std;
long long a[1000005],sum=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++)
	{
		if(n[i]>='0'&&n[i]<='9')
		{		
			a[sum]=int(n[i])-48;
				sum++;
		 }
	}
	sum--;
	sort(a+1,a+1+sum);
	for(int i=sum;i>=1;i--) cout<<a[i];
	return 0;
}

