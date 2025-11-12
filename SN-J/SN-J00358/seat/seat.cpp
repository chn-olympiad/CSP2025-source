#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,f;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==r){
			f=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cnt++;
			if(cnt==f){
				if(i%2==0){
					cout<<i<<" "<<n-j;
				}else{
					cout<<i<<" "<<j;
				}
			}
		}
	}
	return 0;
}
