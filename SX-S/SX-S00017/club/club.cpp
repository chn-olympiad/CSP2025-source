#include<bits/stdc++.h>
using namespace std;
long long t,n,x1[100001],sum,y,x,z;
int main(){
	freopen("club.in","r",stdin);
	freopen("cuub.out","w",stdout);
	cin>>t;
	while(t){
		cin>>n;
		sum=0;
		for(int i=0;i<n;i++){
			cin>>x>>y>>z;
			x1[i]=x;
		}
		sort(x1,x1+n);
		for(int i=n-1;i>=n/2;i--){
			sum+=x1[i];
		}cout<<sum<<endl;
		t--;

	}

	return 0;
}