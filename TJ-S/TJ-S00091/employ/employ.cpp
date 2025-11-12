#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,k,sum=1,sum1=1,sum2=0;
string p;
int a[10001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>p;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			k++;
		}
	}
	for(int i=1;i<=k-m;i++){
		sum1*=i;
	}
	for(int i=k-m;i<=k;i++){
		if(sum1%i==0){
			sum1*=i;
			continue;
		}
		sum*=i;
	}
	sum2=sum%998244353;
	cout<<sum2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
