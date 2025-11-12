#include<bits/stdc++.h> 
using namespace std;
#define mid (l+r)/2
int a[500005];
int q[500005];
int bj[2000005];
int tag[2000005];
int bj1[500005];
void updown(int idx,int l,int r,int n,int m)
{
	if(tag[idx]==1)
	{
		bj[idx<<1]=1;
		bj[idx<<1|1]=1;
		tag[idx<<1]=1;
		tag[idx<<1|1]=1;
		tag[idx<<1]=0;
	}
	return;
}
void update(int idx,int l,int r,int n,int m)
{
	if(r<n||m<l)
	{
		return;
	}
	if(n<=l&&r<=m)
	{
		bj[idx]=1;
		tag[idx]=1;
		return;
	}
	updown(idx,l,r,n,m);
	update(idx<<1,l,mid,n,m);
	update(idx<<1|1,mid+1,r,n,m);
	if(bj[idx<<1]==1||bj[idx<<1|1]==1)
	bj[idx]=1;
	else
	bj[idx]=0;
}
int query(int idx,int l,int r,int n,int m)
{
	if(r<n||m<l)
	{
		return 0;
	}
	if(n<=l&&r<=m)
	{
		return bj[idx];
	}
	updown(idx,l,r,n,m);
	int q1=query(idx<<1,l,mid,n,m);
	int q2=query(idx<<1|1,mid+1,r,n,m);
	if(q1==1||q2==1)
	return 1;
	else
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    long long n,k,qjs=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
		if(a[i]==k)
		{
			qjs++;
			update(1,1,n,i,i);
			bj1[i]=1;
		}	
	}
	q[0]=0;
	q[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		q[i]=q[i-1]^a[i];
	}
	for(int i=2;i<=n;i++)//³¤¶È 
	{
		for(int j=1;j<=n-i+1;j++)
		{
		//	cout<<"*"<<j<<" "<<i<<endl;
			if(query(1,1,n,j,j+i-1)==0)
			{
		//		cout<<")))"<<endl;
		//		cout<<query(1,1,n,j,j+i)<<endl;
				if((q[j+i-1]^q[j-1])==k)
				{
					qjs++;
			//		cout<<i<<" "<<j<<" "<<q[j+i-1]<<" "<<q[j-1]<<" "<<j-1<<" "<<k<<" "<<(q[j+i-1]^q[j-1])<<" "<<a[i]<<" "<<qjs<<endl;
		//			cout<<"))"<<endl;
					update(1,1,n,j,j+i-1);
					for(int k1=j;k1<=j+i-1;k1++)
					{
						bj1[k1]=1;
					}
		//			cout<<q[j+i]<<" "<<q[j-1]<<" "<<j-1<<" "<<k<<" "<<(q[j+i]^q[j-1])<<endl;
		//			cout<<j<<" "<<j+i<<" "<<qjs<<endl;
					
				}
			}
			else if(bj1[j+i-1]==1)
			{
		//		cout<<i<<" "<<j<<"&"<<endl;
				j+=(i-2);
			}
//			else
//			{
//				j++;
//			}
		//	cout<<j<<endl;
		}
	}
	cout<<qjs;
	return 0;
}
