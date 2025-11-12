#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,a[500001],h[22000][22000],t[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(h,0,sizeof(h));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h[i][i]=a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(r!=l){
				h[l][r]=h[l][r-1]^a[r];
			}
			if(h[l][r]==k&&(ans==0||(l>t[ans]))){
				ans++;
				t[ans]=r;
				break;
			}
			
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
