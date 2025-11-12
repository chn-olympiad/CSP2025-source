#include<bits/stdc++.h>
using namespace std;
int N=1e6;
long long n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
cin>>n>>k;
int l=0,r=n,c=0,a[N];

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
while(r<l){


c+=a[l]^a[r];
if(c==k)
cout<<r-l;
l+=1;
r=(l+r)/2+1;
}

	return 0;
}