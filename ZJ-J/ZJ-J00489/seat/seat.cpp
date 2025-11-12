#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],mi;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			mi=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==mi){
			if(i%n==0){
				if((i/n)%2==0){
					cout<<i/n<<" "<<1;
				}
				else{
					cout<<i/n<<" "<<n;
				}
			}
			else{
				if((i/n)%2==0){
					cout<<i/n+1<<" "<<i%n;
				}
				else{
					cout<<i/n+1<<" "<<n+1-i%n;
				}
			}
			
		}
	}
	
	return 0;
}