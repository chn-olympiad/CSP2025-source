#include <bits/stdc++.h>
using namespace std;
int n,x[5005],y[5005];
long long a;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		y[i]=x[i]+y[i-1];
	}
	for(int i=3;i<=n;i++){
		for(int j=i;j<=n;j++){
			int b=0;
			for(int k=j-i+1;k<=j;k++) b=max(b,x[k]);
			if(y[j]-y[j-i]>b*2){
				//cout<<i<<" "<<j<<endl;
				a++;
			}
		}
	}
	cout<<a%998%244%353;
	return 0;
}
