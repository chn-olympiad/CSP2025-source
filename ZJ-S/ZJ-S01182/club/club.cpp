#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;
int n,ans,sum,a[MAXN],b[MAXN],c[MAXN],lim;

void dfs(int x,int cnt1,int cnt2,int cnt3){
	//cout<<1<<endl;
	if(x>n){
		ans=max(ans,sum);
		//cout<<sum<<endl;
		return;
	}
	if(cnt1<lim){
		sum+=a[x];
		dfs(x+1,cnt1+1,cnt2,cnt3);
		sum-=a[x];
	}
	if(cnt2<lim){
		sum+=b[x];
		dfs(x+1,cnt1,cnt2+1,cnt3);
		sum-=b[x];
	}
	if(cnt3<lim){
		sum+=c[x];
		dfs(x+1,cnt1,cnt2,cnt3+1);
		sum-=c[x];
	}
}

void clear(){
	sum=0;ans=0;
	for(int i=1;i<=n;i++)a[i]=b[i]=c[i]=0;
}

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		lim=n/2;
		int flag=1,ff=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0)flag=0;
			if(c[i]!=0)ff=0;
		}
		if(flag==1){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=lim;i++){
				ans+=a[i];
			}
			cout<<ans<<endl;
			continue;
		}
	
		dfs(1,0,0,0);
		cout<<ans<<endl;
		clear();
	}
	return 0;
}
