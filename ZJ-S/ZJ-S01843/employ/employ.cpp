#include<bits/stdc++.h>
using namespace std;
string s;
int n,m;
long long ans=0;
int a[510],b[510],c[510];
void dfs(int place,int people,int g,int shup){
	if((a[shup]<=g||b[place]==0)&&place>=1) g++;
	else if(b[place]==1&&place>=1) people++;
//	cout<<place<<" "<<people<<" "<<g<<" "<<a[place]<<endl;
	if(place==n&&people>=m){
		ans++;
		ans=ans%998244353;
		return;
	}
	if(place==n&&people<m) return;
	for(int i=1;i<=n;i++){
		if(c[i]==true) continue;
		if(c[i]==false){
		//	cout<<c[i]<<" "<<place<<endl;
			c[i]=true;
		//	cout<<c[i]<<" "<<i<<endl;
		//	cout<<place<<" "<<people<<" "<<g<<endl;
			dfs(place+1,people,g,i);
			c[i]=false;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b[i+1]=s[i]-'0';
	}
	dfs(0,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
