#include<bits/stdc++.h>
using namespace std;
int l[10000],v[100][100];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,h,k,f,x,y,o=1;
	cin>>n>>m;
	h=n*m;
	for(int i=1;i<=h;i++){
		cin>>l[i];
	}
	k=l[1];
	sort(l+1,l+1+h,cmp);
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			v[j][i]=l[o++];
		}
		for(int j=n;j>=1;j--){
			v[j][i+1]=l[o++];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(k==v[i][j]){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
} 

