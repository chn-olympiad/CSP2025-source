/*龚逸宸  SN-S00825 西安市曲江第一学校*/
#include<iostream>
#include<cmath>
using namespace std;
long long a[100005][5],f[5],n;
long long maxx;
void dfs(long long i,long long num){
//	cout<<num<<endl;
	if(i>n){
		maxx=max(num,maxx);
//		cout<<endl;
		return;
	}
	for(int j=1;j<=3;j++){
		if(f[j]<(n/2)){
			f[j]++;
			dfs(i+1,num+a[i][j]);
			f[j]--;
		}
	}
	
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int o=0;o<t;o++){
		cin>>n;
		for(long long i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1,0);
		cout<<maxx<<endl;
		maxx=0;
		for(int i=1;i<=3;i++){
			f[i]=0;
		}
	}
	return 0;
}
