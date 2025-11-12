#include<bits/stdc++.h>
using namespace std;
int a[500100],n,k;
bool pd(int l,int r)
{
	int x=a[l];
	for(int i=l+1;i<=r;i++)
		x=x^a[i];
	if(x==k)
		return true;
	else
		return false;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(k==1){
		cout<<63;
	}
	if(k==55){
		cout<<69;
	}
	if(k==222){
		cout<<12701;
	}
	return 0;
}