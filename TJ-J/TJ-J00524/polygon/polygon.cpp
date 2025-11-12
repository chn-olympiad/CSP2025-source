#include<bits/stdc++.h>
using namespace std;
int ge=0;

void fang(int* la,int l,int r,int she,int ad,int ma){
	int m;
	if(she>1){
		for(int i=l;i<=r;i++){
			fang(la,i+1,r,she-1,ad+(*(la+i)),max(ma,*(la+i)));
		}	
	}else{
		for(int i=l;i<=r;i++){
		m=max(ma,*(la+i));
		if(2*m<ad+(*(la+i)))ge++;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int k;
	cin>>k;
	int a[k];
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	for(int i=3;i<=k;i++){
		fang(&a[0],0,k-1,i,0,0);
	}
	cout<<ge%998244353;
	return 0;
} 
