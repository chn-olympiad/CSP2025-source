#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,s,d[100001],f[100001],g=0,z,x=0;
	cin>>a>>s;
	cin>>g;
	f[0]=g;
	for(int i=0;i<a*s-1;i++)
	{
		cin>>f[i+1];
	}
	/*for(int i=0;i<a*s;i++)
	{
		cout<<f[i]<<" ";
	}
	*/
	for(int i=0;i<a*s;i++)
	{
		int q=0,w=0,e=0;
		for(int j=0;j<a*s;j++)
		{
			if(f[j]>=q&&f[j]!=-1)
			{
				q=f[j];
				w=j;
				e=i;
			}
		}
		d[i]=q;
		f[w]=-1;
		cout<<q<<" "<<e<<endl;
		if(q==g)
		{
			z=i;
			break;
		}
	}
	z++;
	cout<<z<<endl;
	x=z/a;
	if(0<z%a&&z%a<a)
	{
		x++;
	}
	z=z%a;
		if(x%2==0)
		{
			cout<<x<<" "<<a-z+1;
		}
		else
		{
			cout<<x<<" "<<z;
		}
	return 0;
}
