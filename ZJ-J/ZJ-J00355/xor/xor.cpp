#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,s;
}p[5000010];
int n,a[500010],s[500010],k,tot,t,ans,ma,x,y,z,l;
bool cmp(node a,node b){
	return a.s<b.s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		s[i]=a[i]^s[i-1];
	}
	if(ma==1){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				x++;
				z+=l/2;
				l=0;
			}else{
				l++;
				y++;
			}
			
		}
		if(k==1) cout<<y;
		else cout<<z+x;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[i-1]^s[j])==k){
				p[tot].x=i;
				p[tot++].s=j;
			}
		}
	}
	sort(p,p+tot,cmp);
	for(int i=0;i<tot;i++){
		if(p[i].x>t){
			ans++;
			t=p[i].s;
		}
	}
	cout<<ans;
	return 0;
}
