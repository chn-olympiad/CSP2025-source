#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int dy[]={1,-1};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin >> n >> m;
	int r;cin>>r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	a[1]=r;
	if(n==1){
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n*m;i++){
			if(a[i]==r){
				cout<<i<<' '<<1<<endl;
				return 0;
			}
		}
	}
	if(m==1){
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n*m;i++){
			if(a[i]==r){
				cout<<1<<' '<<i<<endl;
				return 0;
			}
		}
	}
	sort(a+1,a+1+n*m,cmp);
	int nowdy=0,nx=1,ny=1;
//	cout<<a[1]<<endl;
	for(int i=1;i<=n*m;i++){
		if(a[i]<1) break;
//		cout<<a[i]<<' '<<nx<<' '<<ny<<' '<<dy[nowdy]<<' '<<nowdy<<endl;
		if(a[i]==r){
			cout<<nx<<' '<<ny<<endl;
			return 0;
		}
		if(ny+dy[nowdy]>n||ny+dy[nowdy]<1){
			if(nowdy==1) nowdy=0;
			else nowdy=1;
			nx++;
		}else{
			ny+=dy[nowdy];
		}
	}
	return 0;
}
/*
2 2
99 100 97 98
1 2

2 2
98 99 100 97
2 2

3 3
94 95 96 97 98 99 100 93 92
3 1
*/
