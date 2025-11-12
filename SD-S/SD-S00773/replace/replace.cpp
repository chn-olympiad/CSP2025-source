#include<bits/stdc++.h>
using namespace std;
int n,q,len,len1,l,r,a[200005],b[200005],c[200005],ans,flag;
string s1[200005],s2[200005],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		len=s1[i].size();
		c[i]=len;
		for(int j=0;j<len;j++){
			if(s1[i][j]!=s2[i][j]){
				a[i]=j;
				break;
			}
		}
		for(int j=len-1;j>0;j--){
			if(s1[i][j]!=s2[i][j]){
				b[i]=j;
				break;
			}
		}
	}
	while(q--){
		cin>>t1>>t2;
		len=t1.size(),len1=t2.size();
		if(len!=len1){
			cout<<0<<"\n";
			continue;
		}
		for(int i=0;i<len;i++){
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		}
		for(int i=len-1;i>0;i--){
			if(t1[i]!=t2[i]){
				r=i;
				break;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(r-l==b[i]-a[i]&&l>=a[i]&&len-r>=c[i]-b[i]){
				flag=1;
				int q1=t1.find(s1[i]);
				if(q1==-1){
					flag=0;
					continue;
				}
				int q2=t2.find(s2[i]);
				if(q2==-1){
					flag=0;
					continue;
				}
				if(flag==1){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
