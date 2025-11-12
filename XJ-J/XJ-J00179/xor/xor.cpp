#include<bits/stdc++.h>
using namespace std;
int nl[200100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>nl[i];
	}int maxij=-1;
	for(int i=0;i<n;i++){
		for(int j=n-i;j<n;j++){
			int yih=nl[i];
			for(int a=i+1;a<=j;a++){
				yih=yih ^ nl[a];
			}if(yih>maxij){
				maxij=yih;
			}
		}
	}cout<<maxij-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
