#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	
	cin>>n>>m;
	int a[110];
	int b[110];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		;
	}
	for(int i=1;i<=n*m;i++){
		b[i]=a[i];
	}
	
	
	sort(b+1,b+n*m+1,greater<int>());
	
	for(int i=1;i<=n*m;i++){
		if(b[i]==a[1]){
			if(n==2 && i>n){
				if(i%2==1)cout<<2<<" "<<i-n+1;
				else cout<<2<<" "<<i-n+1;
				
			}
			else{
				cout<<1<<" "<<i;
			}
				
		}
				
	}
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}
