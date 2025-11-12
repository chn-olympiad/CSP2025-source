#include<bits/stdc++.h>

using namespace std;
int t,n;
int a[10005],b[10005],c[10005];
int on[10005],tw[10005];//最大和第二小的值 
int fi[10005],se[10005];//最大和第二大值的位置 
int fan[10005];
int fuzhi[10005];
int tong[10005];
int maxx,zhong,minn;
int cnt,biao,sign;
/*
先将每一个n中的三个数的最值求出来并进行标记，标记每一个位置出现了几次
判断位置出现的最大次数和ans之间的大小
小于等于ans就直接 将每一个的最大值相加
如果大于，就先进行数组排序，得到后面的ans个数相加，并标记如果位置是这个数的那么另外的俩个就直接不用相加减了
这时候会分为两类，一个是ans位置前后的值不一样，另一个是ans前后的值是一样的 
最后层层的递减最终求和得出答案 
*/

void check(int a[],int b[],int c[],int i){
	if(a[i]>=b[i]){
		on[i]=a[i];
		fi[i]=1;
		tw[i]=b[i];
		se[i]=2;
	}
	else if(a[i]<b[i]){
		on[i]=b[i];
		fi[i]=2;
		tw[i]=a[i];
		se[i]=1;
	}
	if(on[i]>=c[i]){
		if(tw[i]>=c[i]){
			on[i]=on[i];
			fi[i]=fi[i];
			tw[i]=tw[i];
			se[i]=se[i];
		}
		else{
			tw[i]=c[i];
			se[i]=3;
		}
	}
	else if(on[i]<c[i]){
		on[i]=c[i];
		fi[i]=3;
		if(a[i]>=b[i]){
			tw[i]=a[i];
			se[i]=1;
		}
		else{
			tw[i]=b[i];
			se[i]=2;
		}
	}
}//没有问题，这里面就可以求出来最大值和第二大的值以及这两值的位置 

void fanzhuan(int on[]){
	for(int i=1;i<=n;i++){
		fan[i]=on[n-i+1];
	}
	for(int i=1;i<=n;i++){
		on[i]=fan[i];
	}
}//将数组倒序输出 

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		int ans=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			check(a,b,c,i);	
		}
//on[],tw[]储存值的最大和第二大的数组 
//fi[],se[]储存值位置的最大和第二大的数组
		
		for(int i=1;i<=n;i++){
			fuzhi[i]=on[i];
		}
		for(int i=1;i<=n;i++){
		 	if(fi[i]==1){
		 		maxx++;
			}
			else if(fi[i]==2){
				zhong++;
			}
			else if(fi[i]==3){
				minn++;
			}
		}
		int num=0;
		if(n==2){
			if(on[1]+tw[2]>=on[2]+tw[1]){
				cout<<on[1]+tw[2]<<'\n';
			}
			else{
				cout<<on[2]+tw[1]<<'\n';
			}
		}
		
		if(max({minn,zhong,maxx})<=ans){
		 	for(int i=1;i<=n;i++){
		 		num+=on[i];
			}
			cout<<num<<'\n';
		}
		else{
			sort(on+1,on+1+n);
			fanzhuan(on);//将数组倒序输出 
			if(on[ans]!=on[ans+1]){
				for(int i=1;i<=n;i++){
					if(fuzhi[i]>=on[ans]){
						num+=fuzhi[i];
					}
					else{
						num+=tw[i];
					}
				}
				cout<<num<<'\n';
			}
			else{
				for(int i=1;i<=n;i++){
					if(fuzhi[i]==on[ans]){
						biao++;
						tong[i]=tw[i];
					}
					else if(fuzhi[i]>on[ans]){
						num+=fuzhi[i];
						sign++;
					}
					else if(fuzhi[i]<on[ans]){
						num+=tw[i];
					}
				}
				int s=ans-sign;
				sort(tong+1,tong+1+n);
				fanzhuan(tong);;
				for(int i=1;i<=n;i++){
					if((fuzhi[i]==on[ans])&&(i<=s)){
						num+=fuzhi[i];
					}
					else{
						num+=tong[i];
					}
				}
				cout<<num<<'\n';
			}
		}
	}
	
	return 0;
} 
