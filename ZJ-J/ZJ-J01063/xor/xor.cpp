#include<bits/stdc++.h>
using namespace std;
long long n,k,mx=0,ans=0,a[100086];
bool t[1000086];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=0;
	}if(k==0){
		cout<<ceil(n/2.0);
		return 0;
	}
	for(int i=1;i<=n;i++){
		int b=a[i];
		if(b==k||t[i]==0){
				ans++;
				t[i]=1;
			} 
		for(int j=i+1;j<=n;j++){
			b=b^a[j];
			if(t[j]==1) break;
			if(b==k){
				ans++;
				t[j]=1;
			}mx=max(ans,mx);
		}ans=0;
		for(int j=1;j<=n;j++) t[j]=0;
	}
	cout<<mx;
	return 0;
}

