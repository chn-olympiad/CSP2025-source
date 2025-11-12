#include<bits/stdc++.h>
using namespace std;
const int MAXN=500050;
int n,k;
int a[MAXN];
int b[MAXN];
bool vis[MAXN];
int cnt;
struct node{
	int l,r;
};
vector<node> st;
bool cmp(node a,node b){
	return a.l<b.l;
}
int ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			int d=b[j]^b[i-1];
			if(d==k){
				st.push_back({i,j});
				cnt++;
			}
		}
			
	sort(st.begin(),st.end(),cmp);
	for(int i=0;i<cnt;i++){
		if(!vis[st[i].l]){
			ans++;
			for(int j=st[i].l;j<=st[i].r;j++)
				vis[j]=true;
		}
		else if(vis[st[i].r]){
			int j=st[i].r+1;
			while(vis[j]){
				vis[j]=false;
				j++;
			}
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}