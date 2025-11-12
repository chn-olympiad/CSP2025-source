#include<bits/stdc++.h>
using namespace std;
int flag[100005],z;
int tmp(int x,int y){
	return x>y;
}
struct{
	int a,b;
}s[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans,flag1,flag2;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i = 1;i<=n;i++){	
				cin>>s[i].a>>s[i].b>>z;	
		}
		flag1=0;flag2=0;
		for(int i = 1;i<=n;i++){
			if(s[i].a>s[i].b){
				ans+=s[i].a;
				if(flag1<=n/2){
					flag1++;
				}else if(flag2<=n/2){
					flag2++;	
				}
			}else {
				ans+=s[i].b;
				if(flag1<=n/2){
					flag1++;
				}else if(flag2<=n/2){
					flag2++;
				}
			}	
		}
		cout<<ans;
	}
	
	return 0;
} 
