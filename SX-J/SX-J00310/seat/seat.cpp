#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
	int a[m*n+1],b,c,ans=1;
	cin>>a[0];
	b=a[0];
	for(int i=1;i!=m*n;i++){
		cin>>a[i];
	}
	for(int i=0;i!=m*n;i++){
		for(int j=0;j!=m*n;j++){
			if(a[j-1]<=a[j]&&j-1>=0&&j<=m*n){
				swap(a[j-1],a[j]);
			}
		}
	}
	for(int i=0;i!=m*n;i++){
			if(a[i]==b){
				c=i+1;
				break;
			}
	}
	for(int i=1;i!=n+1;i++){
		for(int j=1;j!=m+1;j++){
			if(ans==c){
				cout<<i<<' '<<j;
				return 0;
			}
			ans++;
		}
		i++;
		for(int j=m;j!=0;j--){
			if(ans==c){
				cout<<i<<' '<<j;
				return 0;
			}
			ans++;
		}
	}
    return 0;
}