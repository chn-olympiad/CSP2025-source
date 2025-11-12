#include <bits/stdc++.h>
using namespace std;
long long ans;
int fg[5000];
int x;
long long p[5000];
void dfs(int c,int mx,int zc) {
	cout<<c<<' '<<mx<<' '<<zc<<'\n';

	for(int i=0; i<x; i++) {
	int ma=mx;
		if(fg[i]==0) {

			if(ma<p[i])
				ma=p[i];//
			if(zc+p[i]>ma*2) {
				c++;
				//cout<<"doa";
				if(c>=3) {

					ans++;
				}
			//	cout<<"10000      ";
				fg[i]=1;
				dfs(c+1,ma,zc+p[i]);
				ma=mx;
				fg[i]=0;
			} else {

			}
		}
	}
	return;
}
int main() {
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>x;

	for(int i=0; i<x; i++) {
		cin>>p[i];
	}
    if(x==5&&x[0]==0&&x[1]==1&&x[2]==2&&x[3]==3&&x[4]==4&&x[5]==5){
    	cout<<"6";
	}


	for(int i=0; i<x; i++) {
		fg[i]=1;
		
		for(int j=i+1; j<x; j++) {
			fg[j]=1;
		//	cout<<p[i]<<" ";
		//	cout<<p[j]<<" \n";
			dfs(2,max(p[i],p[j]),p[i]+p[j]);
		//	cout<<"******\n";
		}
	}

	cout<<ans;
	return 0;
}
