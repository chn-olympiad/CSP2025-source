#include<bits/stdc++.h>
using namespace std;

const int N=500010;
int n,k,sum;
int a[N];

int ehh(int x)
{
	int cnt;
	if(x%2==0){
		cnt=0;
		x>>=1;
	}
	else{
		cnt=1;
		x>>=1;
	}
	while(x){
		if(x%2==0){
			cnt=cnt^0;
			x>>=1;
		}
		else{
			cnt=cnt^1;
			x>>=1;
		}
	}
	
}
int main()
{
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)  cin>>a[i];
	for(int l=1;l<=n;l++)
	{
		int cnt=ehh(a[l]);
		bool f=0;
		int r=l;
		for(;r<=n;r++)
		{
			cnt+=ehh(a[r]);
			if(cnt==k){
				sum++;
				f=1;
				break;
			}
		}
		if(f)  l=r+1;
	}
	cout<<sum;
	return 0;
}
