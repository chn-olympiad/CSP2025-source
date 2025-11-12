#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=1;
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]){
			cnt++;
		}
	}
	int x=cnt/n,y=(cnt-1)%n+1;
	if(y!=n){
		x++; 
	}
	if(x%2==1){
		cout<<x<<" "<<y<<endl;
	}
	else{
		cout<<x<<" "<<n-y+1<<endl;
	}
	return 0;
}
