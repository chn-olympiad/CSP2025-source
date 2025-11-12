#include<bits/stdc++.h>
using namespace std;
int f[100001];
long long d=0;
int main(){
freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
		for(int i=1;i<=100001;i++){
			cin>>f[i];
		}
		
		for(int i=1;i<=100001;i++){
			if(f[i]<f[i+1]){
				f[i]=d;
				f[i+1]=f[i];
				d=f[i+1];
			}
				if(f[i]!=0){
					cout<<f[i];
				}
			
		}
			fclose(stdin);
fclose(stdout);
	return 0;
	}

