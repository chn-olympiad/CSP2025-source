#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;//行数是n，列数是m 
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	int cnt;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			cnt=i;
			break;
		}
	}
	int z,w;
	int nn,mm;
	if(cnt%n==0) z=cnt/n,w=n;
	else z=cnt/n+1,w=cnt%n;
	if(z%2==1){
		mm=z;
		nn=w;
	}else{
		mm=z;
		nn=n-w+1;
	}
	cout<<mm<<" "<<nn;
	return 0;
}

