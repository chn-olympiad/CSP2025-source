#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c=getchar();
	long long s=0;
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=(s<<1)+(s<<3)+int(c-'0');
		c=getchar();
	}
	return s;
}
long long n,a[5005],f,h[25];
bool check(){
	long long mx=-1,sg=0;
	for(int i=1;i<=f;i++){
		mx=max(mx,h[i]);
	}
	for(int i=1;i<=f;i++){
		sg+=h[i];
	}
	return bool(mx*2<sg);
}
long long dfs(long long now,long long c){
//	if(now>n-f+c){
//		return 0;
//	}
	if(c==f){
		return int(check());
	}
	long long sum=0;
	for(int i=now;i<=n;i++){
		h[c]=a[i];
		sum+=dfs(i+1,c+1);
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	if(n<3){
		cout<<"0";
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
		return 0;
	}
	if(n<=20){
		long long xxx=0;
		for(int i=3;i<=n;i++){
			f=i;
			xxx+=dfs(1,1);
		}
		f=n;
		for(int i=1;i<=n;i++){
			h[i]=a[i];
		}
		xxx+=int(check());
		cout<<xxx%998244353;
	}
	else{
		cout<<"0";
	}
	return 0;
}
