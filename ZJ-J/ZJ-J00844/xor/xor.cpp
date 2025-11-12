#include<bits/stdc++.h>
using namespace std;
int a[500000],n,k,i,j,s,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(;i<n;i++)
		cin>>a[i];
	i=0;
	while(i<n){
		s=a[i];
		j=i;
		while(j<n){
			if(s==k){
				ans++;
				i=j;
				break;}
			j++;
			s^=a[j];
		}
		i++;
	}
	cout<<ans;
}