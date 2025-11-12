#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int t=a[1];
	sort(a+1,a+m*n+1,cmp);
	int k=1;
	while(t!=a[k]) k++;
	if(k%n == 0){
		if(k%(2*n) == 0) cout<<k/n<<" 1";
		else cout<<k/n<<" "<<n;
	}else{
		cout<<k/n+1<<" ";
		if(k%(2*n) <= n) cout<<k%n;
		else cout<<n-(k%n)+1;
	}
	return 0;
}
