#include<bits/stdc++.h>
using namespace std;
long long a,b[1000001],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(long long i=1;i<=a;i++)
	{
		cin>>b[i];
	}
	for(long long i=3;i<=a;i++)
	{
		for(long long j=1;j<=a;j++)
		{
			if(b[j]+b[j+1]+b[j+2]>max(b[j],max(b[j+1],b[j+2])))
			{
				n++;
			}
		}
	}
	cout<<n;
		fclose(stdin);
		fclose(stdout);
	return 0;
} 
