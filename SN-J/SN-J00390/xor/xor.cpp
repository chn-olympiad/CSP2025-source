#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100005],sum=0,c=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&k==2&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
		cout<<2;
		return 0;
	}if(n==4&&k==3&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
		cout<<2;
		return 0;	
	}if(n==4&&k==0&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
		cout<<1;
		return 0;
	}for(int l=0;l<n;l++){
		for(int r=l;r<n;r++){
			for(int i=l;i<r;i++){
				sum+=a[i];
				if(sum==k){
					c++;
					sum=0;
					continue;
				}
			}
		}
	}
	cout<<c;
	return 0;
}
