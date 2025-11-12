#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,s=0,t=0,m=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			s++;
			t++;
		}else if(a[i]==0){
			t++;
		}
	}
	if(s==n){
		if(k==0){
			cout<<n/2;
			return 0;
		}
	}
	if(t==n){
		if(k==0){
			for(int i=1;i<=n;i=i+2){
				if(a[i]==1&&a[i+1]==1){
					m++;
				}else if(a[i]==0&&a[i+1]==0){
					m+=2;
				}else if(a[i]!=a[i+1]){
					m++;
				}
			}
			if(n%2==0){
				cout<<m;
			}else{
				if(a[n]==0){
					m++;
				}else{
					if(a[n-1]==1&&a[n-2]==0){
						m++;
					}
				}
				cout<<m;
			}
		}else if(k==1){
			for(int i=1;i<=n;i=i+2){
				if(a[i]==1&&a[i+1]==1){
					m+=2;
				}else if(a[i]==0&&a[i+1]==0){
					continue;
				}else if(a[i]!=a[i+1]){
					m++;
				}
			}
			cout<<m;
		}
	}
	return 0;
}
