#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	int rd;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			rd=i;
		}
	}
	for(int i=1;i<=n;i++){//ÐÐ 
		for(int j=1;j<=m;j++){//ÁÐ 
			if(j%2==1){
				int u=(j-1)*n+i;
				if(u==rd){
					cout<<j<<' '<<i<<'\n';
					return 0;
				}
			}else{
				int u=(j-1)*n+n-i+1;
				if(u==rd){
					cout<<j<<' '<<i<<'\n';
					return 0;
				}
			} 
		}
	}
	return 0;
}
