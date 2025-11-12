#include<bits/stdc++.h>
using namespace std;
int n,m,s,num;
int a[110];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=m*n;
	for(int i=1; i<=s; i++) {
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+s+1,cmp);
	for(int i=1; i<=s; i++) {
		if(a[i]==num) num=i;
	}
	cout<<(num-1)/n+1<<" ";
	int t=(num-1)/n+1;
	if(t%2==1){
		cout<<(num%n==0?n:num%n);
	}else{
		cout<<(num%n==0?1:n-num%n+1);
	}
	return 0;
}
