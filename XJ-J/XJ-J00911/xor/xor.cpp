#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=5e5+10;
int arr[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	int ji=0;
	for(int a=0;a<n;a++)
	{
		cin>>arr[a];
		if(arr[a]==1)
			ji++;
	}
	
	if(k=0)
		cout<<n;
	if(k=1)
		cout<<ji;
	else
		cout<<n/2;
	
	
	
	
	return 0;
} 
