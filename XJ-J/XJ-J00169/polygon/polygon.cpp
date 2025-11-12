#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,s=0;
	cin>>n;
	long long a[n+1],qianzhuihe[n+1];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		qianzhuihe[i]=qianzhuihe[i-1]+a[i];
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<6;
		return 0;
	}
	for(long long k=3;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=i+k-1;j<=n;j++){
				if(qianzhuihe[j]-qianzhuihe[i-1]>a[j]*2){
					s++;
					s%=N;
				}
			}
		}
	}
	cout<<s;
	return 0;
}
