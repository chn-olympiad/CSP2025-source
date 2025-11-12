#include<bits/stdc++.h>
using namespace std;
int a[1001],b[1001],n,m,z,e=0,f=0,g=0,h,c[1001]; //a[1001]为题目难度 ,b[1001]为人的耐心上线 ,z表示耐心最少 
int main(){
	freopen("employ.in""r"stdin)
	freopen("employ.out""w"stdout)
	cin>>n>>m;//m为希望录取人数，n为来面试人数 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}for(int i=0;i<n;i++){
		cin>>b[i];
	}for(int i=0;i<=n;i++){//难度太高需耐心度最低的 
		if(a[i]==0){
			for(int j=0;j<=n;j++){
			 if(b[j]<b[j+1]){
			 	z=b[j];
			    }
			}
		}
	} for(int i=0;i<n;i++){
		if(z==b[i]){
		   e+=1;
		}
	}for(int i=0;i<n;i++){
		if(a[i]==0){
			f+=1;
		}
	}g=f-e;
	if(g<0){
		g=n-f;
	}else{
		g=f-e;}
	if(g>m){
		for(int i=1;i<=g;i++){
			int qw=m-i,we=m-n;
			int er=we-i;
			g=m*qw/we*er;
	}}
	cout<<g;
	return 0;
}
