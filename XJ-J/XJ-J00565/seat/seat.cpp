#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],a0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	a0=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==a0){
			if((i+1)%n==0){
				cout<<(i+1)/n<<" ";
				if(((i+1)/n)%2==0){
					cout<<1;
				}
				else{
					cout<<n;
				}
			}
			else{
				cout<<(i+1)/n+1<<" ";
				if(((i+1)/n+1)%2==0){
					cout<<n-(i+1)%n+1;
				}
				else{
					cout<<(i+1)%n;
				}
			}
		}
	}
}
