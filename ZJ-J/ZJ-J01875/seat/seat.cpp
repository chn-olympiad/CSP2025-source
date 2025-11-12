#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;
int ans,numlst[105],cont=1,n,m,hang=1,lie=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>numlst[0];
	for(int i=1;i<n*m;i++){
		cin>>numlst[i];
		if(numlst[i]>numlst[0]){
			if(cont==1){
				if(hang<n){
					hang++;
				}else {
					lie++;
					cont = -1;
				}
			}else{
				if(hang>1) {
					hang--;
					
				}else{
					lie++;
					cont =1;
				}
			}
		}

	}
	cout<<lie<<" "<<hang;
	fclose(stdin);
	fclose(stdout);
}
