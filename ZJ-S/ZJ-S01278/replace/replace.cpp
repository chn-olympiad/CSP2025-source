#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,q;
string a[N],b[N];
int res[N];
int mp[N];
int cnt=0;
string t1,t2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i],mp[i]=a[i].find('b');
		if(mp[i]>5e6||mp[i]<0) flag=0;
	}
//	sort(mp+1,mp+n+1);
//	for(int i=0;i<5e6;i++){
//		if(i<=mp[cnt]) res[i]=cnt;
//		else{
//			cnt++;
//			res[i]=cnt;
//		}
//	}
	while(q--){
		cin>>t1>>t2;int sum=0;
//		string p="";
//		for(int i=0;i<t1.size();i++){
//			if(t1!=t2)
//		}
		if(!flag){
			for(int i=1;i<=n;i++){
				int u=t1.find(a[i]),v=t2.find(b[i]);
				if(u<=5e6&&u>-1&&v<=5e6&&v>-1){
					string p="";
					for(int j=0;j<t1.size();j++){
						if(j<u||j>u+a[i].size()-1) p+=t1[j];
						else p+=b[i],j=u+a[i].size()-1;
					}
					if(p==t2) sum++;
				}
//				cout<<sum<<' '<<i<<endl;
			}
			cout<<sum<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				int u=t1.find(a[i]),v=t2.find('b');
				if(u>5e6||u<=-1) continue;
				int x=max(t1.find('b'),b[i].find('b'));
				int y=max(t1.size()-t1.find('b'),b[i].size()-b[i].find('b'));
				if(x==v&&y==t2.size()-v) sum++;
			}
			cout<<sum<<endl;
		}
	}
	return 0; 
} 
