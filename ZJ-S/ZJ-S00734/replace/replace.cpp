#include<bits/stdc++.h>
using namespace std;
string s1[200010],s2[200010],t1,t2;
int n,q,p,b1[5000010],b2[5000010],c[200010],d[200010];
int maxx(int x,int y){
	if (x>y) return x;else return y;
}
int minx(int x,int y){
	if (x<y) return x;else return y;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;p=1;
	for (int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for (int j=0;j<s1[i].length();j++)
			if (s1[i][j]!='a'&&s1[i][j]!='b'||s2[i][j]!='a'&&s2[i][j]!='b')p=0;
	}
	if (p){
		for (int i=1;i<=n;i++){
			int x,y;
			for (int j=0;j<s1[i].length();j++){
				if (s1[i][j]=='b') x=j;
				if (s2[i][j]=='b') y=j;
			}
			c[i]=x;d[i]=y;
		}
		for (int i=1;i<=q;i++){
			cin>>t1>>t2;
			int x,y,ans=0;
			if (t1.length()!=t2.length()){
				cout<<0<<endl;
				continue;
			}
			
			for (int j=0;j<t1.length();j++){
				if (t1[j]=='b') x=j;
				if (t2[j]=='b') y=j;
			}
			for (int j=1;j<=n;j++){
				if (d[j]-c[j]!=y-x) continue;
				if (minx(d[j],c[j])<=minx(x,y)&&s1[j].length()-maxx(d[j],c[j])<=t1.length()-maxx(x,y))
					ans++;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	while (q--){
		cin>>t1>>t2;
		if (t1.length()!=t2.length()){
			cout<<0<<endl;continue;
		}
		int head,tail,p=1,ans=0;
		for (int i=0;i<t1.length();i++){
			if (t1[i]!=t2[i]){
				if (p){
					head=i;
					p=0;
				}
				tail=i;
			} 
		}
		//cout<<head<<' '<<tail<<endl;
		for (int i=1;i<=n;i++){
			if (s1[i].length()<tail-head+1) continue;
			int fr=tail-s1[i].length()+1;
			if (fr<0) fr=0;
			int to=(head<t1.length()-s1[i].length()?head:t1.length()-s1[i].length());
			for (int j=fr;j<=to;j++){
				bool pp=1;
				for (int k=j;k<=j+s1[i].length()-1;k++)
					if (s1[i][k-j]!=t1[k]||s2[i][k-j]!=t2[k]){
						pp=0;break;
					}
				if (pp){
					ans++;
					//cout<<i<<endl;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}