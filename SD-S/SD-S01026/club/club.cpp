#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int t,ans[10],ans2[200000],mmm;
struct club{
	int pos,sat;
}a[200000][3];
void exan(int ji,int kza,int kzb){
	int ex;
	ex=a[ji][kza].sat;
	a[ji][kza].sat=a[ji][kzb].sat;
	a[ji][kzb].sat=ex;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	mmm=t;
	for(int i=1;i<=mmm;i++){
		int n,sum=0;
		unsigned long long sumzh=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k].sat;
				a[j][k].pos=k;
			}
			if(a[j][2].sat>a[j][1].sat&&a[j][2].sat>a[j][3].sat) {
				exan(j,1,2);
				if(a[j][3].sat>a[j][1].sat) exan(j,1,3);
			}
			if(a[j][3].sat>a[j][1].sat&&a[j][3].sat>a[j][1].sat) {
				exan(j,1,3);
				if(a[j][2].sat>a[j][1].sat) exan(j,1,2);
			}
		}
		if(n==2){
			if(a[1][1].pos!=a[2][1].pos) ans[1]=a[1][1].sat+a[2][1].sat;
			if(a[1][2].pos!=a[2][1].pos) ans[2]=a[1][2].sat+a[2][1].sat;
			if(a[1][3].pos!=a[2][1].pos) ans[3]=a[1][3].sat+a[2][1].sat;
			if(a[1][1].pos!=a[2][2].pos) ans[4]=a[1][1].sat+a[2][2].sat;
			if(a[1][2].pos!=a[2][2].pos) ans[5]=a[1][2].sat+a[2][2].sat;
			if(a[1][3].pos!=a[2][2].pos) ans[6]=a[1][3].sat+a[2][2].sat;
			if(a[1][1].pos!=a[2][3].pos) ans[7]=a[1][1].sat+a[2][3].sat;
			if(a[1][2].pos!=a[2][3].pos) ans[8]=a[1][2].sat+a[2][3].sat;
			if(a[1][3].pos!=a[2][3].pos) ans[9]=a[1][3].sat+a[2][3].sat;
			int po=10;
			sort(ans+1,ans+1+po);
			cout<<ans[10]<<"\n";
			return 0;
		}
		for(int j=1;j<=n;j++) ans[j]=a[j][1].sat;
		sort(ans+1,ans+1+n);
		for(int j=n/2+1;j<=n;j++) {
//			cout<<ans[j]<<" ";
			sumzh+=ans[j];
		}
		cout<<sumzh<<"\n";
	}
	
	return 0;
}
//csp-s RP++
