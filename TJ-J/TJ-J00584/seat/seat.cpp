#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b=0;
	cin>>n>>m;
	int a[(n*m)+1];
	for(int i=1;i<=n*m;i++){
		a[0]=0;
		cin>>a[i];
		b=max(a[i],b);
	}
	if(b>a[1]&&a[1]>a[0]){
		cout<<n-1<<" "<<m;
	}
	if(b>a[0]&&a[0]>a[1]){
		cout<<n<<" "<<m;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
