#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200],nm,flag;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++) cin>>a[i]; 	
	flag=a[1];
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if(flag==a[i]) flag=i;
	}
	for(int b=1;b<=m;b++){
		for(int a=1;a<=n;a++){
			if(b%2==1&&(b-1)*n+a==flag){
				cout<<b<<" "<<a;
				break;
			}
			if(b%2==0&&b*n-a+1==flag){
				cout<<b<<" "<<a;
				break;
			}
		}
	}
	return 0;
}
/*b为奇数	(b-1)n+a
	
b为偶数	bn-a+1
*/ 
