#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	bool z=true;
	int c[10001];
	int n,m,ai,xb;
	cin>>n>>m;
	int a[n][m];
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	ai=c[1];
	for(int i=1;i<=n*m-1;i++){
		for(int j=1;j<=n*m-i;j++){
			if(c[j]<c[j+1]){
				swap(c[j],c[j+1]);
				z=false;
			}
		}
		if(z){
			break;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(ai==c[i]){
			xb=i;
			break;
		}
	}
	if(xb==n*m){
		if(n%2==1){
			cout<<1<<' '<<m;
		}else{
			cout<<n<<' '<<m;
		}
		
		return 0;
	}
	if(xb==0){
		cout<<1<<' '<<1;
		return 0;
	}
	if(((xb-1)/m+1==(xb/m)+1||(xb-1)%n==n-1)||(xb/m)+1==1){
		if((xb/m)+1==1){
			cout<<(xb/m)+1<<' '<<n;
		}else if(xb%2==0){
			cout<<(xb/m)+1<<' '<<n;
		}else {
			cout<<(xb/m)+1<<' '<<xb%n+1;
			
		}
	}else{
		cout<<(xb/m)+1<<' '<<xb%n+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

