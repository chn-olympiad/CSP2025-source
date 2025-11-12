#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[105];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,s=0,h=0,f=1,l=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(s==a[i]){
			h=i;
			break;
		}
	}
	for(int i=n*m;i>=h;i--){
		if(i%n==0){
			l++;
		}
		if(l%2==0&&i%n!=0){
			f--;
		}
		else if(l%2!=0&&i%n!=0){
			f++;
		}
	}
	cout<<l<<" "<<f;
	return 0;
 }

