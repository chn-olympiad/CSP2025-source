#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;//Ô¤¹À (25pts) 
int T,n,a[N][5],maxn=INT_MIN,b[N];
bool f[N][5];
struct Node{
	int x,y;
}t[N];
bool cmp(Node a,Node b){
	if(a.x!=b.x) return a.x>b.x;
	else return a.y<b.y; 
}
bool cmp2(int x,int y){
	return x>y;
}
void dfs(int sum,int idx,int x,int y,int z){
	if(x>n/2||y>n/2||z>n/2||x+y+z>n) return;
	if(idx==n+1){
		maxn=max(maxn,sum);
		return;
	}
	if(!f[idx][1]){
		f[idx][1]=1;
		dfs(sum+a[idx][1],idx+1,x+1,y,z);
		f[idx][1]=0;
	}
	if(!f[idx][2]){
		f[idx][2]=1;
		dfs(sum+a[idx][2],idx+1,x,y+1,z);
		f[idx][2]=0;
	}
	if(!f[idx][3]){
		f[idx][3]=1;
		dfs(sum+a[idx][3],idx+1,x,y,z+1);
		f[idx][3]=0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n<=10){
			maxn=INT_MIN;
			memset(f,0,sizeof(f));
			dfs(0,1,0,0,0);
			cout<<maxn<<"\n";
		}
		else{
			bool f1=1,f2=1;
			for(int i=1;i<=n;i++){
				if(a[i][2]!=0||a[i][3]!=0){
					f1=0;
					break;
				}
			}
			if(f1){
				for(int i=1;i<=n;i++){
					b[i]=a[i][1];
				}
				sort(b+1,b+1+n,cmp2);
				long long ans=0;
				for(int i=1;i<=n/2;i++){
					ans+=b[i];
				}
				cout<<ans;
			}
			else{
				for(int i=1;i<=n;i++){
					if(f[i][3]!=0){f2=0;break;}
				}
				if(f2){
					long long e=0,f=0,p=0,ans=0;
					for(int i=1;i<=n;i++){
						t[i]={a[i][1],a[i][2]};
					}
					sort(t+1,t+1+n,cmp);
					for(int i=1;i<=n;i++){
						if(e>n/2||f>n/2){
							p=i;
							break;
						}
						if(t[i].x>t[i].y){
							ans+=t[i].x;
							e++;
						}
						if(t[i].x<t[i].y){
							ans+=t[i].y;
							f++;
						} 
					}
					if(e>n/2){
						for(int i=p;i<=n;i++){
							ans+=t[i].y;
						}
					}
					else if(f>n/2){
						for(int i=p;i<=n;i++){
							ans+=t[i].x;
						}
					}
					cout<<ans;
				}
			}
		}
	}
	return 0;
} 
