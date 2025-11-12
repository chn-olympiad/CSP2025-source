#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,n0,n1;
long long k;
long long a[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==1 && a[i-1]==1){
			n1++;
			n0++;
			a[i]=0;
		}
		else if (a[i]==0) n0++;
		else if (a[i]==1) n1++;
	}
	
	if (k==1){
		cout<<n1;
	}else if (k==0){
		cout<<n0;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}