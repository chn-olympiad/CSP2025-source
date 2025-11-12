#include<bits/stdc++.h>
using namespace std;
string a;
int n[1000005],b[1000005];
int main()
{
	for(int i=1;i<=1000005;i++)
	{
		n[i]=-1;
	}
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	
	cin>>a;
	int k=a.size();
	 sort(n+1,n+1+a.size());
	 for(int i=1;i<=a.size();i++,k--)
	 {
	 	b[i]=n[i];
	 	if(k==-1)break;
	 	cout<<b[i];
	 }
	return 0;
}
