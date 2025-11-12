#include<bits/stdc++.h>
using namespace std;
int b[105];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,x;//n；行  m；列  x；人 
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	x=b[1];
	
	sort(b,b+1);
	
	for(int i=n*m;i>=1;i--)
	{
		
		if(b[i]==x)//找到位置 
		{
			if((n*m+1-i)%n==0)//如果整列 
			{
				cout<<(n*m+1-i)/n;//输出列 （开始求行） 
				
				if((n*m+1-i)%(2*n)==0 && (n*m+1-i)%(2*n)==1)//如果两列一组 (整+1） 
				{
					cout<<1<<" ";
				}
				else
				{
					cout<<n<<" ";
				}
			}else//如果非整列
			{
				cout<<(n*m+1-i)/n+1;//输出列（开始求行）
				
				int o=(n*m+1-i)%(2*n);	
					
				if(o<n)
				{
					cout<<o<<" ";
				}else
				{
					cout<<2*n-o<<" ";
				}
				
			
			}
		}
	}
	
	return 0;
}
