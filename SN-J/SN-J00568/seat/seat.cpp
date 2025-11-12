#include<bits/stdc++.h>
using namespace std;
bool cmp(int w,int y){
	return w>y;
}
/*struct man{
	int x,bh;
}a[100005];
bool cmp(man w,man y){
	return w.x>y.x;
}*/
int n,m,a[10005],x[105][105],d,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		d=a[1];
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int k=1;k<=m;k+=2){
		for(int i=1;i<=n;i++){
			c++;
			x[i][k]=a[c];
		}
		for(int i=n;i>=1;i--){
			c++;
			x[i][k+1]=a[c];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x[i][j]==d){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
/*	for(int i=1;i<=n*m;i++){
		cout<<a[i]<<" ";
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].bh==1){
			d=i;
		}
	}
	cout<<d/n<<" ";
	if(d%m==0){
		cout<<m;
		return 0;
	}
	cout<<d%m;*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}

