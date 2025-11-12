#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],x,y,z=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			x=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			y=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(z==y){
					cout<<i<<" "<<j;
					return 0;
				}
                z++;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(z==y){
					cout<<i<<" "<<j;
					return 0;
				}
				z++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

