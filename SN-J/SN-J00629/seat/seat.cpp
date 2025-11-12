//SN-J00629 杨济铭 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	int f=1,q=0;
	while(f){
		f=0;
		for(int i=1;i<n*m;i++){
			if(a[i]>a[i-1]){
				f=1;
				int t=a[i-1];
				a[i-1]=a[i];
				a[i]=t;
				if(i-1==q){
					q=i;
				}
			}
		}
	}
	q++;
	int c=q/n,r;
	if(q%n){
		c+=1;
	}
	if(c%2){
		if(q%n==0){
			r=n;
		}else{
			r=q%n;
		}
	}else{
		if(q%n==0){
			r=1;
		}else{
			r=n-q%n+1;
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
