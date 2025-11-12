#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+5];
	bool b=1,c=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)b=0;
		if(a[i]>1)c=0;
	}
	if(b==1&&k==0){
		cout<<n/2;
		return 0;
	}else if(b==1&&k==1){
		cout<<n;
		return 0;
	}
	int ans=0;
	if(c==1&&k==0){
		int f=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)f++;
			if(f==2){
				f=0;
				ans++;
				continue;
			}
		}
	}else if(c==1&&k==1){
		int f=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
				continue;
			}
		}
	}
	if(c==1){
		cout<<ans;
		return 0;
	}
	int sum=0;
	for(int l=1;l<=n;l++){
		int x=a[l];
		for(int r=l;r<=n;r++){
			if(l!=r){
				x=x^a[r];
			}
			if(x==k){
				sum++;
				l=r;
				break;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}