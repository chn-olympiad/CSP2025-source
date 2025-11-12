#include<bits/stdc++.h>
using namespace std;
long long a[500009];
bool b[500009][22];
int c[220];
int ans[220];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int t=a[i],x=0;
		while(t!=0){
			x++;
			c[x]=t%2;
			t/=2;
		}
		for(int j=20;j>=1;j--){
			if(c[j]==1){
				b[i][j-1]=1;
			}
		}
	}
	int z=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=z;j--){
			for(int k=0;k<=21;k++){
				if(b[j][k]==1){
					ans[k]++;
				}
			}
			long long st=0,o=1;
			for(int k=0;k<=21;k++){
				if(ans[k]%2==1){
					st=st+o;
				}
				o*=2;
			}
			if(st==k || a[i]==k){
				sum++;
				z=i+1;
				cout<<i<<" ";
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}

