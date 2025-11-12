#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][5],T,n,n_max,c[5],chosen[N];
int maxn;
int flag(int k){
	maxn=max(a[k][1],max(a[k][2],a[k][3]));
	if(maxn==a[k][1])return 1;
	if(maxn==a[k][2])return 2;
	return 3;
}
int find_out(){
	if(c[1]>n_max)return 1;
	if(c[2]>n_max)return 2;
	if(c[3]>n_max)return 3;
}
int find_min(int i,int pos){
	int tmp=0;
	for(int j=1;j<=3;j++)if(a[i][j]>tmp&&j!=pos)tmp=a[i][j];
	return a[i][pos]-tmp;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int tmp=0;tmp<T;tmp++){
		priority_queue<int>q;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		long long ans=0;
		cin>>n;
		n_max=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			chosen[i]=flag(i);c[chosen[i]]++;
			ans+=maxn;
		}
		if(c[1]<=n_max&&c[2]<=n_max&&c[3]<=n_max)cout<<ans<<endl;
		else{
			int pos=find_out();
			for(int i=1;i<=n;i++){
				if(chosen[i]==pos)q.push(-find_min(i,pos));
			}
			
			int tst[N],cnt=0;
			memset(tst,0,sizeof(tst));
			
			for(int i=c[pos];i>n_max;i--){
				ans+=q.top();
				tst[++cnt]=q.top();
				q.pop();
			}
			cout<<ans<<endl;
		}
	} 
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}


//清多测 数据规模 改文件名 验证有输出 文件读写去注释
