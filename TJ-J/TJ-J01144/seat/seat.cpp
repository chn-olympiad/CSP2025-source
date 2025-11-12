#include<bits/stdc++.h>
using namespace std;
const long long MX=101;
long long n,m,t=0,c=0,f=0;
long long arr[MX],b[MX],aa[MX],bb[MX];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i =1;i<=n*m;i++){
	cin>>arr[i];
		if(i==1){
			t=arr[i];

		}

	}
	sort(arr+1,arr+n*m+1);
	for(int i= n*m;i>=1;i--){
		c++;
		b[c]=arr[i];
		if(b[c]==t){
			f=c;

			break;
		}
	}

		if((f/n+1)%2!=0){
			if(f%n==0){
				aa[f]=f/n;
				bb[f]=1;
			}else{
				aa[f]=f/n+1;
				bb[f]=f%n;
			}
		}else{
			if(f%n==0){
				aa[f]=f/n;
				bb[f]=n;
			}else{
				aa[f]=f/n+1;
				bb[f]=n-(f%n)+1;
			}
		}


			cout<<aa[f]<<' '<<bb[f];
	return 0;
}
