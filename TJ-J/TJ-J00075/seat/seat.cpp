#include<bits/stdc++.h> 
using namespace std;
int n,m,num;
int a[101];
int b[11][11];
int x=1,y=1,k;
bool cmp(int a,int b){
	return a>b;
}
bool flagy=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i = 1;i<=m;i++){
		if(i%2!=0){
			for(int j = 1;j<=n;j++){
				num++;
				if(a[num]==k){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j = n;j>0;j--){
				num++;
				if(a[num]==k){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
