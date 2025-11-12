#include<bits/stdc++.h>
using namespace std;

long long  a[5005],mod =  998244353,b[5005];
long long cnt = 0;
int n;
void x(int step,int k,int last){
	if(step==k){
		long long maxn = -4,sum = 0;
		
		for(int i = 1;i<=k;i++){

			sum+=b[i];
		}
		maxn=b[k]*2;
		if(sum>maxn){
		/*	for(int i = 1;i<=k;i++){
				cout<<b[i]<<" ";
			}
			cout<<endl;*/
			cnt++;
		}

		cnt%=mod;
		return ;
	}

	for(int i = last+1;i<=n;i++){

		b[step+1] = a[i];
		x(step+1,k,i);		

		

	}
	
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;

	for(int i =  1;i<=n;i++){
		cin>>a[i];

	}
	sort(a+1,a+n+1);


	for(int i = 3;i<=n;i++){
		x(0,i,0);
		for(int j = 1;j<=i;j++){
			b[i] = 0;
		}
	}
	
	cout<<cnt%mod;
	return 0;
}
