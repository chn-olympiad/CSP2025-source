#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,mmax=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int md=0;int my[100001][3],a[3],q[100001];
		memset(a,0,sizeof(a));
		cin>>n;
		for(int j=0;j<n;j++) 
		{
			cin>>my[j][0]>>my[j][1]>>my[j][2];
			for(int k=0,m=-1;k<3;k++)
				if(my[j][k]>m)
					q[j]=k;
			a[q[j]]++;
		}
		while(a[0]>n/2||a[1]>n/2||a[2]>n/2)
		{
			int cha,wa,min,minn=0;
			for(int j=0;j<3;j++)
				if(a[j]>n/2)
				{
					wa=j;
					cha=a[j]-n/2;
					break;
				}
			
			
			
			
				
		}
		int cnt=0;
		for(int j=0;j<n;j++)
			cnt+=my[j][q[j]];
		cout<<cnt;
	}
	return 0;
}
