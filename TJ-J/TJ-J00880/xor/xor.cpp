#include<bits/stdc++.h>
using namespace std;
int n,a[500005],k,f,cnt,b[500005],cnt1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			f=1;
			cnt++;
		}
		if(a[i]==1){
			cnt1++;
		}
	}
	if(k==0){
		for(int i=1;i<=n-1;i++){
			if(b[i]==0){
				if(a[i]==1&&a[i+1]==1){
					cnt++;
					b[i]=1;
					b[i+1]=1;
				}
			}
		}
		cout<<cnt;
	}
	if(k==1&&f==0){
		cout<<n;
	}
	if(k==1&&f==1){
		cout<<cnt1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
