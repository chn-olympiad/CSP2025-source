//Ñ¦ÞÈÆ½  ¸¨ÂÖÖÐÑ§  SN-J00953
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[110];
	for (int i=1; i<=n*m; i++){
		cin>>a[i];
		if (i%n==0){
			if ((i/n)%2==0){
				cout<<n<<" "<<i/n;
				break;
			}
			else{
				cout<<"1"<<i/n;
				break;
			}
		}	
		else{
			if ((i/n)%2==0){
				cout<<i%n<<" "<<i/n+1;
				break;
			}
			else{
				cout<<n-(i%n)<<" "<<i/n+1;
				break;    
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
