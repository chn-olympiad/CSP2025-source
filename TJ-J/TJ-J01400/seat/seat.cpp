#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,c,k,t=0;
	cin>>n>>m;
	long long a[n][m];
	long long s[n*m];
	for(int i=0;i<n*m;i++){
		t=0;
		cin>>s[i];
		if(i==0)c=s[i];
		if(i>=1){
			while(s[i]>s[i-t-1]&&(i-t-1)!=-1){
				k=s[i];
				s[i]=s[i-1-t];
				s[i-t-1]=k;
				t++;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		if(i%2!=0){
			for(long long j=1;j<=n;j++){
				if(s[(i-1)*n+j-1]==c){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for(long long j=n;j>=1;j--){
				if(s[(i-1)*n+(n-j)]==c){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
} 
