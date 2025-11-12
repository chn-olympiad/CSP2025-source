#include<bits/stdc++.h>
using namespace std;
int n,m,a[114],x=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			x++;
		}
	}
	int v1=x%n,v2=x/n;
	if(v2%2==0){
		if(v1==0){
			cout<<v2<<' '<<1;
		}else{
			cout<<v2+1<<' '<<v1;
		}
	}else{
		if(v1==0){
			cout<<v2<<' '<<n;
		}else{
			cout<<v2+1<<' '<<n-v1+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
