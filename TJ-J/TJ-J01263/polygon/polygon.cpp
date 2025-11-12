#include<bits/stdc++.h>
using namespace std;
int n;
int edge=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int k=3;k<n;k++)
		for(int i=0;i<n;i++){
			int ans=1;
			int jg[k];
			jg[0]=a[i];
			for(int j=i+1;ans<=k;ans++) 
			{
				jg[ans]=a[j];
			}
			int op=0;
			for(int j=0;j<k;j++)
			{
				op+=jg[j];
			}
			if(jg[k-1]<op/2)
			{
				edge++;
			}
		}
	cout<<edge;
}
