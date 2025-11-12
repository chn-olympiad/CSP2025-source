#include<bits/stdc++.h>
using namespace std;
int a[500005];
map<int,vector<int> > mp;
struct Node{
	int x,y;
}s[500005];
bool cmp(Node xx,Node yy){
	if(xx.y==yy.y){
		return xx.x>yy.x;
	}
	return xx.y<yy.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			s[++cnt].x=i;
			s[cnt].y=i;
		}
		if(i>1) a[i]=(a[i]^a[i-1]);
		mp[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			s[++cnt].x=1;
			s[cnt].y=i;
		}
		if(mp[(k^a[i])].empty()) continue;
		else{
			int maxn=0,f=0;
			for(auto it:mp[(k^a[i])]){
				if(it<i){
					maxn=max(maxn,it);
					f=1;
				}
				else{
					break;
				}
			}
			if(f==1){
				s[++cnt].x=maxn+1;
				s[cnt].y=i;
			}
		}
	}
	sort(s+1,s+cnt+1,cmp);
	int x=0,ans=0;
	for(int i=1;i<=cnt;i++){
		if(s[i].x>x){
			ans++;
			x=s[i].y;
		}
	}
	cout<<ans;
	return 0;
}
