#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,s[500005],f=1,b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) f=0;
	}
	if(f){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) b++;
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==0) b++;
			}
		}
		cout<<b;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
