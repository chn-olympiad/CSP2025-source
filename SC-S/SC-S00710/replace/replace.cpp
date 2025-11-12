#include<bits/stdc++.h>
using namespace std;
struct node{
	string a,b;
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