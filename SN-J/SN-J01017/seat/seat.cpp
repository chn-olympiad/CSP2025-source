#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105],ans,f=1,gg=0,tt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in" ,"r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+1+n*m,cmp);
	int sum=0,q=1,id=1;
	for (int i = 1;i<=m;i++){
		for (int j =q;j<=n*i;j++){
			b[id]=a[j];
			if (b[id]==ans){
				gg=1;
			}
			id++;
		};
		id=1;
		if (gg==1 && f%2==1){
			for (int y = 1;y<=n;y++){
				if (b[y]==ans){
					cout<<f<<" "<<y;
					return 0;
				}
			}
		}else if(gg==1 && f%2==0){
			tt=1;
			for (int y = n;y>=1;y--){
				if (b[y]==ans){
					cout<<f<<" "<<tt;
					return 0;
				}
				tt++;
			}
		}
		q=n*i+1;
		f++;
	}
	return 0;
}
