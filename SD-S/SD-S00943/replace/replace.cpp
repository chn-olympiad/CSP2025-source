#include<bits/stdc++.h>
//priority_queue
//unsigned
//cout.flush()
//sync_with_stdio
//long long,file,momrey
using namespace std;
//replace
string s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	cin.tie(0)->sync_with_stdio(0);

	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1==t2){
			cout<<1<<"\n";
			continue;
		}
		if(t2.size()!=t1.size()){
			cout<<0<<"\n";
			continue;
		}
		int l1=-1,r=-1;
		int f=0;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				if(r!=-1){
					cout<<0<<"\n";
					f=1;
					break;
				}
				if(l1==-1){
					l1=i;
				}
			}else if(l1!=-1){
				r=i;
			}
		}
		if(r==-1){
			r=t1.size();
		}
//		cout<<l1<<" "<<r<<"\n";
		if(f){
			continue;
		}
		for(int i=1;i<=n;i++){
			int j=0,l=0;
			for(int k=0;j<s1[i].size()&&k<t1.size();){
				if(s1[i][j]!=t1[k]||s2[i][j]!=t2[k]){
					k=l+1;
					l++;
					j=0;
				}
				j++;
				k++;
				if(j==s1[i].size()){
					k=l+1;
					l++;
					j=0;
					if(l<=l1&&k<=r){
//						cout<<l<<" "<<k<<" "<<i<<"\n";
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}

