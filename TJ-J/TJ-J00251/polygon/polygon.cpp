#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0,a[5050],sum=0;
void js(int nu,int f,int r){
	for(int i=r+1;i<=n-nu+f;i++){
		sum+=a[i];
		if(f==nu){
			if(sum>2*a[i]){
				cnt++;
				cnt%=998224353;
			}
		}else{
			js(nu,f+1,i);
		}
		sum-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		sum=0;
		js(i,1,0);
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
