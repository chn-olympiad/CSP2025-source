#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int c1[5005],c2[5005],c3[5005];
int x[5005],y[5005],z[5005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,maxn=0;
		cin>>n;
		int cn1=0,cn2=0,cn3=0;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
			if(x[i]>y[i]&&x[i]>z[i]){
				cn1++;
				c1[cn1]=x[i];
			}
			else if(y[i]>x[i]&&y[i]>z[i]){
				cn2++;
				c2[cn2]=y[i];
			}
			else{
				cn3++;
				c3[cn3]=z[i];
			}
		}
		sort(c1+1,c1+1+cn1,cmp);
		sort(c2+1,c2+1+cn2,cmp);
		sort(c3+1,c3+1+cn3,cmp);
		if(c1[1]==0&&c2[1]==0){
			for(int i=1;i<=n/2;i++){
				maxn+=c3[i];
			}
			cout<<maxn;
			return 0; 
		}
		else if(c1[1]==0&&c3[1]==0){
			for(int i=1;i<=n/2;i++){
				maxn+=c2[i];
			}
			cout<<maxn;
			return 0; 
		}
		else if(c3[1]==0&&c2[1]==0){
			for(int i=1;i<=n/2;i++){
				maxn+=c1[i];
			}
			cout<<maxn;
			return 0; 
		}
		if(cn1+cn2+cn3==n&&cn1<=n/2&&cn2<=n/2&&cn3<=n/2){
			for(int i=1;i<=cn1;i++){
				maxn+=c1[i];
			}
			for(int i=1;i<=cn2;i++){
				maxn+=c2[i];
			}
			for(int i=1;i<=cn3;i++){
				maxn+=c3[i];
			}
			cout<<maxn;
			return 0; 
		}
	}
	return 0;
}

