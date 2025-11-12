#include<bits/stdc++.h>

using namespace std;
long long n,k;
long long a[500009],b[500009],c[500009]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long sum=0,q=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			sum++;
		}else{
			q++;
			b[q]=a[i];
		}
	} 
	//for(long long i=1;i<=q;i++){
	//	long long w[500009];
	//	int y=0;
	//	long long e=b[i];
	//	while(e){
	//		long long r=e%2;
	//		y++;
	//		w[y]=r;
	//		e/=2;
	//	}
	//	for(int j=y;j>=1;j--){
	//		c[i]=c[i]*10+w[j];
	//	}
	//}
	
	
	
	cout<<sum;
	return 0;
}
