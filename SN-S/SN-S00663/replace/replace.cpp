#include<bits/stdc++.h>
using namespace std;
struct hjh{
	string s1,s2;
}n[200005];
hjh q[200005];
long long db(string bb,long long ans,int n1){
	for(int i=0;i<n1;i++){
		for(int l=0;l<n[i].s1.size();l++){
			bool f=0;
			if(n[i].s1[l]==bb[0]){
				for(int j=0;j<bb.size();j++){
					if(n[i].s1[j+l]!=bb[j]&&f==1){
						f=0;break;
					}
					else if(n[i].s1[j+l]==bb[j])
						f=1;
				}	
			}
			if(f==1)ans++;
			if(f==0)break;
		}	
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	int n1,q1;cin>>n1>>q1;
	for(int i=0;i<n1;i++){
		cin>>n[i].s1>>n[i].s2;
	}
	for(int i=0;i<q1;i++){
		cin>>q[i].s1>>q[i].s2;
	}
	long long ans;
	for(int i=0;i<q1;i++){
		ans=0;
		if(q[i].s1==n[i].s1&&q[i].s2==n[i].s2)ans++;
		if(q[i].s1.size()>n[i].s1.size()){
			cout<<0<<endl;continue;
		}
		int f=0;string bb="";
		for(int j=0;j<q[i].s1.size();j++){
			if(q[i].s1[j]!=q[i].s2[j]&&f==2){
				f=0;
			}
			else if(q[i].s1[j]!=q[i].s2[j]&&f==0){
				f=1;bb+=q[i].s1[j];
			}
			else if(q[i].s1[j]!=q[i].s2[j]&&f==1){
				f=2;
			}
		}
		if(f==2)ans=db(bb,ans,n1);
		cout<<ans<<endl;
	}
	return 0;
}
