#include<bits/stdc++.h>
using namespace std;
int n,k,l,r;
int a[500005];
int add(int a[],int x,int y){
	int sum=0;
	if(x==y) return a[x];
	for(int i=x;i<=y;i++){
		sum^=a[i];
	}
	return sum;
}
int check(int a[],int e,int k){
	int result=0;
	for(int i=e;i<=n;i++){
		if(add(a,e,i)==k){
			return i;
		}
	}
	return 0;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		if(check(a,i,k)!=0){
			maxn++;
			if((check(a,i,k)+1)<=n){
				i=check(a,i,k);
			}
			else break;
		}
	}
	cout<<maxn;
	return 0;
}
