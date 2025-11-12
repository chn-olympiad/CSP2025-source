#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,k,god;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if(a[i]==k) god++;	 
	}
	if(k==0){
		int i=2;
		while(i<=n){
			if(a[i]!=0 && a[i]==a[i-1]){
				god++;
				i=i+2;
			}
			else{
				i++;
			}
		}
	}
	else{
		int i=2;
		while(i<=n){
			if(a[i]!=0 && a[i]!=a[i-1] && a[i]!=1 && a[i-1]!=1){
				god++;
				i=i+2;
			}
			else{
				i++;
			}
		}
	}
	printf("%d",god);
	
	return 0;
}
