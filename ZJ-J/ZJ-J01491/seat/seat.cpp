#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++cnt];
		}
	}
	int c=a[1];
	sort(a+1,a+1+cnt,cmp);
	for(k=1;k<=n*m;k++){
		if(a[k]==c)break;
	}
	int p=(k-1)/n+1;
	int q=k%(2*n);
	if(q==0)q=1;
	else if(q>n)q=2*n+1-q;
	cout<<p<<" "<<q;
	return 0;
}
