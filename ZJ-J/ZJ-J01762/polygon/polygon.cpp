#include<bits/stdc++.h>
using namespace std;
long long a[5010];
long long s;
long long k;
long long m;
long long d;
long long n;
bool b[5010];
void dfs(int i){
	if(i>n){
		if(k>m*2&&d>=3){
			s++;
			s=s%998244353;
		}
		return ;
	}
	long long nm=m;
	m=a[i];
	d++;
	k+=a[i];
		b[i]=1;
	dfs(i+1);
		b[i]=0;
	m=nm;
	d--;
	k-=a[i];
	dfs(i+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			f=0;
		}
	}
	if(f){
		long long w=1;
		long long j=n;
		while(j--){
			w*=2;
		}
		w=w-n*(n-1)/2-n-1;
		cout<<w;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1);
	cout<<s%998244353<<endl;
	return 0;
}
