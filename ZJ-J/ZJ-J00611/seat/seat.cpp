#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
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
	int R=a[1],id;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			id=i-1;
			break;
		} 
	}
	int h=(id/n)+1;
	int w=(id%n)+1;
	if(h%2==1)cout<<h<<" "<<w;
	else cout<<h<<" "<<n-w+1;
}
/*
3 3
94 95 96 97 98 99 100 93 92

*/
