#include<bits/stdc++.h>
using namespace std;
int n,a[505],s[505],num;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int k=3;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==3){
				if(s[i-1]>a[i])num+=i-1;
				break;
			}
			if(k==4&&s[i-1]>a[i])
				num++;		
			else{
				if(s[i-1]>a[i])
					num+=i-1;
			}
		}
	}
		
	cout<<num;
	return 0;
}