#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
long long fint(long long q,long long m){
	while(m<n){
		long long x=a[q];
		for(long long i=q+1;i<=m;i++){
			x=x^a[i];
		}
		if(x==k){
			return m;
		}
		m++;
	}
	return n-1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	int q=0,m=0,sum=1;
	while(1){
		int t=fint(q,m);
		if(t!=n-1){
			q=m;
			sum++;
			m=t+1;
		}else{
			q++;
			m++;
			if(q>n-1){
				cout<<sum;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;//#Shang4Shan3Ruo6Shui4
}
