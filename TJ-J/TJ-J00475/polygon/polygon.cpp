#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5 , MOD = 998244353;
int n,a[N],ans,c[N][N],maxx=-1;
void ta1(){
	for(int i=0;i<=n;i++){
		c[i][i]=1;
	}
	for(int i=0;i<=n;i++){
		c[i][0]=1;
		if(i>0) c[i][1]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	for(int i=3;i<=n;i++){
		ans+=c[n][i];
		ans=ans%MOD;
	}
	cout<<ans;
}
void ta2(){
	
	if(n>=3){
		if((a[1]+a[2]+a[3])>max(a[1],max(a[2],a[3]))*2) ans+=1;
	}
	if(n>=4){
		if((a[1]+a[2]+a[4])>max(max(a[4],a[1]),a[2])*2) ans+=1;
		if((a[1]+a[3]+a[4])>max(max(a[4],a[1]),a[3])*2) ans+=1;
		if((a[2]+a[3]+a[4])>max(a[4],max(a[2],a[3]))*2) ans+=1;
		if((a[1]+a[3]+a[4]+a[2])>max(max(a[4],a[1]),max(a[2],a[3]))*2) ans+=1;
	}
	if(n>=5){
		if((a[1]+a[3]+a[5]+a[2])>max(max(a[1],a[5]),max(a[2],a[3]))*2) ans+=1;
		if((a[1]+a[4]+a[5]+a[2])>max(max(a[1],a[5]),max(a[2],a[4]))*2) ans+=1;
		if((a[1]+a[4]+a[5]+a[3])>max(max(a[1],a[5]),max(a[3],a[4]))*2) ans+=1;
		if((a[2]+a[4]+a[5]+a[3])>max(max(a[3],a[5]),max(a[2],a[4]))*2) ans+=1;
		if((a[1]+a[3]+a[5]+a[2]+a[4])>max(max(a[4],max(a[1],a[5])),max(a[2],a[3]))*2) ans+=1;
	}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(n<3){
		cout<<0;
		return 0;
	} 
	if(maxx==1){
		ta1();
	}else{
		ta2();
	}
	
	return 0;
}
//5
//1 1 1 1 1 
