#include<bits/stdc++.h>
using namespace std;
int a[5003],s=0,n;
void d(int x,int ma,int p,int ss){//递归遍历 
	for(int i=x+1;i<n;i++){
		if(p+1>=3&&(ss+a[i])>max(ma,a[i])*2){//判断成立 
			s++;
			if(s==998244353){//取模 
				s=0;
			}
		}
		d(i,max(ma,a[i]),p+1,ss+a[i]);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);//文件输入输出 
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	d(-1,-1,0,0);//递归 
	cout<<s;
	return 0;
} 
