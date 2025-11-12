#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	bool A=true,B=true; 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]!=1){
			A=false;
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]!=0&&a[i]!=1){
			B=false;
			break;
		}
	}
	if(A){
		cout<<n/2<<"\n";
	}else if(B){
		if(k==0){
			int sum=0;
			for(int i=0;i<n;i++){
				if(a[i]==0)sum++;
				else{
					int ct=0;
					int j=i;
					for(;a[j]==1;j++){
						ct++;
					}
					sum+=ct/2;
					i=j-1;
				}
			}
			cout<<sum<<"\n";
		}else{
			int sum=0;
			for(int i=0;i<n;i++){
				if(a[i]==1&&a[i+1]==0){
					sum++;
					a[i+1]=10000; 
				}else if(a[i]==1&&a[i-1]==0){
					sum++;
					a[i-1]=10000;
				}
			}
			cout<<sum<<"\n";
		}
	}else {
		vector<ll>pre(n+1);
		for(int i=0;i<n;i++){
			pre[i+1]=pre[i]^a[i];
		}
		int ans=0;
		for(int l=0,r=0;l<=n;){
			int sum=0;
			while(r<=n){
				r++;
				sum=pre[r]^pre[l];
				if(sum==k)break;
				
			}
			if(sum==k)ans++;
			l=r+1;
		}
		cout<<ans<<"\n";
	}
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}
