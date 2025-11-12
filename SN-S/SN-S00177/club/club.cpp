#include <bits/stdc++.h>
using namespace std;
#define int long long
int read() {
	char c;int t=1;
	while(1) {
		c=getchar();
		if(c>='0'||c<='9') break ; 
	}
	int s=c-'0';
	while(1) {
		c=getchar() ;
		if(c<'0'||c>'9') break ;
		s=s*10+c-'0';
	}
	return s ;
}
int a[100005][3] ;
int TT ;
int sum[3] ;
int n ;
void work() {
	memset(sum,0,sizeof(sum));
	cin>>n ;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=2;j++) {
			scanf("%lld",&a[i][j]) ;
		}
	}
	int s=0 ;
	priority_queue<int> q[3] ;
	for(int i=1;i<=n;i++) {
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) {
			s+=a[i][0] ;
			sum[0]++ ;
			q[0].push(-a[i][0]+max(a[i][1],a[i][2])) ;
		}
		if(a[i][1]>a[i][0]&&a[i][1]>=a[i][2]) {
			s+=a[i][1] ;
			sum[1]++ ;
			q[1].push(-a[i][1]+max(a[i][0],a[i][2])) ;
		}
		if(a[i][2]>a[i][1]&&a[i][2]>a[i][0]) {
			s+=a[i][2] ;
			sum[2]++ ;
			q[2].push(-a[i][2]+max(a[i][1],a[i][0])) ;
		}
	}
//	cout<<s<<endl;
	while(sum[0]>n/2) {
		s+=q[0].top() ;
		q[0].pop() ;
		sum[0]-- ;
	}
	while(sum[1]>n/2) {
		s+=q[1].top() ;
		q[1].pop() ;
		sum[1]-- ;
	}
	while(sum[2]>n/2) {
		s+=q[2].top() ;
		q[2].pop() ;
		sum[2]-- ;
	}
	cout<<s<<endl;
}
signed main() {
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ;
cin>>TT ;
while(TT--) {work() ;}
	
	
	return 0 ;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1*/
