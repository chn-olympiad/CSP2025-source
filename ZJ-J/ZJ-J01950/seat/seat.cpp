#include<bits/stdc++.h>
using namespace std;
int mp[100][100];
struct no{
	int x,id;
}a[10000];
bool cmp(no j,no y){
	return j.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	 freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				mp[j][i]=a[++cnt].x;
				if(a[cnt].id==1)cout<<i<<' '<<j;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				mp[j][i]=a[++cnt].x;
				if(a[cnt].id==1)cout<<i<<' '<<j;
			}
		}
	}/*
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<mp[i][j]<<' ';
		}
		cout<<endl;
	}*/
	return 0;
}
