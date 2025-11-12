#include<bits/stdc++.h>
using namespace std;
const int N=1000+10;
int a[N];
int b[N][N];
int n,m,len,k,h,l,flag;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	sort(a+2,a+1+len,greater<int>());
	k=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[i][j]=a[++k];
			}
		}
		else{
			for(int j=1;j<=n;j++){
				b[i][j]=a[++k];
				
			}
		}
	}
	for(int i=1;i<=m;i++){
		flag=0;
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(b[i][j]<a[1]){
					l=i;h=j;
					flag=1;
					break;
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				if(b[i][j]<a[1]){
					l=i;h=j;
					flag=1;
					break;
				}
			}
		}
		if(flag==1){
			break;
		}
		if(i==n){
			l=m;h=n;
		}
	}
	cout<<l<<" "<<h<<endl;
	return 0;
	
}
 
