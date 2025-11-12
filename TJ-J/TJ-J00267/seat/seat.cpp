#include <iostream>
#include <cstdio>
#include <algorithm>
int a[100];
using namespace std;
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+n*m+1);
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			cnt++;
			break;
		}
		cnt++;
	}
	int ans=n*m-cnt+1;
	int c=ans/n;
	int r=ans%n;
	if(ans>n && r!=0){
		c++;
	}
	if(r==0){
		r=n;
	}
	if(c%2==0){
		cout<<c<<" "<<n-r+1;
	}
	else{
		cout<<c<<" "<<r;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
