#include<bits/stdc++.h>
using namespace std;
int a[110];
int x[110][110];
bool fx(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
	int n,m,l=0,ac=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	int u=n*m;
	int d=u;
	sort(a+1,a+1+u);
	for(int i=1;i<=n;){
		for(int y=1;y<=m;){
			if(i==n){
				x[i][y]=a[u];
				u--;
				if(i*y==d || u==0){
					l=1;
					break;
				}
				y++;
				x[i][y]=a[u];
				u--;
				i--;
				ac=1;
			}
			else if(i==1 && y%2!=1){
				x[i][y]=a[u];
				u--;
				if(i*y==d || u==0){
					l=1;
					break;
				}
				y++;
				x[i][y]=a[u];
				u--;
				i++;
				ac=0;
			}
			else{
				x[i][y]=a[u];
				u--;
				if(ac==1){
					i--;
				}
				else{
					i++;
				}
			}
			if(l==1){
				break;
			}
			if(i*y==d || u==0){
				l=1;
			}
		}
		if(l==1){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int y=1;y<=m;y++){
			if(x[i][y]==ans){
				cout<<y<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 
