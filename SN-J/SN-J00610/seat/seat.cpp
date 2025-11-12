#include<bits/stdc++.h>
using namespace std;
int n,m,b[105],v;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	v=b[0];
	sort(b,b+n*m,cmp);
	for(int i=0;i<n*m;i++){
		int j=i+1;
		if(b[i]==v){
			if(j%n==0){
				cout<<j/n<<" ";
			}else{
				cout<<j/n+1<<" ";
			}
			if(j%n==0){
				if(j/n%2==0){
					if(j%n==0){
						cout<<1;
					}else{
						cout<<n-(j%n)+1;
					}
				}else{
					if(j%n==0){
						cout<<n;
					}else{
						cout<<j%n;
					}
				}				
			}else{
				if((j/n+1)%2==0){
					if(j%n==0){
						cout<<1;
					}else{
						cout<<n-(j%n)+1;
					}
				}else{
					if(j%n==0){
						cout<<n;
					}else{
						cout<<j%n;
					}
				}	
			}
			break;
		}
	}
	return 0;
}
