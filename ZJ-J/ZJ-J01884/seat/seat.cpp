#include<bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int f=a[1];
	sort(a+1,a+n*m+1,cmp);
	int sum=1;
	while(a[sum]!=f){
		sum++;
	}
	cout<<(sum-1)/n+1<<" ";
	if(((sum-1)/n+1)%2==1){
		cout<<(sum-1)%n+1;
	}else{
		cout<<n-(sum-1)%n;
	}
	return 0;
} 

