#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct p{
	int a;
	int b;
	int c;
}x[100010];
int ans;
void go(int la,int lb,int lc,int sum,int v){
	if(v>n){
		ans=max(ans,sum);
		//cout<<ans<<" ";
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			if(la<n/2){
				go(la+1,lb,lc,sum+x[v].a,v+1);
			}else{
				continue;
			}
		}else if(i==2){
			if(lb<n/2){
				go(la,lb+1,lc,sum+x[v].b,v+1);
			}else{
				continue;
			}
		}else if(i==3){
			if(lc<n/2){
				go(la,lb,lc+1,sum+x[v].c,v+1);
			}else{
				continue;
			}
		}
	}
	
	return;
}
bool cmp(p d,p e){
	return d.a>e.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		int flag=0;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].b!=0||x[i].c!=0){
				flag=1;
			}
		}
		if(flag==0){
			sort(x+1,x+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=x[i].a;
			}
			cout<<ans;
			return 0;
		}
		go(0,0,0,0,1);
		cout<<ans<<endl;
	}
	return 0;
}