#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],vis,b[105];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) vis=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==vis){
			int nn;
			if(i%m==0){
				cout<<i/m<<" ";
				nn=i/m;
			}
			else{
				cout<<i/m+1<<" ";
				nn=i/m+1;
			}
			if(nn%2==1){
				if(nn==i/m){
					cout<<m;
				}
				else{
					cout<<i-(m*(nn-1));
				}
			}
			else{
				if(nn==i/m){
					cout<<1;
				}
				else{
					cout<<m-(i-(m*(nn-1)));
				}
			}
		}
	}
}
