#include<bits/stdc++.h>
using namespace std;
int xi[5005],a[5005],n;
bool cmp(int x,int y){
	return x>y;
}
int gui(int l_s,int l_y,int ans){
	if(l_y+1>=l_s){
		int yan=0;
		for(int i=2;i<=l_y;i++){
			yan+=xi[i];
		}
		for(int r=n;r>=xi[l_y]+1;r--){
			if(r>xi[1]-yan){
				return ans+=r-xi[l_y];
			}
		}
		return 0;
	}
	if(l_y==0){
		for(int l=1;l<=n-l_s+1;l++){
			xi[1]=a[l];
			ans+=gui(l_s,1,0);
		}
		return ans;
	}
	for(int r=xi[l_y]+1;r<=n-(l_s-l_y)+1;r++){
		xi[l_y+1]=a[r];
		ans+=gui(l_s,l_y+1,ans);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int ans=0;
	for(int i=3;i<=n;i++){
		ans+=gui(i,0,0);
	}
	cout<<ans;
	return 0;
}
