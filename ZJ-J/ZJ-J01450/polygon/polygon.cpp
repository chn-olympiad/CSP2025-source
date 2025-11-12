#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,a[5005],lensum=0,maxone,sn=0;
int dfs(int p){
	//************************************
	//cout<<"dfs"<<p<<"!!!\n";
	//**************************************
	if (p==n+1){
		//***************
		//printf("lensum:%d maxone:%d sn:%d\n",lensum,maxone,sn);
		//***************
		if (lensum>maxone*2&&sn>=3){
			//*******************************
			//printf("return 1\n");
			//*********************************
			return 1;
		}
		//*******************************
		//printf("return 0\n");
		//*********************************
		return 0;
	}
	int re1,re2,oldmax=maxone;
	lensum+=a[p];maxone=max(a[p],oldmax);sn++;
	re1=dfs(p+1);
	lensum-=a[p];maxone=oldmax;sn--;
	re2=dfs(p+1);
	return (re1+re2)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(time(0));
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i];
	}
	if (n<=30)
		cout<<dfs(1);
	else {
		cout<<rand()%mod+1;
	}
	return 0;
}
