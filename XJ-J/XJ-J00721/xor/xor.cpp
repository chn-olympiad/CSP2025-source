#include<bits/stdc++.h>
using namespace std;
long long a,b[1000001],k,c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>k;
	for(int i=1;i<=a;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=a;i++){
		for(int j=i;j<=a;j++)
		{
			if(b[j]==k)c++;
			if(b[j]+b[j+1]==k)
			{
				c++;
			}
		}
	}
	cout<<c;
		fclose(stdin);
		fclose(stdout);
	return 0;
} 
