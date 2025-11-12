#include<bits/stdc++.h>
using namespace std;
int n,m;
int k,len=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+1],ans[n+1][m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				ans[j][i]=a[len];
				if(ans[j][i]==k){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				len++;
			}
		}else{
			for(int j=m;j>=1;j--){
				ans[j][i]=a[len];
				if(ans[j][i]==k){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				len++;
			}
		}
	}
	return 0;
}
