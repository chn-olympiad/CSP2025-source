#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;struct node{
	int val,number;
}a[20005];
bool cmp(node x,node y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++cnt].val;
			a[cnt].number=cnt;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	int R=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].number==1){
			R=i;
			break;
		}
	}
	int lie=(R%n==0?R/n:R/n+1);
	int p=(R%n==0?n:R%n);
	int hang=(lie%2==0?n-p+1:p);
	cout<<lie<<' '<<hang;
}
