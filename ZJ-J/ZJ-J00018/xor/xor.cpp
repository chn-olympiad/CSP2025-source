#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001],k,d;
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==m){
			b[i]=0;
			k=i;
			d++;
		}
		else if(a[i]!=0){
			b[i]=a[i]^b[i-1];
			for(int j=k;j<i;j++){
				if((b[i]^b[j])==m){
					d++;
					b[i]=0;
					k=i;
					break;
				}
			}
		}
	}
	cout<<d;
	return 0;
}
