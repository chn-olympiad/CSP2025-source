#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
#define long long long
using namespace std;
bool cmp(long a,long b){
	if(a!=b) return a>b;
}
long a[109],n,m,No,c,r,me,x[3]={0,-1,1},y[3];//n是行数,m是列数,c是列,r是行 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	y[1]=n;y[2]=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) me=a[i];
	}
	int nxm=n*m;
	sort(a+1,a+nxm+1,cmp);
	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
		if(a[i]==me){
			No=i;
		}
	}
//	cout<<endl;
//	cout<<me;
	int k=1;
	for(int i=1;i<=m;i++){//枚举列 
		for(int j=y[(i%2)+1],l=1;l<=n;j+=x[(i%2)+1],k++,l++){//枚举行
//			cout<<i<<' '<<j<<"\n";
//cout<<k<<" ";
//			cout<<a[k]<<endl;
			if(a[k]==me) {
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}	
	}
	return 0;
}

