#include<bits/stdc++.h>
using namespace std;
bool cmp(int x, int y)
{
	return x>y;
}
int a[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	
	int n,m,cnt;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			cnt=i;
		}
		//cout<<a[i]<<" ";
		
	}
	//cout<<endl;
	//cout<<"cnt:"<<cnt<<endl;
	int w=cnt/n;
	int f=cnt-w*n;
	if(f!=0)
	{
		w++; 
	}
	if(f==0&&w%2==0)
	{
		cout<<w<<" "<<1<<" ";
		return 0;
	}
	if(f==0&&w%2==1)
	{
		cout<<w<<" "<<n;
		return 0;
	}
	if(w%2==1)
	{
		cout<<w<<" "<<f;
		return 0; 
	}
	else
	{
		cout<<w<<" "<<n-f+1;
		return 0; 
	}
	return 0; 
}
