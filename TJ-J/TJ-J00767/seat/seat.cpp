#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n*m;i++){
		if(a[i]>a[0]){
			cnt++;
		}
	}
	if((cnt/n)%2==1){
		cout<<cnt/n+1<<" "<<n-(cnt+1)%n+1;
	}
	if((cnt/n)%2==0){
		cout<<cnt/n+1<<" "<<cnt%n+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
