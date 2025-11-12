#include <bits/stdc++.h> 
using namespace std;
int a[105];
int n,m,R,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++) if(a[i]==R) cnt=i;
	cnt=n*m-cnt+1;
	if((cnt/n)%2==1){
		if(cnt%n==0){
			cout<<cnt/n<<" "<<n;
			return 0;
		}
		else{
			cout<<cnt/n+1<<" "<<n-cnt%n+1;
			return 0;
		}
	}
	else{
		if(cnt%n==0){
			cout<<cnt/n<<" "<<1;
			return 0;
		}
		else{
			cout<<cnt/n+1<<" "<<cnt%n;
			return 0;
		}
	}
	return 0;
}
