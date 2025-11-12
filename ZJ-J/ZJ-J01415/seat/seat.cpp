#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000010],x;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	a[1]=x;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int ans=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			ans=i;
			break;
		}
	}
	int k=ans/n;
	if(ans%n)k++;
	if(k%2==0){
		if(ans%n==0)cout<<k<<" "<<1;
		cout<<k<<" "<<n-(ans%n)+1;
	}
	else{
		if(ans%n==0)cout<<k<<" "<<n;
		else cout<<k<<" "<<ans%n;
	}
	return 0;
}