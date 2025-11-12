#include <bits/stdc++.h>
using namespace std;
int n,m;
int cj[15];
int main(){
	freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	int mb=cj[1];
for(int i=1;i<=n*m-1;i++){
    if(cj[i]<cj[i+1]) swap(cj[i+1],cj[i]);
}
	int wz=0;
	for(int i=1;i<=n*m;i++){
		if(cj[i]==mb){
			wz=i;
			break;
		}
	}
		int step=1;
	for(int i=1;i<=n;i++){
		if(i%2!=0){
		for(int j=1;j<=m;j++){
            if(cj[i*j]==mb&&step==wz){
               	cout<<i<<" "<<j;
               	return 0;
		      }
		      step++;
	     	}
		  }else{
		    for(int j=m;j>=1;j--){
            if(cj[i*j-n]==mb||cj[i*j-n+1]==mb&&step==wz){
               	cout<<i<<" "<<j;
               	return 0;
		   }
		   step++;
	     }
       }
     }
   fclose(stdin);
   fclose(stdout);
	return 0;
}
