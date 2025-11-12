//SN-J00629 杨济铭 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	int a[n];
	bool b[n];
	for(int i=0;i<n;i++){
		b[i]=0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			b[i]=1;
			cnt++;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			bool f=0;
			for(int l=j;l<j+i;l++){
				if(b[l]==1){
					f=1;
					break;
				}
			}
			if(f){
				continue;
			}
			int anw=0;
			for(int l=j;l<j+i;l++){
				anw^=a[l];
			}
			if(anw==k){
				cnt++;
				for(int l=j;l<j+i;l++){
					b[l]=1;
				}
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	
