#include<bits/stdc++.h>
using namespace std;
int n,a[11451],ans=0,p,l;
int name[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
	 	cout<<0;
	 	return 0;
	}else if(n==3){
		if(a[0]+a[1]+a[2]>2*max(a[0],max(a[1],a[2]))){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i;j++){
			name[j]=j;
		}
		while(name[1]<n-i){
			p=0;
			l=0;
			for(int j=1;j<=i;j++){
				p+=a[name[j]];
				l=max(l,a[name[j]]);
			}
			if(p>2*l){
				ans++;
			}
			if(name[1]>=n-i+1){
				break;
			}
			name[i]++;
			for(int j=i;j>0;j--){
				if(name[j]>n-i+j){
					name[j-1]++;
					for(int k=j;k<=i;k++){
						name[k]=name[k-1]+1;
					}
				}
			}
			ans=ans%998244353;
		}
	}
	cout<<ans%998244353;
	return 0;
}
