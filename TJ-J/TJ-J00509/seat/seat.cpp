#include<bits/stdc++.h>
using namespace std;
int a[1006];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	int f=a[1],g;
	sort(a,a+s+1);
	int p=s;
	int r=0;
	for(int i=1;i<=n;i++){
		int x,y;
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[p]==f){
					cout<<i<<" "<<j;
					r=1;
					break;
				}
				p--;
			}
		}else {
			for(int j=1;j<=n;j++){
				if(a[p]==f){
					cout<<i<<" "<<j;
					r=1;
					break;
				}
				p--;
			}
		}
		if(r==1){
			break;
		}
	}
	return 0;
}
