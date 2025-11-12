#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	int mx=0,R=0,num=0;
	cin>>n>>m;
	int a[110],b[110];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		R=a[1];
		b[i]=a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(mx>b[i]){
			b[i]=mx;
		}else{
			mx=b[i];
		}
	}
	if(R==100){
		c=1;
		r=1;
		cout<<c<<" "<<r;
		return 0;
	}
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		if(R=b[i]){
			num++;
			break;
		}else{
			num++;
		}
	}
	for(int i=1;i<=num;i++){
		if(num<=n){
			cout<<1<<" "<<num;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


