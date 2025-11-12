#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int q;
struct node{
	string fr;
	string to;
	int dis;
}a[1000005];
map<int,vector<pair<int,int> > >mp;
map<pair<string,string>,int>cnt;

int tag;
int vvb1;
int vvb2;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i].fr;
		cin>>a[i].to;
		int p1;
		int p2;
		int ppp;
		int qqq;
		vvb1=0;
		vvb2=0;
		for (int j=0;j<a[i].fr.size();j++){
			if (a[i].fr[j]!='a' && a[i].to[j]!='a' && a[i].to[j]!='b' && a[i].fr[j]!='b'){
				tag=1;
			}
			if (a[i].fr[j]=='b'){
				p1=j;
				ppp=j;
				vvb1++;
			}
			if (a[i].to[j]=='b'){
				p2=j;
				qqq=j;
				vvb2++;
			}
		}
		cnt[make_pair(a[i].fr,a[i].to)]++;
		mp[p1-p2].push_back(make_pair(min(ppp,qqq),a[i].fr.size()-1-max(ppp,qqq)));
		if (vvb1>1 || vvb2>1){
			tag=1;
		}
	}
	if (!tag){
		while (q--){
			string c1,c2;
			cin>>c1>>c2;
			if (c1.size()!=c2.size()){
				cout<<"0\n";
				continue;
			}
			int p1;
			int p2;
			int ppp;
			int qqq;
			vvb1=0;
			vvb2=0;
			for (int i=0;i<c1.size();i++){
				if (c1[i]=='b'){
					p1=i;
					ppp=i;
					vvb1++;
				}
				
				if (c2[i]=='b'){
					p2=i;
					vvb2++;
					qqq=i;
				}
			}
			if (vvb1>1 || vvb2>1){
				int s=0;
				int t=0;
				int ans=0;
				for (int i=0;i<c1.size();i++){
					if (c1[i]!=c2[i]){
						s=i;
						break;
					}
				}
				
				for (int i=c1.size()-1;i>=0;i--){
					if (c1[i]!=c2[i]){
						t=i;
						break;
					}
				}
				for (int l=0;l<=s;l++){
					for (int r=t;r<=c1.size();r++){
						string c="";
						string p="";
						for (int j=l;j<=r;j++){
							c+=c1[j];
							p+=c2[j];
						}
						ans+=cnt[make_pair(c,p)];
					}		
				}
				
				cout<<ans<<'\n';
			}
			else{
				if (ppp>qqq){
					swap(ppp,qqq);
				}
				qqq=c1.size()-qqq-1;
				int as=0;
				for (int i=0;i<mp[p1-p2].size();i++){
					
					int xx=mp[p1-p2][i].first;
					int yy=mp[p1-p2][i].second;
					if (xx>ppp || yy>qqq) continue;
					as++;
				}
				cout<<as<<'\n';
			}
		}	
		return 0;
	}
	while (q--){
		int ans=0;
		string c1;
		string c2;
		cin>>c1>>c2;
		if (c1.size()!=c2.size()){
			cout<<"0\n";
			continue;
		}
		int s=0;
		int t=0;
		for (int i=0;i<c1.size();i++){
			if (c1[i]!=c2[i]){
				s=i;
				break;
			}
		}
		
		for (int i=c1.size()-1;i>=0;i--){
			if (c1[i]!=c2[i]){
				t=i;
				break;
			}
		}
		for (int l=0;l<=s;l++){
			for (int r=t;r<=c1.size();r++){
				string c="";
				string p="";
				for (int j=l;j<=r;j++){
					c+=c1[j];
					p+=c2[j];
				}
				ans+=cnt[make_pair(c,p)];
			}		
		}
		
		cout<<ans<<'\n';
	}
	
	return 0; 
}
