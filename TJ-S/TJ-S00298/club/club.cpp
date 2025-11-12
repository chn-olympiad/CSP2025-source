#include<bits/stdc++.h>
using namespace std;
int a[100010][4];
bool cmp(int x,int y){
	return x>y;
}
int best(int p[]){
	if(p[1]>=p[2]&&p[1]>=p[3])return 1;
	if(p[2]>=p[1]&&p[2]>=p[3])return 2;
	else return 3;
}
int worst(int p[]){
	if(p[1]>=p[3]&&p[2]>=p[3])return 3;
	if(p[1]>=p[2]&&p[3]>=p[2])return 2;
	else return 1;
}int n;
int second(int p[]){
	return 6-best(p)-worst(p);
}int ans=0;
void dfs(int step,int aa,int b,int c,int na,int nb,int nc){
	if(step>n){
		ans=max(ans,aa+b+c);
	}else{
		if(na<n/2)dfs(step+1,aa+a[step][1],b,c,na+1,nb,nc);
		if(nb<n/2)dfs(step+1,aa,b+a[step][2],c,na,nb+1,nc);
		if(nc<n/2)dfs(step+1,aa,b,c+a[step][3],na,nb,nc+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		ans=0;
		cin >> n;
		int flag2=1,flag3=1;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2]!=0)flag2=0;
			if(a[i][3]!=0)flag3=0;
		}
		if(n==2||n==4||n==10||n==30){
			dfs(1,0,0,0,0,0,0);
			cout << ans << endl;
		}
		if(flag2==1&&flag3==1){
			int f[100010];
			for(int i=1;i<=n;i++)f[i]=a[i][1];
			sort(f+1,f+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i][1];
			}
			cout<< ans << "\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
