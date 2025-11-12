#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n,t,rs[4];
long long ans;
bool c[MAXN];//是否分配;
bool panduan1(int m){
	if(rs[m]+1>(n>>1))return 0;
	else return 1;
}
struct P{
	int a;//部门的序号 
	int b;//人的序号 
	int zhi;//值 
}a[MAXN*3+10];
bool cmp(P a,P b){
	return a.zhi>b.zhi;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(c,0,sizeof(c));
		memset(rs,0,sizeof(rs));
		cin>>n;
		for(int i=1;i<=n*3;i=i+3){
			cin>>a[i].zhi>>a[i+1].zhi>>a[i+2].zhi;
			a[i].a=1;
			a[i+1].a=2;
			a[i+2].a=3;
			a[i].b=i/3+1;
			a[i+1].b=(i+1)/3+1;
			a[i+2].b=(i+2)/3+1;
		}
		sort(a+1,a+n*3+1,cmp);
		for(int i=1;i<=n*3;i++){
			if((!c[a[i].b])){
				ans+=a[i].zhi;
				c[a[i].b]=1;
				rs[a[i].a]++;
			}
		}
		
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}//panduan1(a[i].a)&&
