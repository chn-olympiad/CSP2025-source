#include<bits/stdc++.h>
using namespace std;
int n,m,a[103][103],b[10086],flag;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>b[i];
	}
	flag=b[1];
	sort(b+1,b+n*m+1);
	for(int i=m,q=1;i>=1;i--){
		if(i%2==1){
			for(int j=n;j>=1;j--,q++){
				if(b[q]==flag){
					cout<<i<<" "<<j;
					return 0;
				}
				a[i][j]=b[q];
			}
		}
		else if(i%2==0){
			for(int j=1;j<=n;j++,q++){
				if(b[q]==flag){
					cout<<i<<" "<<j;
					return 0;
				}
				a[i][j]=b[q];
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
