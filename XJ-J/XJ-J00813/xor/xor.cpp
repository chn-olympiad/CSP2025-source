#include<bits/stdc++.h>
using namespace std;
int a[1000006],b[1000006],c[1000006];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int d=0,e=0,f=0,g=0;
	cin>>d>>e;
	for(int i=0;i<d;i++){
		cin>>a[i];
	} 
	for(int k=0;k<d;k++){
		for(int j=k;j<d;j++){
			b[k]=a[k];
			if(b[k]&b[k]==e){
				f++;
			}
			for(int i=k+1;i<j;i++){
				b[i]=a[i];
				g=b[i-1]&b[i];
				if(g!=e){
					g=0;
					break;
				}
			}
			if(g!=0){
				f++;	
			}
		}
	}
	cout<<f+1;
	return 0;
} 
