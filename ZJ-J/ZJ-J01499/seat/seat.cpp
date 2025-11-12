#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,R;
	cin>>n>>m>>R;
	a[1]=R;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	int now=0;
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				now++;
				if(a[now]==R){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				now++;
				if(a[now]==R){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
