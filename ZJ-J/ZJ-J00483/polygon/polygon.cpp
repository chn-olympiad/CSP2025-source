#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int p=0,p1[5005]={},p2=0;
int n,a[5005]={};
long long sum=0;
void dfs(int num,int q){
	if(p2==num){
		p=0;
		for(int i=0;i<num;i++){
			p+=a[p1[i]];
		}
		if(p>2*a[p1[num-1]]){
			sum=(sum%998244353+1)%998244353;
		}
	}else{
		for(int i=q+1;i<n;i++){
			p1[p2]=i;
			p2+=1;
			dfs(num,i);
			p2--;
			p1[p2]=-1;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=3;i<=n;i++){
		dfs(i,-1);
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


