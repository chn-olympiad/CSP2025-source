#include<bits/stdc++.h>
using namespace std;
const int N=13,M=107;
int s[M],seat[N][N],aim,n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	aim=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==aim){
			if(i%n==0){
				cout<<i/n;
			}
			else cout<<i/n+1;
			cout<<" ";
			if((i/n)%2==1 and i%n) {
				if(i%n==0){
					cout<<1;
				}
				else {
					cout<<n-i%n+1;
				}
			}
			else{
				if(i%n==0){
					cout<<n;
				}
				else {
					cout<<i%n;
				}
			}
		}
	}
	return 0;
}
