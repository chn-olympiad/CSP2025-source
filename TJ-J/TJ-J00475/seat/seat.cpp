#include<bits/stdc++.h>
using namespace std;
const int N = 1e1 + 5 , M = 1e2 + 5;
int n,m,a[N][N],mark[M];
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int g=n*m;
	for(int i=1;i<=g;i++){
		cin>>mark[i];
	}
	int markR=mark[1],pos;
	sort(mark+1,mark+g+1,cmp);
	for(int i=1;i<=g;i++){
		if(mark[i]==markR){
			pos=i;
			break;
		}
	}
	int f1=((pos-1)/n)+1,f2=pos%n;
	cout<<f1<<' ';
	if(f1%2==1){
		if(f2==0) f2=n;
		cout<<f2;
	}else {
		if(f2==0) f2=1;
		cout<<n-f2+1;
	}
	return 0;
}
// 100 99 98 97
// f1=0,f2=2;
