#include<bits/stdc++.h>
using namespace std;
int n,a[50005],b[50005],k,he,l,r,m,mk;
void cop(int c){
	int i=1;
	while(c==0){
		b[i]=c%2+b[i]*10;
		c/=2;
		i++;
	}
}
void copp(int d,int e){
	while(e==0||d==0){
		l++;
		if(e%10==d%10) m=m*10+0;
		else m=m*10+1; 
	}
}
void co(int h){
	while(l==0){
		l--;
		mk=m%10;
		m/=10;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cop(a[i]);
		if(a[i]==k) he++;
	}
	for(int i=1;i<=n;i++){
		mk=b[i];
		for(int j=i;j<=n-i;j++){
			l=0;
			copp(mk,b[i+j]);
			co(m);
			if(mk==k) he++;
			
		}
		m=0;
		mk=0;
	}
	cout<<he;
	return 0;
}
