#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],h,b[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	h=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		int x,y;
		if(i%n==0){
			x=i/n;
			if(x%2==0){
				y=1;
			}
			else{
				y=n;
			}
		}
		else{
			x=i/n+1;
			if(x%2==0){
				y=n+1-i%n;
			}
			else{
				y=i%n;
			}
		}
		if(a[i]==h){
			cout<<x<<" "<<y;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

