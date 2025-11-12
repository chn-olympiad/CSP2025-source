#include<bits/stdc++.h>

using namespace std;
unsigned long long a[5000080];
int main(){
	/*while(1){
		int x,y;
	cin>>x>>y;
	cout<<(x^y);
	}*/
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	unsigned long long n;
	unsigned long long k;
	cin>>n;
	cin>>k;
	unsigned long long ans=0;
	for(unsigned long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(unsigned long long i=1;i<=n;i++){
		unsigned long long anss=0,now=0;
		
		for(unsigned long long j=i;j<=n;j++){
			now^=a[j];
			if(now==k){
				anss++; 
				now=0;
			}
		
	}
	ans=max(ans,anss);
	}
	
	cout<<ans;
	return 0;
} 
