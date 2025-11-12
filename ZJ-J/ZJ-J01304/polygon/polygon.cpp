#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,a[500005],t[105],endsum=0;
bool f=0;
struct node{
	int k,ans;
};
void dfs(int sum,int ma,int k){
	f=0;
	//	cout<<sum<<" "<<ma<<" "<<k<<endl;	
	if(k>=3&&ma*2<sum){
		endsum++;
		endsum%=MOD;
		f=1;
	//	cout<<"DAAN!!!:"<<sum<<" "<<ma<<" "<<k<<endl;
	
	}
	if(k==n+1)return;
	if(f){
		dfs(sum+a[k],max(ma*1ll,a[k]),k+1);
	}else{
		dfs(sum+a[k],max(ma*1ll,a[k]),k+1);
		dfs(sum,ma,k+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,1);
	cout<<endsum;
	return 0;
}
//CIALLO,wo xiang shang mi huo xing wei da shang;
//ke yi mang AWA
//luogu ming:Rcwh_De_Shary
//freopen
//freopen
// itn mian[](
//    rteunr 1134713489;
//)
//rto CCF ort
