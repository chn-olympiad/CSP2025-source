#include<bits/stdc++.h>
#include<CSTDIO>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;

//动态规划 忘记 
int n,a[5001],cnt_;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n){
		rep(j,3,n){
			if(i+j-1>n) continue;
			bool flag=0;
			rep(k,i,i+j-1){
				int cnt=0;
				rep(l,i,i+j-1) if(l!=k) cnt+=a[l];
				if(cnt<=a[k]){
					flag=1;
					break;
				} 
			}
			if(!flag) cnt_++;
		}
	}
	cout<<cnt_;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
