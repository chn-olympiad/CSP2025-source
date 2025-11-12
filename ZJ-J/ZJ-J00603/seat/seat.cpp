#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int x;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			x=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		
		if(a[i]==x){
			
			if((i/n)%2==1){
				if(i%n==0){
					cout<<i/n<<" "<<n-(i%n);
				}else{            
					cout<<i/n+1<<" "<<n+1-(i%n);
				}                     
				return 0;
			}else{
				if(i%n==0){
					cout<<i/n<<" "<<i%n+1;
				}else{
					cout<<i/n+1<<" "<<i%n;
				}                       
				return 0;
			}
		}
	}
	return 0;
}