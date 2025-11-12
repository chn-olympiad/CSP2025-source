#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	int x=11;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){ 
	
		if(a[i]==t){
			break;
		}
		int y=1;
		if(i%n==0){
			x+=n;
			y+=1;
		}else{
			if(y%2==0){
				x--;
			}else{
				x++;
			}
		} 
	
	}
	cout<<x/10<<" "<<x%10;
	return 0;
}
