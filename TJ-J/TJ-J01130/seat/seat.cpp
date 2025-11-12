#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[1000];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>a[(i-1)*m+j];
		}
	}int s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){int k=n*m-i+1;
			if(((k-1)/n+1)%2==1)cout<<(k-1)/n+1<<' '<<(k-1)%n+1;
			else cout<<(k-1)/n+1<<' '<<n-(k-1)%n;
		}
	}
    return 0;
}/*2 2
98 99 100 97
2 2
99 100 97 98
3 3
94 95 96 97 98 99 100 93 92

*/

