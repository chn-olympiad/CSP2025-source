#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	int n,m,a,b,t=1;
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a) t++;
	}
	b=(t+n-1)/n;
	int c=t%n;
	if(c==0) c+=n;
	if(b%2==0) c=n-c+1;
	cout<<b<<" "<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}