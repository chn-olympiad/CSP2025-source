#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[101];
	int u[101] = { };
	cin>>a;
	int l = strlen(a);
	for(int i = 0;i<l;i++){
		if(a[i]>=48&&a[i]<=57){
			u[int(a[i])-48]+=1;
		}
	}
   for(int i = 9;i>=0;i--){
   	if(u[i] > 0){
 		for(int j = 1;j<=u[i];j++){
   			cout<<i;
		   }
	   }
   }
   fclose(stdin);
   fclose(stdout);
   return 0;
}
