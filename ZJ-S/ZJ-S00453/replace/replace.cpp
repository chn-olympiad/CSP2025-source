#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int n,q;
long long ans;
string s1[maxn],s2[maxn],t1,t2;
struct node{
	char x,y;
	int p,q;
	int dep;
}cnt[maxn];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	if(n<=1000){
		for(register int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
		}
		while(q--){
			ans=0;
			cin>>t1>>t2;
			int len=t1.size(),mn,mx;
			for(register int i=0;i<len;i++){
				if(t1[i]!=t2[i]){
					mn=i;
					break;
				}
			}
			for(register int i=len-1;i>=0;i--){
				if(t1[i]!=t2[i]){
					mx=i;
					break;
				}
			}
			int d=mx-mn+1;
			for(register int i=1;i<=n;i++){
				int l=s1[i].size();
				if(l<d||l>len) continue;
				for(register int st=mx-l+1;st<=mn;st++){
					bool flag=0;
					for(register int k=0;k<st;k++){
						if(t1[k]!=t2[k]){
							flag=1;
							break;
						}
					}
					if(flag) continue;
					for(register int k=st+l;k<len;k++){
						if(t1[k]!=t2[k]){
							flag=1;
							break;
						}
					}
					if(flag) continue;
					for(register int k=st;k<st+l;k++){
						if(t1[k]!=s1[i][k-st]){
							flag=1;
							break;
						}
						if(t2[k]!=s2[i][k-st]){
							flag=1;
							break;
						}
					}
					if(!flag) ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}else{
		for(register int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
			char c1=s1[i][0],c2=' ';
			int p,q;
			if(s1[i][0]!=s1[i][1]&&s1[i][0]!=s1[i][2]) c1=s1[i][1],c2=s1[i][0],p=0;
			else{
				c1=s1[i][0];
				for(register int l=1;l<s1[i].size();l++){
					if(s1[i][l]!=c1){
						c2=s1[i][l];
						p=l;
						break;
					}
				}
			} 
			for(register int l=0;l<s2[i].size();l++){
				if(s2[i][l]==c2){
					q=l;
					break;
				}
			}
			int dd=q-p;
			//cout<<p<<" "<<q<<" "<<dd<<endl;
			cnt[i].x=c1,cnt[i].y=c2,cnt[i].dep=dd;
			cnt[i].p=p,cnt[i].q=q;
		}
		while(q--){
			ans=0;
			cin>>t1>>t2;
			int p,q;
			char c1=t1[0],c2=' ';
			if(t1[0]!=t1[1]&&t1[0]!=t1[2]) c1=t1[1],c2=t1[0],p=0;
			else{
				c1=t1[0];
				for(register int l=1;l<t1.size();l++){
					if(t1[l]!=c1){
						c2=t1[l];
						p=l;
						break;
					}
				}
			} 
			for(register int l=0;l<t2.size();l++){
				if(t2[l]==c2){
					q=l;
					break;
				}
			}
			int dd=q-p;
			//cout<<p<<" "<<q<<" "<<dd<<endl;
			int len=t1.size();
			for(register int i=1;i<=n;i++){
				if(cnt[i].x==c1&&cnt[i].y==c2&&cnt[i].dep==dd){
					int pp=cnt[i].p,qq=s1[i].size()-1-pp+1;
					if(p>pp&&p+qq-1<len) ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
