#include<iostream>
using namespace std;
int n,k,ma=0,c=0;
int a[5000005];
int cnt[5000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[i]=0;
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){	
		    int ans=0;
			if(l==r){
				ans=a[l];
			}
			else{
				for(int ix=l;ix<=r;ix++){
					ans^=a[ix];
				}
			}
			if(ans==k&&cnt[l]!=1&&cnt[r]!=1){
				c++;
				for(int ix=l;ix<=r;ix++){
					cnt[ix]=1;
				}
			}
		}
	}
	cout<<c;
	return 0;
}
