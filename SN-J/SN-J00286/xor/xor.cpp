#include<bits/stdc++.h>

using namespace std;
int n,k;
int num[500001];
int sum;
struct Area{
	int head_;
	int bail_;
	int quan_;
};
int xor_;
int m=1;
int mx;
int t;
int main(){
	cin>>n>>k;
	num[0]=0;
	for(int i=1;i<=n;i++)
	{ 
		cin>>num[i];
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n-i;j++)
		{
			xor_=num[i];
			for(int k=i+1;k<=i+j;k++)
			{
				xor_=(xor_^num[k]);
			}
			 int (xor_==k);
			{
			
				t[m].head_=i;
				t[m].bail_=i+j-1;
				t[m].quan_=back(t);
				m++;
				cout<<i<<""<<i+j<<" "<<xor_<<endl;
			};
		}
	}
	return 0;
}
