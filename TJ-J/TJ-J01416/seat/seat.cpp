#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100]={},b[100]={};
	cin>>n>>m;
	int x=m*n,z=0;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	z=a[1];
	sort(a,a+m*n);
	int y=0;
	for(int i=x;i>=1;i--){
		b[y]=a[i];
		y++;
	}
	int q=1,w=1;
	while(w<=m){
		int i=1,j=1;
		q=1;
		while(w%2==1){
			if(a[i]==z){
				cout<<w<<" "<<q;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
			if(q>n){
				w++;
			}
			else q++;
			i++;
		}
		q=n;
		while(w%2==0){
			if(a[j]==z){
				cout<<w<<" "<<q;
				fclose(stdin);
		  		fclose(stdout);
				return 0;
			}
			if(q<1){
				w++;
			}
			else q--;
			j++;
		}
	}
	return 0;
}

