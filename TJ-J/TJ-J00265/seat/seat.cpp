#include<bits/stdc++.h>
using namespace std;
int n,m;
int seat[11][11];
int a[105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int a1=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	int id=0;
    for(int i=1;i<=n*m;i++){
    	if(a[i]==a1){
    		id=i;
    		break;
		}
	}
	int y=(id-1)/n+1;
	int x=(id-1)%n+1;
	cout<<y<<" "<<x;
    return 0;
}
