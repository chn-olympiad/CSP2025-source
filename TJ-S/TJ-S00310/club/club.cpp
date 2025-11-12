#include<bits/stdc++.h>
using namespace std;
/*
 _________________
|世界上最大的屎山| 
``````````````````
-警告！警告 警告 警告 ！！！！！！！警告 - 

 \( > v < )/ 
 
   
*/
const int N=1e6+520;
int t;
long long ans,cnt;
int l,m,r;
long long a[N][7];
int qpl(int h,int n,int yans,int yl,int ym,int yr){	
	if(h>n) return 0;
	for(int i=1;i<=3;i++){
		if(i==1){
			if(l+1<=n/2){
				ans+=a[h][i];
				l++;
			}
		}else if(i==2){
			if(m+1<=n/2){
				ans+=a[h][i];
				m++;
			}
		}else if(i==3){
			if(r+1<=n/2){
				ans+=a[h][i];
				r++;
			}
		}
		cnt=max(cnt,ans);
		qpl(h+1,n,ans,l,m,r);
		ans=yans;
		l=yl,m=ym,r=yr;
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnt=0;
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		qpl(1,n,0,0,0,0);
		cout<<cnt<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
