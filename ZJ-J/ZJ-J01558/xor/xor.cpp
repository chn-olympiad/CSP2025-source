#include<bits/stdc++.h>
using namespace std;
int jz(int x){
	int c;
	if(x==0) return 1;
	for(int i=1;i<=x;i++){
		c*=2;
	}
	return c;
}
int er(int x){
	int x1[16],k=0,x2=0;
	while(x){
		x1[++k]=x%2;
		x/=2;
	}
	for(int i=k;i>=1;i--){
		x2+=10*x+x1[i];
	}
	return x2;
}
int xor1(int x,int y){
	string a,b;
	while(x){
		a+=x%10;
		x/=10;
	}
	for(int i=0;i<a.size();i++) swap(a[i],a[a.size()-i]);
	while(y){
		b+=y%10;
		y/=10;
	}
	for(int i=0;i<b.size();i++) swap(b[i],b[b.size()-i]);
	int c;
	int l=max(a.size(),b.size());
	if(a.size()>b.size()){
		string b1;
		for(int i=1;i<=a.size()-b.size();i++){
			b1+='0';
		}
		b=b1+b;
	}
	else{
		string a1;
		for(int i=1;i<=b.size()-a.size();i++){
			a1+='0';
		}
		a=a1+a;
	}
	for(int i=1;i<=l;i++){
		if(a[i]!=b[i]) c+=jz(l-i);
	}
	return c;
}
int n,k,a[500005],b=1,c,d,e,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) b=0;
		if(!a[i]) c++;
		if(a[i]==1) d++;
	}
	if(!k&&b){//1
		cout<<n/2;
		return 0;
	}
	if(k<=1){//2
		if(!k) cout<<c/2+d/2;
		else{
			if(d>c) d-=(d-c)*2/3,c+=(d-c)*2/3;
			cout<<min(c,d);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j) e=a[i];
			else e=xor1(er(e),er(a[j]));
			if(e==k) sum++;
		}
	}
	cout<<sum+1;
	return 0;
}