#include<bits/stdc++.h>
using namespace std;
int n,a[500005],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0,cnt=0,mx=-100,mx1=-100;
	for(int j=1;j<=k;j++){
		mx=max(mx,a[j]);
	}
	while(mx!=0){
		cnt+=mx%2;
		mx/=2;
	}
	for(int j=k+1;j<=n;j++){
		mx1=max(mx1,a[j]);
	}
	while(mx1!=0){
		ans+=mx1%2;
		mx1/=2;
	}
	cout<<max(cnt,ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

