#include<bits/stdc++.h>
using namespace std;
const int modd=998244352;
int n,a[5010],b[5010];
int main(){
	freopen("polygon4.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int sum=0;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]!=1){
			flag=0;
		}
		b[i]=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		sort(a+1,a+1+n);
		if(sum>a[n]*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else if(flag==1){
		int cnt=0;
		for(int i=n-2;i>=1;i--){
			cnt+=i;
		}
		cout<<cnt;
		return 0;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for(int i=2;i<=n;i++){
		b[i]+=b[i-1];
	}
	long long anss=0;
	for(int i=1;i<=n;i++){
		for(int x=2;x<=n;x++){
			for(int j=i+x;j<=n;j++){
				if(b[j]>a[j]*2){
					anss++;
					anss%=modd;
				}
			}
		}
	}
	cout<<anss;
	return 0;
}
