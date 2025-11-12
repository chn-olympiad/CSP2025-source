#include<bits/stdc++.h>
using namespace std;
string zhuan(int k)
{
	string k2="";
	while(k>0)
	{
		k2=char(k%2+48)+k2;
		k=int(k/2);
	}
	return k2;
}
string yihuo(string k1,string k2)
{
	int i=0;
	string k3;
	//cout<<"diaoyong";
	while(i<k1.size() and i<k2.size())
	{
	//	cout<<k1.size();
		//cout<<k2.size();
	//	cout<<i<<"i";
		if(k1[k1.size()-i-1]==k2[k2.size()-i-1])
		{
			k3=k3+"0";
			i=i+1;
		}
		else
		{
			k3=k3+"1";
			i=i+1;
		}
	}
	if(i<k1.size())
	{
		while(i<k1.size())
		{
			k3=k1[k1.size()-i-1]+k3;
			i+=1;
		}
	}
	if(i<k2.size())
	{
		while(i<k2.size())
		{
			k3=k2[k2.size()-i-1]+k3;
			i+=1;
		}
	}
	//cout<<k3<<"/";
	return k3;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,k;
	int a[1000]={},c[1000]={};
	string b[1000]={};
	cin>>n>>k;
	string k2;
	k2=zhuan(k);
	if(k2=="")
	{
		k2="0";
	}
	int y=1;
	//cout<<k2;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=zhuan(a[i]);
		if(b[i]=="")
		{
			b[i]="0";
		}
		//cout<<b[i]<<"bi";
		if(b[i]==k2)
		{
			c[i]=y;
			y+=1;
		}
		//cout<<b[i];
		//cout<<y;
	}
	for(int i=1;i<n;i++)
	{
		if(c[i]!=1)
		{	
			for(int j=0;j<n;j=j+i)
			{
				string l="";
				if(c[j]<1 and c[j+1]<1)
				{
					l=yihuo(b[j],b[j+1]);
				}
				else
				{
					continue;
				}
				for(int q=j;q<=j+i;q+=1)
				{
					if(c[q+1]<1)
					{
						l=yihuo(l,b[q+1]);
					}
					else
					{
						break;
					}
				}
					//cout<<l;
				if(l==k2)
				{
					for(int q=j;q<j+i;q++)
					{
						c[q]=y;
						y+=1;
						//cout<<"q"<<q<<"j"<<j<<"i"<<i;
					}
				}		
			}
		}
	}
	cout<<y-1;
	return 0;
}   