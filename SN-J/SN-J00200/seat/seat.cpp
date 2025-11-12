#include<bits/stdc++.h>
using namespace std;
bool b(int a,int b){
	if(a>b) return 1;
	else return 0;
}
int n,m,p,u;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}p=a[0];
	sort(a,a+n*m,b);
	for(int i=0;i<n*m;i++){
		if(a[i]==p){
			u=i;
			break;
		}
	}
	cout<<u/n+1<<" ";
	if((u/n+1)%2==0){
		cout<<n-u%n;
	}else cout<<u%n+1;
	return 0;
}
