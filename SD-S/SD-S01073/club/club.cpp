#include<bits/stdc++.h>
using namespace std;
int n,rt[5];
struct node{
	int s1=0,s2=0,s3=0,ans;
}f[1000005][5];
struct node1{
	int x1,x2,x3;
}a[1000005];
bool cmp(node1 a,node1 b){
	if(a.x1==b.x1){
		if(a.x2==b.x2){
			return a.x3>b.x3;
		}
		return a.x2>b.x2;
	}
	return a.x1>b.x1;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x1>>a[i].x2>>a[i].x3;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			f[i][1].ans=0;
			f[i][2].ans=0;
			f[i][3].ans=0;
		}
		for(int i=0;i<=n;i++){
			for(int j=1;j<=3;j++){
				f[i][j].s1=0,f[i][j].s2=0,f[i][j].s3=0;
			}
		}
		f[1][1].s1=1,f[1][2].s2=1,f[1][3].s3=1;
		f[1][1].ans=a[1].x1,f[1][2].ans=a[2].x2,f[1][3].ans=a[3].x3;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=3;j++){//即将改变f[i][j]的位置 
				rt[1]=f[i-1][1].ans,rt[2]=f[i-1][2].ans,rt[3]=f[i-1][3].ans;//rt[j]表示上一步j的位置的答案 
				if(j==1){//要去第一个位置 
					if(f[i-1][1].s1+1>n/2)	rt[1]=-1;//没法由上一步的第一个位置到现在的第一个位置  
					if(f[i-1][2].s1+1>n/2)	rt[2]=-1;//没法由上一步的第二个位置到现在的第一个位置 
					if(f[i-1][3].s1+1>n/2)	rt[3]=-1;//没法由上一步的第三个位置到现在的第一个位置 
				}
				if(j==2){//要去第二个位置 
					if(f[i-1][1].s2+1>n/2)	rt[1]=-1;//没法由上一步的第一个位置到现在的第二个位置 
					if(f[i-1][2].s2+1>n/2)	rt[2]=-1;//没法由上一步的第二个位置到现在的第二个位置 
					if(f[i-1][3].s2+1>n/2)	rt[3]=-1;//没法由上一步的第三个位置到现在的第二个位置 
				} 
				if(j==3){//要去第三个位置 
					if(f[i-1][1].s3+1>n/2)	rt[1]=-1;//没法由上一步的第一个位置到现在的第三个位置  
					if(f[i-1][2].s3+1>n/2)	rt[2]=-1;//没法由上一步的第二个位置到现在的第三个位置 
					if(f[i-1][3].s3+1>n/2)	rt[3]=-1;//没法由上一步的第三个位置到现在的第三个位置 
				} 
				int maxrt=-5,irt=-1;
				for(int k=1;k<=3;k++){
					if(rt[k]>maxrt){
						maxrt=rt[k];
						irt=k;
					}
				}//找到上一步的最优解的值还有其位置
				f[i][j].s1=f[i-1][irt].s1;//继承 
				f[i][j].s2=f[i-1][irt].s2;
				f[i][j].s3=f[i-1][irt].s3; 
				if(irt==1)	f[i][j].s1=f[i-1][irt].s1+1;	
				else if(irt==2)	f[i][j].s2=f[i-1][irt].s2+1;
				else if(irt==3)	f[i][j].s3=f[i-1][irt].s3+1;//从哪来的要加一 
				if(j==1)	f[i][j].ans+=a[i].x1+maxrt;//它本身与上一步的最优解
				else if(j==2)	f[i][j].ans+=a[i].x2+maxrt;//它本身与上一步的最优解
				else if(j==3)	f[i][j].ans+=a[i].x3+maxrt;//它本身与上一步的最优解
			}
		}
		int maxa=-1;
		for(int i=1;i<=3;i++){
			maxa=max(maxa,f[n][i].ans);
		}
		cout<<maxa<<"\n";
	}
	return 0;
}

