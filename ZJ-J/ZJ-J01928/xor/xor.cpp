#include<bits/stdc++.h>
using namespace std;
int k,n,a[500010],f1=0,f2=0,c;
void ok0(){
	cout<<n/2;
	exit(0);
}
void ok1(){
	if(k==0){
		for(int i=0;i<n-1;i++){
			if(a[i]==a[i+1]){
				c++,i++;
			}
		}
	}
	else{
		for(int i=0;i<n-1;i++){
			if(a[i]!=a[i+1]){
				c++,i++;
			}
		}
	}
	cout<<c;
	exit(0);
}
int mx;
void dfs(int s,int i,int c){
	if(i==n){
		mx=max(mx,c);
	}
	if(s==k){
		dfs(0,i+1,c+1);
	}else{
		for(int j=i+1;j<n;j++){
			dfs(s^a[j],j,c);
		}
	}
}
void ok2(){
	dfs(0,0,0);
	cout<<mx;
	exit(0);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) f1=1;
		if(a[i]>1) f2=1;
	}
	if(f1==0&&k==0)
		ok0();
	else if(k<=1&&f2==0)
		ok1();
	else if(k<=255)
		ok2();
	return 0;
}

