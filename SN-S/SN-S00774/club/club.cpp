#include <bits/stdc++.h>
using namespace std;
int t,n,sum;
int m[4];//计数 
int a[100005][3];
int d[100005];
int mx=-1;
bool x=true;
bool cmp(int x,int y){
	return x>y;
}
void tool(int i){
	if(i>=n+1)return;
	for(int j=1;j<=3;j++){
		if(m[j]<n/2){
			m[j]++;
			sum+=a[i][j];
			tool(i+1);
			if(sum>=mx)mx=sum;
			sum-=a[i][j];
			m[j]--;
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		m[1]=m[2]=m[3]=0;
		sum=0;
		mx=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			d[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){//特殊性质A 
			if((a[i][2]!=0)&&(a[i][3]!=0)){
				x=false;
				break;
			}
		}
		if(x){
			for(int i=1;i<=n;i++)d[i]=a[i][1];
			sort(d+1,d+1+n,cmp);
			for(int i=1;i<=n/2;i++)sum+=d[i];
			cout<<sum<<endl;
			continue;
		}
		tool(1);
		cout<<mx<<endl;
	}
	return 0;
}
