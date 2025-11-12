#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int f=a[1];
	sort(a+1,a+n*m+1,cmp);
	if(a[1]==f){
		cout<<1<<" "<<1;
		return 0;
	}
	if(a[n*m]==f){
		cout<<m<<" "<<n;
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			if(i%n==0){
				if(i/n%2==1){
					cout<<i/n<<" "<<n;
				}
				else{
					cout<<i/n<<" "<<1;
				}
			}
			else{
				if(i/n%2==0){
					cout<<i/n+1<<" "<<i%n;
				}
				else{
					cout<<i/n+1<<" "<<n-i%n+1;
				}
			}
			break;
		}
	}
	return 0;
}
