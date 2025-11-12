#include<bits/stdc++.h>
using namespace std;
int n,m,len,sum=1,r,x,a,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	len=n*m-1;
	for(int i=1;i<=len;i++){
		cin>>x;
		if(x>r) sum++;
	}
	a=sum/(2*n)*2;
	sum%=(2*n);
	if(sum<=n) cout<<a+1<<" "<<sum;
	else cout<<a+2<<" "<<2*n-sum+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
