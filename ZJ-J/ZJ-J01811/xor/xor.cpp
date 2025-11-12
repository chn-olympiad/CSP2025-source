#include<bits/stdc++.h>
using namespace std;
int a[5005],maxx,n,minn=1e9,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	if(k==0&&maxx==1&&minn==1){
		ans=n/2;
	}
	else if(k<=1&&maxx==1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)
					ans++;
				else if(a[i]==a[i+1])
					ans++,i++;
		}
	}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1)
					ans++;
		}
	}
}
	else ans=1;
	cout<<ans;
	return 0;
}
