#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005],c,d,maxx=-1,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>c;
	for(int i=1;i<=c;i++){
		cin>>a[i];
	}
	for(int i=1;i<=c;i++){
		for(int j=1;j<=i;j++){
			b[i]+=a[j];
		}
	}
	for(int i=1;i<=c;i++){
		for(int j=1;j<=i;j++){
			for(int h=j;h<=i;h++){
				maxx=max(maxx,a[h]);
			}
			if(i-j>=3&&b[i]-b[j]>2*maxx){
				ans++;
			}
		}
	}
	cout<<ans*3;
}
