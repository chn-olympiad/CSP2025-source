#include<bits/stdc++.h>
using namespace std;
int a[20001];
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	int n,k,ans=0;
	bool c=true;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if((a[i]!=1)&&(a[i]!=0)) c=false;
	}
	if(k==0) printf("%d",n);
	else if(c){
		for(int i=1;i<n;i++){
			if(a[i]!=a[i+1]){
				ans++;
				i++;
			}
		}
		printf("%d",ans);
	}
	return 0;
}
