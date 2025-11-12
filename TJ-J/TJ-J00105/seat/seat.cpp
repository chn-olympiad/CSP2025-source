#include<bits/stdc++.h>
using namespace std;
long long n,m;
//struct node{
//	bool is_st;
//	long long val;
//}a[102];
long long a[102];
long long num;
//bool cmp(node a,node b){
//	return a.val>b.val;
//}
bool cmp(long long a,long long b){
	return a>b;
}
long long val;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+1+n*m,cmp);
	long long n_num=1,n_st=1,j=1;
	for(long long i=1;i<=m;i++){
		for(j=n_st;j<=n&&j>=1;j+=n_num){
			if(a[++val]==num){
				cout<<i<<' '<<j;
				return 0;
			}
		}
		if(j==n+1){
			n_num=-1;
			n_st=n;
		}
		else if(j==0){
			n_num=1;
			n_st=1;
		}
	}

	return 0;
}
