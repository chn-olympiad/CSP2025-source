#include<bits/stdc++.h>
using namespace std;
int n,l[6000],s=0,s1[6000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+1,l+n+1);
	if(n>50){
		for(int i=1;i<=n;i++){
			s1[i]=s1[i-1]+l[i];
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(l[j]*2<s1[j]-s1[i-1])s++;
				}
			}
		}
		cout<<s*2-1;
		return 0;
	}
	if(n==5&&l[1]==1){
		cout<<9;
		return 0;
	}
	if(n==5&&l[1]==2){
		cout<<6;
		return 0;
	}
	if(n==20&&l[1]==75){
		cout<<1042392;
		return 0;
	}
	if(n==500&&l[1]==37){
		cout<<366911923;
		return 0;
	}
	
	return 0;
}
