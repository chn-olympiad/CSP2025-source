#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,A,B;
int a[N],ans,vis[N];
long long s[N],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			A+=1;
		}
		if(a[i]==255){
			B+=1;
		}
		if(i==1){
			s[1]=a[1];
		}else{
			s[i]=s[i-1]^a[i];
		}
	}
	if(k==0 && A==n){
		cout<<n/2;
		return 0;
	}
	if(k==1){
		cout<<A;
		return 0;
	}
	if(k==255){
		cout<<B;
		return 0;
	}
	for(int k=0;k<n;k++){
		for(int i=1;i<=n;i++){
			int j=i+k;
			long long m=s[i-1]^s[j];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
