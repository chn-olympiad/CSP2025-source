#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],m,o;
bool d(int q,int w){
	int s=a[q];
	for(int i=q+1;i<=w;++i)s=s^a[i];
	return s==k;
}
void f(int p,int c){
	m=max(m,c);
	for(int i=p;i<n;++i)
		if(d(p,i))f(i+1,c+1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;++i)cin>>a[i];
	if(k==0){
		for(int i=0;i<n;++i)if(a[i]==0)++m;
		cout<<m;
	}else if(k==1){
		bool flag=true;
		for(int i=0;i<n;++i){
			if(a[i]!=0&&a[i]!=1)flag=false;
			if(a[i]==1)++o;
		}
		if(flag)
			cout<<o;
		else{
			f(0,0);
			cout<<m;
		}
	}else{
		f(0,0);
		cout<<m;
	}
	return 0;
}
