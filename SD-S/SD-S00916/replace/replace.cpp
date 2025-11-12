#include<bits/stdc++.h>
using namespace std;
int a[10007][3];
struct node{
	int i;//第几名同学的满意度 
	int data;//选取的满意度的值 
};
bool f1(node x,node y)
{
	return x.data<y.data; 
}
int main()
{
	int T;
	cin>>T;
	for(int T1=1;T1<=T;T1++)
	{
		int n,m,num[4];
		vector<node> v[4];
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int maxx=0; 
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>=maxx)
				{
					m=j;
					maxx=a[i][j];
				}
			}
			num[m]++;
			node temp,temp1; 
			temp.i=i;temp.data=maxx;
			while(num[m]>(n/2))
			{
				sort(v[m].begin(),v[m].end(),f1);
				if(maxx>v[m][0])
				{
					temp1=v[m][0];
					v[m][0]=temp;
				}
			}
			
			v[m].push(temp);
		}
	}
	return 0;
}

