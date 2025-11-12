//陈柏霖，SN-J00747,西安市曲江第一中学 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("club.in","r",stdin)
	//freopen("club.out","w",stdout)
	int n,t;
	cin>>t;
	int s,k;
	for(int e=0;e<t;e++)
	{
		cin>>n;
		int a[n][3]={};
		for(int i=0;i<n;i++)
		{
			for(int r=0;r<3;r++) cin>>a[i][r];
		}
		s=0;
		int b[3]={0,0,0};//b-department amount
		int m[3]={};
		for(int i=0;i<n;i++)//i-people,j-department
		{			
			for(int r=0;r<3;r++) m[r]=a[i][r];
			sort(m,m+3);
			for(int j=0;j<3;j++)
			{
				k=2;
				if(b[j]<n/2)
				{
					s+=m[k];
					b[j]++;
				}
				else
				{
					k--;
					b[j+1]++;
				}
			}
			
		}
		cout<<s<<endl;
	}
	return 0;
}
