#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=200000+10; 

int T;
long long n;
int h[N][10]; 
bool A=true,B=true; 
long long ans=-1;
int a[N];

void dfs(int x,int cnt,int a,int b,int c){
	if(x==n){
		for(int i=1;i<=3;i++){
			if((a<(n/2)&&i==1)||(b<(n/2)&&i==2)||(c<(n/2)&&i==3)){
				if((cnt+h[x][i])>ans)ans=cnt+h[x][i];
			}
		}
		return;
	}
	for(int i=1;i<=3;i++){
		if(a<(n/2)&&i==1)dfs(x+1,cnt+h[x][i],(a+1),b,c);
		if(b<(n/2)&&i==2)dfs(x+1,cnt+h[x][i],a,(b+1),c);
		if(c<(n/2)&&i==3)dfs(x+1,cnt+h[x][i],a,b,(c+1));
	}
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>h[i][1]>>h[i][2]>>h[i][3];
			a[i]=h[i][1];
			if(h[i][2]!=0&&A)A=false;
			if(h[i][3]!=0&&B)B=false;
		}
		
		if(A){
			ans=0;
			sort(a+1,a+1+n);
			for(int i=n;i>(n/2);i--){
				ans=ans+a[i];
			}
			cout<<ans;
			
			return 0;
		}
		
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		
		
	}
	
	
	return 0;
}
