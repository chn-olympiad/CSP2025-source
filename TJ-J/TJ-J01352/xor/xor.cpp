#include<bits/stdc++.h>
using namespace std;

int n,r;long long k;
long long a[500000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i]; 
	for(int i=0;i<n;i++){
		int i1 = i;
		for(int x=-1;x!=k;i++){
			if(i>n){i=i1;goto no;}
			x = a[i];
			for(int j=i+1;j<=i;j++)
				x = (x xor a[j]);
		}r++;
		no:;
	}
	cout<<r;
	return 0;
}
