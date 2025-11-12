#include <bits/stdc++.h>
using namespace std;
int n,m;
struct ss{
	int number,yji,xji;
} a[10010];
bool cmp1(ss x,ss y){
	return x.number>y.number;
}
bool cmp2(ss x,ss y){
	return x.yji<y.yji;
}
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].number;
		a[i].yji=i;
	}
	int nown=n*m;
	sort(a+1,a+1+nown,cmp1);
	for(int i=1;i<=nown;i++){
		a[i].xji=i;
	}
	sort(a+1,a+1+nown,cmp2);
	int wei=a[1].xji;
	int hang=wei/n;
	if(wei%n==0){
		hang--;
	}
	if(hang%2==0){
		int yu=wei-hang*n;
		cout<<hang+1<<" "<<yu;
	}else{
		int yu=wei-hang*n;
		cout<<hang+1<<" "<<m-yu+1;
	}
	return 0;
}
