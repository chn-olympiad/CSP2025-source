#include<bits/stdc++.h>
using namespace std;
int z,siz[5005],qian[5005];
bool cmp(int z,int x){
	return z>x;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int ans=0;
	cin>>z;
	for(int i=1;i<=z;i++){
		cin>>siz[i];
	}sort(siz+1,siz+1+z,cmp);
	if(z<3 || (z==3 && siz[1]*2>=siz[1]+siz[2]+siz[3])){
		cout<<0;
		return 0;
	}else if(z==3 && (siz[1]*2<siz[1]+siz[2]+siz[3])){
		cout<<1;
		return 0;
	}for(int i=1;i<=z;i++){
		qian[i]=qian[i-1]+siz[i];
	}for(int i=1;i<=z;i++){
		cout<<qian[i]<<" ";
	}cout<<endl;
	for(int i=1;i<=z-2;i++){
		for(int j=i+1;j<=z;j++){
			if(qian[j]-qian[i-1]>siz[i]*2){
				ans++;
			}
		}
	}cout<<ans;
	return 0;
}