#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
int main(){
	//freopen("polygon.in","r",stdin);
   	//freopen("polygon.out","w",stdout);
	int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	b[i]+=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int s=b[i]-2*a[i];
		if(i<3||s<=0) continue;
		for(int j=0;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(b[k]-b[j]>s&&n-(k-j)>3||j==0&&n-(k-j)>=3) sum++;
			}
		}
		sum++;
	}
	cout<<sum%998%244%353;
	return 0;
}
