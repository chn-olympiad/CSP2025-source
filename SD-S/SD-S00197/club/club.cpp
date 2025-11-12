#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n;
int a[N][4],b[N][4],a1[N];
int T,ans=0;
bool cmd(int x,int y){
	return x>y;
}
void dfs(int l,int ans1,int d[]){
//	cout<<d[1]<<" "<<d[2]<<" "<<d[3]<<endl;
	if(l>n){
		ans=max(ans,ans1);
		return;
	}
	if(d[b[l][1]%10]<n/2){
		d[b[l][1]%10]++;
		dfs(l+1,ans1+b[l][1]/10,d);
		d[b[l][1]%10]--;
	}
	if(d[b[l][2]%10]<n/2){
		d[b[l][2]%10]++;
		dfs(l+1,ans1+b[l][2]/10,d);
		d[b[l][2]%10]--;
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n;
		int l=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a1[i]=a[i][1];
			if(a[i][2]!=0||a[i][3]!=0) l=1;
		}
		if(l==0){
			sort(a1+1,a1+n+1,cmd);
			for(int i=1;i<=n/2;i++){
				ans+=a1[i];
			}
			cout<<ans<<endl;
			continue;
		}
		int d[4]={0};
		for(int i=1;i<=n;i++){
			int m1=INT_MIN,m2=INT_MIN,l1=1,l2=1;
			for(int j=1;j<=3;j++){
				if(m1<a[i][j]){
					m2=m1;
					l2=l1;
					m1=a[i][j];
					l1=j;
				}
				else if(m2<a[i][j]){
					m2=a[i][j];
					l2=j;
				}
			}
			b[i][1]=m1*10+l1;
			b[i][2]=m2*10+l2;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(b[i][1]>b[j][1]){
					swap(b[i][1],b[j][1]);
					swap(b[i][2],b[j][2]);
				}
			}
		} 
		dfs(1,0,d);
		cout<<ans<<endl;
	}
	return 0;
}

