#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,k,x;
bool h=1,l=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)h=0;
		if(a[i]>1)l=0;
	}
	if(h){
		cout<<n/2;
		return 0;
	}
	if(l){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)x++;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0)x++;
			}
		}
		cout<<x;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}