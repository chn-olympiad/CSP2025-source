#include<bits/stdc++.h>
using namespace std;
int n,m,l,a[10005],num=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i];
	}
	int end=a[1];
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l;i++){
		if(a[i]==end){
			num=i;
			break;
		}
	}
	int x=num/n;
	int y=num%n;
	if(x%2==1){
		if(y==0){
			cout<<x<<" "<<n;
		}
		else{
			cout<<x+1<<" "<<n-y+1;
		}
	}
	else{
		if(y==0){
			cout<<x<<" "<<1;
		}
		else{
			cout<<x+1<<" "<<y;
		}
	}
	return 0;
}