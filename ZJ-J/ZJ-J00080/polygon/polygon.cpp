#include<bits/stdc++.h>
using namespace std;
int a[40],b[40];
void f(int n){
	int cnt1=0;
	for(int i=n;i;i/=2){
		b[++cnt1]=i%2;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,maxx=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=7;i<=pow(2,n);i++){
		int sum=0,maxx=0;
		f(i);
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				sum+=a[i];
				maxx=max(maxx,a[i]);
			}
		}
		if(sum>2*maxx) cnt++;
	}
	cout<<cnt;
	return 0;
}
