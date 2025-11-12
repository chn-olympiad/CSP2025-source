#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300],r;
bool cmp(long long i,long long j){
	return i>j;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)r=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(r==a[i]){
			cout<<(i-1)/n+1<<" ";
			if(((i-1)/n+1)%2==1)cout<<(i-1)%n+1;
			else cout<<n-(i-1)%n;
			return 0;
		}
	}
}



