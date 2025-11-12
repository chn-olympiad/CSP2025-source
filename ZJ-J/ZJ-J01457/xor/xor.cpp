#include<bits/stdc++.h>
using namespace std;
int n,k,a[500500],d[500500],s=0,b[500500];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x^a[i-1];
		b[i]=k^a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(d[j]==1)break;
			if(a[j]==b[i]){
				d[i-1]=1;
				s++;
				break;
			}
		}
	}
	cout<<s;
	return 0;
}

