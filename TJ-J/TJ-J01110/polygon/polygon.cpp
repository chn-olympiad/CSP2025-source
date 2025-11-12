#include<bits/stdc++.h>
using namespace std;
int n,a[10000],m,he,l;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3){
		for(int i=1;i<=n;i++){
			cin>>a[i];	
			}
		if(n<3) cout<<0;
		else{
			for(int i=1;i<=n;i++){
				he+=a[i];
				m=max(m,a[i]);
				
			}
			if(he-m>m) cout<<1;
			else cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++){
		for(int j=3;j<=n;j++){
			for(int k=i;k<=j;k++){
				he+=a[i];
				m=max(m,a[i]);
			}
			if(he>m*2) l++;
			he=0;
			m=0;
		}
	}
	cout<<l;
	return 0;
}
