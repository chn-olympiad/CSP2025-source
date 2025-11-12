#include<bits/stdc++.h>
using namespace std;
struct ppp{
	int t1,t2,t3;
};
int n,a[100100][4],b[100100],c[100100],t,ans;

int dfs(int x,int an,ppp txt){
	cout<<x;
	if(x>n){
		ans=max(ans,an);
		return 0;
	}
	if(txt.t1<n/2){
		txt.t1+=1;
		dfs(x+1,an+a[x][1],txt);
		txt.t1-=1;
	}
	if(txt.t2<n/2){
		txt.t2+=1;
		dfs(x+1,an+a[x][2],txt);
		txt.t2-=1;
	}
	if(txt.t3<n/2){
		txt.t3+=1;
		dfs(x+1,an+a[x][3],txt);
		txt.t3-=1;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int p=1;p<=t;p++){
		cin>>n;
		ans=0;
		int nm[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=a[i][1];
		}
		ppp ttt;
		ttt.t1=0;
		ttt.t2=0;
		ttt.t3=0;
		if(n>=200){
			sort(b+1,b+1+n);
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
		}
		else dfs(1,0,ttt);
		cout<<ans<<endl;
	}
	
	return 0;
} 
