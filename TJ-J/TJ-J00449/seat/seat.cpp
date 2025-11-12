#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1)x=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		s++;
		if(a[i]==x)break;
	}
	if(s%n==0)cout<<s/n<<" "<<n;
	else cout<<s/n<<" "<<s%n;
return 0;}
