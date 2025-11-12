#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200][200],b[10000],cnt=1,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	r=b[1];
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		cnt=i;
		for(int j=1;j<=m;j++){
			a[i][j]=b[cnt];
			if(j%2!=0){
				cnt+=2*n-1-(i-1)*2;
			}else{
				cnt+=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==r){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
