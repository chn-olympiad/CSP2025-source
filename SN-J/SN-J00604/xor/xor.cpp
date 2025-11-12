//杨俊楠 SN-J00604 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
void calc(int n,int left,int k,int a[],int &count);
void calc(int n,int left,int k,int a[],int &count)
{
	int sbreak=0;
		for(int i=left+1;i<=n;i++)
		{
			
			for(int j=i;j<=n;j++)
			{
				//calc xor
				int res=0;
				res=a[i];
				if(res!=k&&a[j]!=k)
				{
					for(int q=i;q<=j&&q<=n;q++)
					{
						if(q==i) continue;
						res=(res xor a[q]);
					}
					
				}
				if(a[j]==k)
				{
					left=j;
					count++;
					//cout<<left<<" detail "<<" num="<<a[j]<<" count="<<count<<" res="<<res<<endl;
					sbreak=1;break;
				}
				if(res==k)
				{
					left=j;
					count++;
					sbreak=1;
					//cout<<left<<" detail i="<<i<<" j="<<j<<" count="<<count<<" res="<<res<<endl;
					break;
				}
			}
			if(sbreak=1) break;
			
		}
		if(left!=n) calc(n,left,k,a,count) ;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500005];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int left=0,count=0;
	
	calc(n,left,k,a,count);
		
	cout<<count;
	return 0;
}
