#include<bits/stdc++.h>
using namespace std;
int T,a[100005][5],n;
int sum(int t,int s,int x,int y,int z){
	if(t<n){
		for(int i=1;i<=3;i++){
			if (x<n/2&&i==1) s=max(s,sum(t++,s+a[t++][i],x++,y,z));
			if (y<n/2&&i==2) s=max(s,sum(t++,s+a[t++][i],x,y++,z));
			if (z<n/2&&i==3) s=max(s,sum(t++,s+a[t++][i],x,y,z++));
		}
    }
	    else{
		return s;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) 
		  cin>>a[i][1]>>a[i][2]>>a[i][3];
		cout<<sum(0,0,0,0,0);
	}
}
