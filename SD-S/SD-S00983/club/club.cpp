#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
int t,n;long long ans,maxx;
struct nodeee{
	int q,w,e;
}a[100005]; 
bool cmp1(nodeee a,nodeee b){
	if(a.q>b.q)return 0;
	else return 1;
}
//bool cmp2(nodeee a,nodeee b){
//	if(a.q<b.q)return 1;
//	else return 0;
//}
//bool cmp3(nodeee a,nodeee b){
//	if(a.w<b.w)return 1;
//	else return 0;
//}
void dfs(int i,int qn,int wn,int en){
	if(i>n){
		maxx=max(maxx,ans);
		return ;
	}
	if(qn+1<=n/2&&a[i].q!=0){
		ans+=a[i].q;
		dfs(i+1,qn+1,wn,en);
		ans-=a[i].q;
	}
	if(wn+1<=n/2&&a[i].w!=0){
		ans+=a[i].w;
		dfs(i+1,qn,wn+1,en);
		ans-=a[i].w;
	}
	if(en+1<=n/2&&a[i].e!=0){
		ans+=a[i].e;
		dfs(i+1,qn,wn,en+1);
		ans-=a[i].e;
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		maxx=0;
		cin>>n;
		int flaga=0,flagb=0,flagc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].q>>a[i].w>>a[i].e;
			if(a[i].w!=a[i].e){
				flaga=1;
			}
		}
		if(flaga==0){
			sort(a+1,a+n+1,cmp1);
			for(int i=n;i>n/2;i--){
				ans+=a[i].q;
			}
			cout<<ans;
			return 0;
		}
		dfs(1,0,0,0);
		cout<<maxx<<endl;
	}
	return 0;
}

