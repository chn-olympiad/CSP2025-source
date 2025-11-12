#include<bits/stdc++.h>
using namespace std;
int a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int w=0,mx=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		w+=a[i];
		mx=max(mx,a[i]);
	}
	if(n<3){
		cout<<0;
	}
	else if(n==3){
		if(w>mx*2) cout<<1;
		else cout<<0;
	}
	else if(mx==1){
		int ans=0;
		int cnt=1;
		for(int i=3;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt*=j;
			}
			ans+=cnt;
			cnt=1;
		}
		cout<<ans;
	}
	else{
		sort(a,a+n);
		int m=0,c=0,mx=0;
		int s=0;
		for(int j=0;j<n;j++){
			for(int i=j;i<n;i++){
				c+=a[i];
				mx=max(mx,a[i]);
				m++;
				if(m>=3&&c>mx*2){
					s++;
				}
	  		}
			m=0,c=0,mx=0;
		}
		cout<<s;
	}
	return 0;
}
