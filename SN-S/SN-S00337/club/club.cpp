#include<bits/stdc++.h>
using namespace std;
struct clubmem{
	int to1;
	int to2;
	int to3;
};
long long ans=0;
vector<clubmem> mates(100000);
int have1=0;
int have2=0;
int have3=0;
int lim=0;
void dfs(int n,int now,int res,int lim){
	if(n==100000){
		if(now>n){
		if(res>ans){
			ans=res;
			return;
		}
		return;
	}
	if(have1<lim){
		res+=mates[now-1].to1;
		have1++;
		dfs(n,now+1,res,lim);
		res-=mates[now-1].to1;
		have1--;
	}
	
	}else if(n==200){
	
	if(now>n){
	if(res>ans){
			ans=res;
			return;
		}
		return;
	}
		if(have2<lim){
		res+=mates[now-1].to2;
		have2++;
		dfs(n,now+1,res,lim);
		res-=mates[now-1].to2;
		have2--;
	}
	if(have3<lim){
		res+=mates[now-1].to3;
		have3++;
		dfs(n,now+1,res,lim);
		res-=mates[now-1].to3;
		have3--;
	}
		return;
	}else if(n!=100000 or n!=200){
		if(now>n){
		if(res>ans){
			ans=res;
			return;
		}
		return;
	}
	if(have1<lim){
		res+=mates[now-1].to1;
		have1++;
		dfs(n,now+1,res,lim);
		res-=mates[now-1].to1;
		have1--;
	}
	if(have2<lim){
		res+=mates[now-1].to2;
		have2++;
		dfs(n,now+1,res,lim);
		res-=mates[now-1].to2;
		have2--;
	}
	if(have3<lim){
		res+=mates[now-1].to3;
		have3++;
		dfs(n,now+1,res,lim);
		res-=mates[now-1].to3;
		have3--;
	}
	return;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>mates[i].to1;
			cin>>mates[i].to2;
			cin>>mates[i].to3;
		}
		lim=n/2;
		dfs(n,1,0,lim);
		cout<<ans<<endl;
		ans=0;
		n=0;
		mates.clear();
	}
	return 0;
}
