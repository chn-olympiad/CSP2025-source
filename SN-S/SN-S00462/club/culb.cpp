#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,max=0,jin=0,r=0,mus=0,d=3,w=0;
	int a[10001]={},b[10001]={};
	cin>>t;
	for(int i=0;i<t;t++){
		cin>>n;
		for(int j=0;j<n*3;j++){
			cin>>a[i];
			if(a[i]>max||a[i]<n/2){
				max=a[i];
			}
			j++;
			if(j==d-1){
				b[r]=max;
				max=0;
				r++;
				d=d+3;
			}
			for(int k=0;k<n;k++){
			    mus=b[k]+mus;
			}
			cout<<mus;
		    w++;
		}
		if(w==n){
	    	w=0;
	    	mus=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

