#include<bits/stdc++.h>
using namespace std;
long long a[105];
int main(){
    freopen("seat.in","r",stdin);
      freopen("seat.out","w",stdout);
    long long n,m,l=0,s=0;
    cin>>n>>m;
    l=n*m;
    for(long long i=1;i<=l;i++){
        cin>>a[i];
        s=a[1];
	}
	sort(a+1,a+l+1);
	long long x=1,y=1,u=1;
	for(long long i=l;i>=1;i--){
		if(s==a[i]){
			cout<<y<<" "<<x<<endl;
			return 0;
		}
		else{
		if(x<n&&u==1){
			x++;
		}
		else if(x>1&&u==0){
			x--;
		}
		else if(x==n){
			y++;
			u=0;
		}
		else if(x==1&&u==0){
			u=1;
			y++;
		}
	}
	}
}