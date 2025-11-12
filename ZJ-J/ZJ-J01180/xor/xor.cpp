#include <bits/stdc++.h>
using namespace std;
int qejz(int x,int y){
	int xz=1,c=0;
	for (int i=0;i<20;i++){
		xz=xz*2;
		if (xz>=max(x,y)){
			break;
		}
	}
	while (xz>0){
		if (x>=xz && y>=xz){
			x-=xz;
			y-=xz;
		}else if(x>=xz && y<xz){
			x-=xz;
			c+=xz;
		}else if(x<xz &&y>=xz){
			y-=xz;
			c+=xz;
		}
		xz=xz/2;
	}
	return c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005],q=0,i=0;
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	while (a[i]==k){
		i++;
		q++;
	}
	int z=a[i];
	i++;
	for (;i<n;i++){
		if (a[i]==k){
			z=0;
			q++;
		}else{
			z=qejz(z,a[i]);
			if (z==k){
				q++;
				z=a[i+1];
				i++;
			}
		}
	}
	cout<<q;
} 
