#include <bits/stdc++.h>
using namespace std;
long long n,m,k,r,x,y;
long long a[110];
bool cmp(long long x,long long y){
	return x>=y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k = n*m;
	for(int i=1;i<=k;i++) cin>>a[i];
	r = a[1];
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++){
		if(a[i]==r){
			x = i/n;
			y = i%n;
			if(y==0){
				if(x%2) cout<<x<<" "<<n;
				else cout<<x<<" "<<1;
			}else{
				x += 1;
				if(x%2) cout<<x<<" "<<y;
				else cout<<x<<" "<<n-y+1;
			}
		}
		
	}
	
	
	return 0;
}
