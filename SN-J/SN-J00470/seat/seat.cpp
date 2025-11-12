#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[100];
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long y=a[1];
	sort(a[1],a[n*m]);
	for(long long i=1;i<=n*m;i++){
		if(a[i]==y){
			if(i%n==0){
				cout<<m;
				y=m;
			}
			if(i%n!=0){
				cout<<i%n;
				y=i%n;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
