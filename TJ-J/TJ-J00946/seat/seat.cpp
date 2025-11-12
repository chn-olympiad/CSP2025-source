#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x=1,cnt=n*m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int t=a[1];
	sort(a+1,a+1+(n*m));
	for(int i=1;i<=n;i++){
		if(t==a[cnt--]){
			cout<<1<<" "<<i;
			return 0;
		}
	}
	for(int i=n;i>=1;i--){
		if(t==a[cnt--]){
			cout<<2<<" "<<i;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(t==a[cnt--]){
			cout<<3<<" "<<i;
			return 0;
		}
	}
	for(int i=n;i>=1;i--){
		if(t==a[cnt--]){
			cout<<4<<" "<<i;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(t==a[cnt--]){
			cout<<5<<" "<<i;
			return 0;
		}
	}
	for(int i=n;i>=1;i--){
		if(t==a[cnt--]){
			cout<<6<<" "<<i;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(t==a[cnt--]){
			cout<<7<<" "<<i;
			return 0;
		}
	}
	for(int i=n;i>=1;i--){
		if(t==a[cnt--]){
			cout<<8<<" "<<i;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(t==a[cnt--]){
			cout<<9<<" "<<i;
			return 0;
		}
	}
	for(int i=n;i>=1;i--){
		if(t==a[cnt--]){
			cout<<10<<" "<<i;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	
    return 0;
}


