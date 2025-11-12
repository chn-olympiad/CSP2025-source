#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int h=1e5+9;
int n,t[10];
int d[h][5];
int a[h*2][5],b[h*2][5],o[10];
void push(int r,int f,int l)
{
	o[l]+=r;
	a[++t[l]][l]=r;
	b[t[l]][l]=f;
	int k=t[l];
	while(k!=1&&a[k][l]<a[k/2][l])
	{
		swap(a[k][l],a[k/2][l]);
		swap(b[k][l],b[k/2][l]);
		k/=2;
	} 
}
void pop(int l)
{
	o[l]-=a[1][l];
	swap(a[1][l],a[t[l]][l]);
	swap(b[1][l],b[t[l]][l]);
	
	a[t[l]--][l]=1e6+9;
	b[t[l]][l]=0;
	int k=1;
	while(k<=t[l])
	{
		if(a[k*2][l]<a[k][l]&&a[k*2+1][l]<k)
		{
			if(a[k*2][l]<a[k*2+1][l])
			{
				swap(a[k][l],a[k*2][l]);
				swap(b[k][l],b[k*2][l]);
			}
			
			else
			{
				swap(a[k][l],a[k*2+1][l]);
				swap(b[k][l],b[k*2+1][l]);
			}
			
		 } 
		else if(a[k*2][l]<a[k][l])
		{
			swap(a[k*2][l],a[k][l]);
			swap(b[k*2][l],b[k][l]);
		}
		else if(a[k*2+1][l]<a[k][l])
		{
			swap(a[k*2+1][l],a[k][l]);
			swap(b[k*2+1][l],b[k][l]);
		}
		else break;
	}
}
signed main()
{
//	freopen("club1.in","r",stdin);
//	freopen("club.out","w",stdout);
	int yy;
	cin>>yy;
	while(yy--)
	{
		memset(d,sizeof(d),0);
		memset(a,sizeof(a),1e5);
		memset(b,sizeof(b),0);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i][1]>>d[i][2]>>d[i][3];
			d[i][5]=max(d[i][1],max(d[i][2],d[i][3]));
			if(d[i][5]==d[i][1])d[i][4]=1,d[i][6]=2,d[i][7]=3;
			if(d[i][5]==d[i][2])d[i][4]=2,d[i][6]=1,d[i][7]=3;
			if(d[i][5]==d[i][3])d[i][4]=3,d[i][6]=1,d[i][7]=2;
		}
		for(int i=1;i<=n;i++)
		{
			int l=d[i][4];
			if(t[l]<n/2){
				push(d[i][l],i,l);
			}
			else{
				int p=a[1][l],q=b[1][l],h=max(d[q][d[q][6]],d[q][d[q][7]]),w;
				if(h==d[q][d[i][6]]) w=d[q][6];
				else w=d[q][7];
				if(d[i][l]+h>p)
				{
					push(d[q][w],q,w);
					push(d[i][l],i,l);
					pop(l);
				}
				else
				{
					if(l==3)
					{
						if(d[i][1]>d[i][2]){
						push(d[i][1],i,1);
						}
						else push(d[i][2],i,2);
					}
					if(l==2)
					{
						if(d[i][1]>d[i][3]){
						push(d[i][1],i,1);
						}
						else push(d[i][3],i,3);
					}
					if(l==1)
					{
						if(d[i][2]>d[i][3]){
						push(d[i][2],i,2);
						}
						else push(d[i][3],i,3);
					}
				}
			}
		}
		cout<<o[1]+o[2]+o[3]<<endl;
	}
	return 0;
} 
				
	
