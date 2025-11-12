#include<bits/stdc++.h> 
using namespace std;
int a[100007];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,c=1,r=1,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
			
	}
	int s=a[1];
	sort(a,a+1);

		for(int i=1;i<=n*m;i++){
				if(s==a[i]){
				cout<<c<<" "<<r;
				break;
			}
			if(r<=n){
	        	r++;
			}if(r>n){
				c++;
			}

		}

	return 0;
}

