#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[50005],m=0,x=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		x=0;
		for(int j=i;j<=n;j++){
			if(a[j]==k&&m<j-i){
				m=j-i;
			}else{
				x=x^a[j];
				if(x==k&&m<j-i){
					m=j-i;
				}
			}
		}
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

