#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long sum=0;
	int c=n;
	sort(a,a+n);
	while(--c){
		if(c<3){
			break;
		}
		for(int i=0;i<c;i++){
			int b[n]={0};
			for(int f=i;f<c;f++){
				b[f]=a[f];
			}
			long long ans=0;
			int maxx=0;
			for(int j=i;j<c;j++){
				ans+=b[j];
				maxx=max(maxx,b[j]);
			}
			if(maxx<ans/2){
				sum++;
			}
		}
	}
	cout<<sum*9%998%244%353;
	return 0;
}
