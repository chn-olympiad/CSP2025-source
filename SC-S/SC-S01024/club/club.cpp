#include<bits/stdc++.h>
using namespace std;
int T;
int n=0;
int f[50005];
int s[50005];
int t[50005];
vector<int> mem(50005,-1);
struct node{
	int v;
	int x;
	int y;
	int maxx;
	int minn;
};
int dfs(int op,int k,int w,int usa,int usb,int usc,int cnt,int lim){
	if(usa>lim||usb>lim||usc>lim){
		return 0;
	}
	if(op==0){
		w+=f[k];
	}else if(op==1){
		w+=s[k];
	}else if(op==2){
		w+=t[k];
	}
	if(cnt==n){
		return w;
	}
	return max({dfs(0,k+1,w,usa+1,usb,usc,cnt+1,lim),dfs(1,k+1,w,usa,usb+1,usc,cnt+1,lim),dfs(2,k+1,w,usa,usb,usc+1,cnt+1,lim)});
}
bool cmp(int x,int y){
	return x>y;
}
bool cmp1(node x,node y){
	return x.v>y.v;
}
bool A=1;
bool B=1;
bool TO=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		TO=1;
		A=1;
		B=1;
		cin>>n;
		if(n!=2){
			TO=0;
		}
		int lim=n/2;
		for(int i=0;i<n;i++){
			cin>>f[i]>>s[i]>>t[i];
			if(s[i]!=0){
				A=0;
			}
			if(t[i]!=0){
				B=0;
				A=0;
			}
		}
		if(TO){
			int a1=f[0]+s[1];
			int a2=f[0]+s[2];
			int a3=f[1]+s[0];
			int a4=f[1]+s[2];
			int a5=f[2]+s[1];
			int a6=f[2]+s[0];
			cout<<max({a1,a2,a3,a4,a5,a6})<<endl;
		}else{
			if(A){
				sort(f,f+n,cmp);
				int ans=0;
				for(int i=0;i<n/2;i++){
					ans+=f[i];
				}
				cout<<ans;
			}else if(B){
				node all[50005];
				for(int i=0;i<n;i++){
					all[i].x=f[i];
					all[i].y=s[i];
					all[i].v=f[i]+s[i];
					all[i].maxx=max(f[i],s[i]);
					all[i].minn=min(f[i],s[i]);
				}
				sort(all,all+n,cmp1);
				int sum=0;
				int cnt=0;
				int lim=n/2;
				for(int i=0;i<n;i++){
					if(cnt<lim){
						sum+=all[i].maxx;
						cnt++;
					}else{
						sum+=all[i].minn;
						cnt++;
					}
				}
				cout<<sum<<endl;
			}else{
				int ans=0;
				ans=max(ans,dfs(0,0,0,1,0,0,0,lim));
				ans=max(ans,dfs(1,0,0,0,1,0,0,lim));
				ans=max(ans,dfs(2,0,0,0,0,1,0,lim));
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}

//This is my last time to have progamming contest...
//After the worst complishment, I will AFO...

//Whatever we thought... Wherever we were...
//We were all kids at young times...
//Whoever we were... Nothing matters...
//Now we just need to have a little little rest...
//To be a kid again... Just play outside...
//With enjoyment in the eyes...
//Who want to grow up? Maybe only childhood...
//We almost be an adult, which isn't a real one...