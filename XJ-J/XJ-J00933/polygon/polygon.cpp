#include<bits/stdc++.h>
using namespace std;
int a[5100];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(a[i]+'0');
	}
	if(n<=2){
		cout<<0;
		return 0;
	} 
	else if(n==3){
		if((a[1]+a[2])>a[3]&&(a[1]+a[3])>a[2]&&(a[3]+a[2])>a[1]){
			cout<<1;
			return 0;
		} 
		else cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	int sum=0;
	if(a[n]-a[1]<=3){
		for(int i=1;i<=n;i++){
			sum+=a[i];
		}
		cout<<sum;
		return 0;
	} 
	cout<<n+4;
	return 0;
}
