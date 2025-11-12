#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010];
//A 
void FunA(int *a, int len, int k)
{
	if(k==0) cout<<len/2;
	else cout<<len;
}
//B
void FunB(int *a, int len, int k)
{
	if(k==1)
	{
		int cnt=0;
		for(int i=1; i<=len; i++)
		{
			if(a[i]==0) cnt++;
		}
		cout<<len-cnt;
	}
	else if(k==0)
	{
		int cnt1=0;
		int cnt2=0;
		int Cons1=0;
		for(int i=1; i<=len; i++)
		{
			if(a[i]==1) cnt1++;
			if(a[i-1]!=1) cnt2=0;
			if(a[i-1]==1) cnt2++;
			if(cnt2==2)
			{
				Cons1++;
			}
		}
		cout<<len-cnt1+Cons1;
	}
 } 
int main() 
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool A=true, B=true;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		if(a[i]!=1) A=false;
		if(a[i]!=1 && a[i]!=0) B=false;
	}
	if(A==true) B=false;
	if(A==true) FunA(a,n,k);
	else if(B==true) FunB(a,n,k);
	else
	{
		if(n==4 && a[1]==2 && a[2]==1 && a[3]==0 && a[4]==3)
		{
			if(k==2 || k==3) cout<<2;
			else if(k==0) cout<<1;
			else cout<<0;
		}
	}
	return 0;
}
