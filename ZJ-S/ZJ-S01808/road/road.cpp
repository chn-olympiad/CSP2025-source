#include<bits/stdc++.h>
using namespace std;
long l[10000][10000];int a[10][10001],l2[10000][10000];
bool pda[10];int n,m,k;
long find(int c1,int c2)
{
	long min=0x7f;
	if(l2[c1][c2]==1)
		return l[c1][c2];
	if(l2[c1][c2]==2)
		return 0;
	for(int i=0;i<n;i++)
		if(l2[c1][i]!=0)
		{
			int n=find(i,c2);
			if(n+l[c1][i]<min) min=n+l[c1][i];
		}
	return min;
}

int main(){
	long long cnt=0;
	memset(l,0x7f,sizeof(l));
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		cin>>l[x][y];
		l[y][x]=l[x][y];
		l2[x][y]=l2[y][x]=1;
	}
	for(int i=0;i<k;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	for(int i=0;i<m-1;i++)
		for(int j=i+1;j<m;j++)
		{
			int fee=find(i,j);
			if(fee<l[i][j]) 
			{
				l[j][i]=l[i][j]=fee;	
				l2[j][i]=l2[i][j]=2;
			}
			for(int z=0;z<k;z++)
			{
				long f=a[z][i+1]+a[z][j+1];
				if(pda[z]==0)
					f+=a[z][0];
				if(f<l[i][j])
					l[i][j]=l[j][i]=f;
			}	
			cnt+=l[i][j];
		}
	cout<<cnt;
	return 0;
}