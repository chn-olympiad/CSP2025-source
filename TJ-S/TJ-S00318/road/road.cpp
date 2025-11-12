#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long mon,jishuqi=0;//ÁÚ½Ó¾ØÕó,¼Û¸ñ 
int san3dai[1000][1000];
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin.tie(0);
	long long n,m,k,x,y;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>mon;
		san3dai[x][y]=mon;
		jishuqi+=mon;
	}
	long long jiancheng[1000],cheng=1;
	while(k--){
		int i;
		cin>>i;
		jiancheng[cheng]=i;
		cheng++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(jiancheng[i]+jiancheng[j]<san3dai[i][j]){
				jishuqi-=(san3dai[i][j]-jiancheng[i]-jiancheng[j]);
			}
		}
	}
	cout<<jishuqi;
	return 0;
}

