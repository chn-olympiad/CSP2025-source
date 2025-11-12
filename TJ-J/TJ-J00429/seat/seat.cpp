#include <bits/stdc++.h> 
using namespace std;
int n,m;
int a[105];
int s;
cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	a[1]=s;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int nnnn;
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			nnnn=i;
			break;
		}
	}
	int nnn=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			nnn++;
			if(nnn==nnnn){
				cout<<i<<' '<<j;
			}
		}
		i++;
		for(int j=n;j>=1;j--){
			nnn++;
			if(nnn==nnnn){
				cout<<i<<' '<<j;
			}
		}
	}
	return 0;
}
