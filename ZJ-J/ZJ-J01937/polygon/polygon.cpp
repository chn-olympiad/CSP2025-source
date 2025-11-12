#include <bits/stdc++.h>
using namespace std;
int n;
int b[5005];
int cccc=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]!=1){
			cccc=1;
		}
	}
	if(cccc==0){
		cout<<(n-2)*(n-1)/2;
		return 0;
	}
	sort(b+1,b+n+1);
	if(n==3&&b[1]+b[2]>b[3]){
		cout<<1;
		return 0;
	}
	if(n==3&&b[1]+b[2]<=b[3]){
		cout<<0;
		return 0;
	}
	int ant=0;
	for(int i=3;i<=n;i++){
		int cnt=0;
		for(int j=i-1;j>=1;j--){
			
			if(cnt>b[i]&&j!=1){
				ant+=(1+j)*j/2;
				ant++;
				break;
			}
			if(cnt==b[i]&&j!=1){
				ant+=(1+j)*j/2;
				break;
			}if(cnt>b[i]&&j==1){
				
				ant++;
				break;
			}
		}
	}
	cout<<ant;
	return 0;
}
