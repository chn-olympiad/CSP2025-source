#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000009];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int to;
	for(int i=1;i<=n*m;i++) if(a[i]==r) to=i;
	int out1=to/m;
	if(to%m) out1++;
	if(out1%2==1){
		int out2=to%m;
		if(out2==0) out2=m; 
		cout<<out1<<" "<<out2<<"\n";
	}else{
		cout<<out1<<" "<<m-(to%m)+1<<"\n";
	}
	return 0;
}
