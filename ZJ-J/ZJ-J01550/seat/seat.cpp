#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int k;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	k=a[1];
	
	int kk;
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=n*m;i++){
		if(k==a[i]){
			kk=i;
			break;
		}
	}
	int aa=(kk-1)/n+1,bb;
	if(aa%2==1){
		bb=(kk-1)%n+1;
	}else{
		bb=n-(kk-1)%n;
	}
	cout<<aa<<" "<<bb;
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97
*/
