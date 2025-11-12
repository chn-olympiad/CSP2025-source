#include <bits/stdc++.h>
using namespace std;
int n,m,a[101],k,s,rn,rm;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	k=a[1];
	for (int i=2;i<=m*n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++){
		if (k==a[i]){
			s=i;
		}
	}
	if (s%n==0){
		rn=n;
		rm=s/n;
	} else {
		rm=s/n+1;
		rn=s%n;
	}
	
	cout<<rm<<' '<<rn;
	return 0;
} 
