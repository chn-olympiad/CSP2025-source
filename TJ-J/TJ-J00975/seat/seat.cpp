#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int temp=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(temp==a[i]){
			if(i%n==0){
				if((i/n)%2==1){
					cout<<i/n<<' '<<n;
				}else if((i/n)%2==0){
					cout<<i/n<<' '<<1;
				} 
			}else{
				if(((i/n)+1)%2==1){
					cout<<i/n+1<<' '<<i%n;
				}else if(((i/n)+1)%2==0){
					cout<<(i/n)+1<<' '<<n-i%n+1;
				} 
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
