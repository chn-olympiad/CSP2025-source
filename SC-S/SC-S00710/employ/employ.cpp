#include<bits/stdc++.h>
using namespace std;
struct node{
	string a,b;
	int len;
}a[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
		a[i].len=abs(int(a[i].a.find('b')-a[i].b.find('b')));
	}
	if(n>=200010){
		while(q--){
			string s,s2;
			cin>>s>>s2;
			int b1=s.find('b'),b2=s.find('b'),ans=0;
			for(int i=1;i<=n;i++){
				int t1=s.find(a[i].a),t2=s2.find(a[i].b);
				if(t1==-1||t2==-1||(t1!=t2)) continue;
				if(abs(int(b2-b1))!=a[i].len){
					continue;
				}
				if(b1!=int(t1+a[i].a.find('b'))||b2!=int(t2+a[i].b.find('b'))){
					continue;
				}
				ans++;
			}
			cout<<ans<<"\n";
		}
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int m=s1.size();
		int ans=0;
		for(int i=1;i<=n;i++){
			int f=s1.find(a[i].a),f1=s2.find(a[i].b);
			if(f!=f1||((f==-1)||(f1==-1))) continue;
			string q1="",q2="";
			for(int j=0;j<f;j++){
				q1+=s1[j];
				q2+=s2[j];
			}
			if(q1!=q2) continue;
			q1=q2="";
			for(int j=f+a[i].a.size();j<m;j++){
				q1+=s1[j];
				q2+=s2[j];
			}
			if(q1!=q2) continue;
			ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}