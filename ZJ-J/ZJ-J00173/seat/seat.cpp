#include<bits/stdc++.h>
using namespace std;
int N,M;
int a[150],num,l;
int lie,hang;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>N>>M;
	int n=N*M;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		if(a[i]==num){
			l=n-i+1;
			break;
		}
	}
	lie=(l-1)/N+1;
	if(lie%2==1){
		hang=(l-1)%N+1;
		cout<<lie<<" "<<hang;
	}
	else{
		hang=(l-1)%N;
		cout<<lie<<" "<<N-hang;
	}
	return 0;
}
