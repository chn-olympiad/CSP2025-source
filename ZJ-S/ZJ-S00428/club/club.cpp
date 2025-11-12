#include<bits/stdc++.h>
using namespace std;
int t,n,a[5][100005],num[200000],ans;
void solve(int dep,int x,int y,int z){
	if(dep>n){
		if(max(x,max(y,z))>n/2)return;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=a[num[i]][i];
		}
		ans=max(ans,cnt);
		return;
	}
		num[dep]=1;
		solve(dep+1,x+1,y,z);
		num[dep]=2;
		solve(dep+1,x,y+1,z);
		num[dep]=3;
		solve(dep+1,x,y,z+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//=============================
	cin>>t;
	while(t--){
		bool f1=1,f2=1;
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[2][i]!=0)f1=0;
			if(a[3][i]!=0)f2=0;
		}
		if(f1&&f2){
			for(int i=1;i<=n;i++)num[i]=a[1][i];
			sort(num+1,num+n+1);
			for(int i=n;i>=n/2;i--)ans+=num[i];
			cout<<ans<<endl;
			continue;
		}else if(f2){
			
		}
		solve(1,0,0,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
