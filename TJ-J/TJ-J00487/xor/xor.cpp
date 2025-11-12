#include<bits/stdc++.h>
using namespace std;
int a[]={};
int f[][];
int main(){
	///freopen("xor,in","in",stdin);
	///freopen("xor,out",out.stdout);
	int n,k;
	cin>>n,k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==0)
			{
				f[i]f[j];
			}
		}
	}
	///fclose(stdin);
	///fclose(stdout);
	return 0;
}
