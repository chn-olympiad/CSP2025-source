#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,xz[25][25],js1=1,js2=1;//js计数 
int l;
bool pd(int y[],int gs){
	int sum1,m;
	for(int i=1;i<=gs;i++){
		sum1+=y[i];
		m=max(m,y[i]);
	}
	if(sum1>2*m) return 1;
	else return 0;
}
void dfs(int k,int gs,int now){//k是a[]中的第k根，gs是目标n边形 
	//nuw是现在的根数
	if(now>gs){
		if(pd(xz[js1],gs)){
			js1++,sum++;
		}
		return;
	}
	if(gs-now>n-k+1) return;
	for(int i=1;i>=0;i--){
		if(!i) dfs(k+1,gs,now);
	    else{
	    xz[js1][js2]=a[k];
	    js2++;
	    dfs(++k,gs,++now);
	    js2--;
	}
}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(1,i,1);
	}
	cout<<sum;
return 0;
}
