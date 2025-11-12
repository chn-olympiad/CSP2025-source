#include<bits/stdc++.h>
using namespace std;
long long n,b,mwz=0;
long long a[4][1000006];
long long dan[1000006];
void solve(long long js,int s1,int s2,int s3,int shu,int b){
	if(shu>b+1){
		return;
	}
	if(s1>b/2){
		return;
	}
	if(s2>b/2){
		return;
	}
	if(s3>b/2){
		return;
	}
	if(shu==b+1){
		mwz=max(mwz,js);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			solve(js+a[i][shu],s1+1,s2,s3,shu+1,b);
		}else if(i==2){
			solve(js+a[i][shu],s1,s2+1,s3,shu+1,b);
		}else{
			solve(js+a[i][shu],s1,s2,s3+1,shu+1,b);
		}
	}
}
int main(){
	freopen("club","r",stdin);
	freopen("club","w",stdout);
	cin>>n;
long long i=0,zh=n;
while(n--){
	i++;
	b=0;
	cin>>b;
	for(int i=1;i<=b;i++){
		cin>>a[1][i]>>a[2][i]>>a[3][i];
	}
	solve(0,0,0,0,1,b);
	dan[i]=mwz;
	mwz=0; 
}
for(int i=1;i<=zh;i++){
	cout<<dan[i]<<endl; 
}
	return 0;
} 

