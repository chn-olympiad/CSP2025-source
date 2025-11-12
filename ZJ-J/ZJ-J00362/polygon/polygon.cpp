#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5005];

int t,mx;
void asd(int l,int nw){
	if(nw==t){
		if(l>mx)ans=(ans+1)%998244353;
		return ;
	}
	asd(l+a[nw],nw+1);
	asd(l,nw+1);
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=3;i<=n;i++){
		t=i;
		mx=a[i];
		asd(0,1);
	}
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
