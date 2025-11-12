#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum=0;
void solve(int m,int i,int sm,int cnt,int f){
	if(cnt>=3){
		if(sm>2*m&&f==1){
			sum++;
//			cout<<sm<<endl;
		}
	}
	if(i<=1){
		return;
	}
	else{
		solve(m,i-1,sm+a[i-1],cnt+1,1);
		solve(m,i-1,sm,cnt+1,0);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=3;i--){
		solve(a[i],i,a[i],1,1);
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//wo ai ni bao li
