#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,m,c[505],a[505];
long long jc(long long x){
	long long s=1;
	for(int i=2;i<=x;i++){
		s=(s*i)%998244353;
	}
	return s%998244353;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	char ch;
	for(long long i=1;i<=n;i++){
		cin>>ch;
		a[i]=a[i-1];
		if(ch=='0'){
			a[i]++;
		}
	}
	for(long long i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(a[n]==0){
		long long s=0;
		for(long long i=1;i<=n;i++){
			if(c[i]>0){
				s++;
			}
		}
		if(s<m){
			cout<<0;
		}else{
			cout<<jc(n);
		}
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
