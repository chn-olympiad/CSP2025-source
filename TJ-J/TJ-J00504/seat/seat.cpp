#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,ans1 = 0,ans2 = 0,cnt = 1,f;
	cin>>n>>m;
	long long a[10001] = {};
	cin>>a[1];
	int cy = a[1];
	for(int i = 2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i<=n*m;i++){
		if(a[i]==cy){
			ans1 = i;
		}
	}
	ans2=ans1;
	if(ans2%n==0){
		f = ans2/n;
		cout<<f<<' ';
	}else{
		f = ans2/n+1;
		cout<<f<<' ';
	}
	if(ans1%n==0){
		cout<<n;
		return 0;
	}
	ans1%=n;
	if(f%2==0){
		cout<<n-ans1+1;
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
