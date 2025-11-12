#include<bits/stdc++.h>
using namespace std;
long long n=0,a[99999],k=0,s=0;
int main(){
	freopen("xor.in",'r',stdin);
	freopen("xor.out",'w',stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				s++;
			}
		}
	}
	else{
		for(int i=1;i<n;i++){
			if(a[i]==k){
				s++;
			}
			for(int j=i+1;j<=n;j++){
				if((a[i]+a[j])%k==0&&a[i]!=0&&a[j]!=0){
					s++;
				}
			}
		}
		if(a[n]==k){
			s++;
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
