#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ss=0;
	cin>>n>>k;
	int a[n+1];
	bool b[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int xb=1;
	for(int i=1;i<=n;i=xb+1){
		for(int j=i;j<=n;j++){
			int s=a[i];
			for(int h=i+1;h<=j;h++){
				s^=a[h];
			}
			if(s==k){
				ss++;
				xb=j;
				break;
			}
		}
	}
	cout<<ss;
	return 0;
}
