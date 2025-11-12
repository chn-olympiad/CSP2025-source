#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[5000005];
long long c;
int s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		while(c!=k){
			if(a[i]^a[i+1]==k){
				c=a[i]^a[i+1];
				s++;
				i++;
			}
		}
	}
	cout<<s+1;
	return 0;
}
