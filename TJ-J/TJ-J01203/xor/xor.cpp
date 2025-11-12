#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	long long sum=0;
	cin>>n>>k;
	if(k==0) {
		int a[200005]= {};
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		long long x=0;
		for(long long i=1; i<=n; i++) {
			if(a[i]==0) {
				sum++;
				sum+=x/2;
				x=0;
			}
			x++;
		}
		sum+=x/2;
		cout<<sum;
	}
	if(k==1) {
		for(long long i=1; i<=n; i++) {
			int x;
			cin>>x;
			sum+=x;
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
