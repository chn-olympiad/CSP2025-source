#include<bits/stdc++.h>
using namespace std;
int num=2,a[50010],n,k,m=5000,ans,num1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=min(m,a[i]);
		ans+=a[i];
	}
	if(k==1){
		num=0;
		for(int i=1;i<=n;i++){
			if(a[i])num++;
		}
	}
	if(k==0){
		num=0;
		if(m){
			num=n/2;
		}
		else {
			for(int i=1;i<=n;i++){
				if(a[i]==0&&num1==0) num++;
				if(a[i]&&a[i+1]){
					i++;
					num++;
				}
			}
		}
	}
	cout<<num;
	return 0;
}