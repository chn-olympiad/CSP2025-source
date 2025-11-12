#include<bits/stdc++.h>
using namespace std;
int m[1000000];
int m1[1000000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k,num=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
    	cin>>m[i];
    	if(m[i]==k)
    	{
    		num++;
		}
    	
	}
	cout<<num; 
	return 0;
}
