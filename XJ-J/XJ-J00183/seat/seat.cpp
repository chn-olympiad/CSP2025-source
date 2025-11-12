#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e2+5;
int n,m,a[N],b,st,lie,hang;
bool cmp(int a,int b){
	return a>b;
} 
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			lie=(i-1)/n+1;
			if(lie%2){
				hang=i-(lie-1)*n;
			}
			else{
				hang=n-(i-(lie-1)*n)+1;
			}
			break;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}
/*
1 1,1
2 1,2
3,1,3
4,1,4
5,2,4
6,2,3
7,2,2
8 2,1
9 3,1
*/
