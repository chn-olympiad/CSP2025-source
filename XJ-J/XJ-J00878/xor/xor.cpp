#include<bits/stdc++.h> 
using namespace std;
int n,k,a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(k==0){
		int x=0;
		for(int i=1;i<=n;i++){
			if((a[i]&&a[i+1])){
				x++;
				i++;
			}
			if(!a[i])
				x++;
		}
		printf("%d",x);
	}
	else{
		int x=0;
		for(int i=1;i<=n;i++)
			if(a[i])
				x++;
		printf("%d",x);
	}
	fclose(stdin);
	fclose(stdout);
}
