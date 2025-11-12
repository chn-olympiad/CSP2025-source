#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
bool cnt(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cnt);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			if(i%n!=0){
				cout<<i/n+1<<" "<<i%n;
			}
			else if(i%n==0){
				cout<<i/n<<" "<<n;
			}
			break;
		}
	}
	
	return 0;
} 
