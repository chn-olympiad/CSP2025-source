#include<bits/stdc++.h>
using namespace std;
const int N=114514;
int n,m;
int a[100005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int r;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			r=a[i];
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(a[j]<a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	int y=1;
	int yn=n+1;
	int x=1;
	for(int i=1;i<=n*m;i++)
	{
		if(i==yn)
		{
			y+=1;
			yn+=n;
			if(y%2==0){
				x=n;
			}else if(y%2==1){
				x=1;
			}
		}
		if(a[i]==r)
		{
			cout<<y<<" "<<x;
			return 0;
		}
		if(y%2==0){
			x--;
		}else if(y%2==1){
			x++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
