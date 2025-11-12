#include<bits/stdc++.h>
using namespace std;
bool x(bool a,bool b){
	return !(a==b);
}
int f(int x,int y){
	int a[50]={0},b[50]={0},d=0,e=0,f=0;
	while(x>=2){
		a[d]=x%2;
		x/2;
		d++;
	}
	while(y>=2){
		b[e]=y%2;
		y/2;
		e++;
	}
	for(int i=0;i<e;i++){
		if(a[i]==b[i]){
			a[i]=0;
		}else{
			a[i]=1;
		}
	}
	int n=0;
	for(int i=49;i>=0;i--){
		if(a[i]==1){
			n=i;
			break;
		}
	}
	int m=1,h=0;
	for(int i=0;i<n;i++){
		h+=a[i]*m;
		m=m*2;
	}
	return h;
}
int a[600000]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,m=0,v=0,l=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	while(1){
		l=0;
		for(int i=v;i<n;i++){
			for(int j=i;j<n;j++){
				int y=0;
				for(int o=i;o<=j;o++){
					y=x(y,a[o]);
				}
				if(y==k){
					m++;
					v=j+1;
					l=1;
					break;
				}
			}
			if(l){
				break;
			}
		}
		if(l==0){
			break;
		}
	}
	cout<<m;
	return 0;
}
