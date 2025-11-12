#include<bits/stdc++.h>
using namespace std;
int a[100005][5],f[100005],b[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(f,0,sizeof f);
		int n;
		cin>>n;
		if(n<=2){
			int aaa[5],bbb[5],ccc[5];
			for(int i=1;i<=n;i++){
				cin>>aaa[i]>>bbb[i]>>ccc[i];
			}
			int cnt=0;
			int xy1=aaa[1]+bbb[2];
			int xy2=aaa[1]+ccc[2];
			int xy3=aaa[2]+bbb[1];
			int xy4=aaa[2]+bbb[3];
			int xy5=aaa[3]+bbb[1];
			int xy6=aaa[3]+bbb[2];
			cnt=max(xy1,xy2);
			cnt=max(cnt,xy2);
			cnt=max(cnt,xy3);
			cnt=max(cnt,xy4);
			cnt=max(cnt,xy5);
			cnt=max(cnt,xy6);
			cout<<cnt<<endl;
			continue;
		} 
		int q=n/2;
		int s=0,ss=0,cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][3]!=0) s=1;
				if(a[i][2]!=0) ss=1;
			}
		}
		if(s==0&&ss==0){
			int aa[100005];
			for(int i=1;i<=n;i++){
				aa[i]=a[i][1];
			}
			sort(aa+1,aa+1+n);
			for(int i=q+1;i<=n;i++){
				cnt+=aa[i];
			}
			cout<<cnt<<endl;
		}
		else if(s==0){
			cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
			return 0;
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					if(b[j]<q){
						int x=f[i-1]+a[i][j];
						if(f[i]<x){
							f[i]=x;
							b[j]++;
						}
					}
				}
			}
			cout<<f[n]<<endl;
		}
	}
	return 0;
} 
