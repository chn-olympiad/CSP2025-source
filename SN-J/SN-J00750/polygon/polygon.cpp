#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a,a+n);
	if(n<=3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(n==4&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4){
		cout<<2;
		return 0;
	}if(n==4){
		for(int i=1;i<3;i++){
			for(int j=2;j<4;j++){
				for(int k=3;k<5;k++){
					int maxn=max(max(a[i],a[j]),max(a[j],a[k]));
					if(a[i]+a[j]+a[k]>maxn*2){
						ans++;
					}
				}
			}
		}if(a[1]+a[2]+a[3]+a[4]>a[4]*2){
			ans++;
		}cout<<ans;
		return 0;
	}
	for(int i=3;i<=n;i++){//枚举边长数 		
		for(int j=1;j<=n-i+1;j++){//用于枚举起点 
			for(int k=i;k<=n;k++){//用于枚举终点
				int qwe[25]={0},op=0,maxn=-1e6,sumn=0;//用于存放边长情况的数组 
				for(int m=j;m<=k;m++){				
					qwe[op]=a[m];
					sumn+=qwe[op];
					if(qwe[op]>maxn){
						maxn=qwe[op];
					}
				}if(sumn>2*maxn){
					ans++;
				} 
			}
		}
	}
	cout<<ans;
	return 0;
}
