#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s1,s2;
string s[N][2];
bool flag=1;
int lef[N],rig[N];
int id1[N],id2[N],w[N];
//map<int,int> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		int l=s[i][0].size();
		int a=l,b=-1;
		int ans=0;
		for(int j=0;j<l;j++){
			if(s[i][0][j]!=s[i][1][j]){
				a=min(a,j);
				b=max(b,j);
			}
		}
		lef[i]=a,rig[i]=b;
//		gethash(s1);
//		gethash(s2);
//		int l=s1.size();
//		for(int j=0;j<l;j++){
//			if(s1[j]=='b'){
//				if(id1[i]==0){
//					id1[i]=j;
//				}else{
//					flag=0;
//				}
//			}else if(s1[j]!='a'){
//				flag=0;
//			}
//		}
//		for(int j=0;j<l;j++){
//			if(s2[j]=='b'){
//				if(id2[i]==0){
//					id2[i]=j;
//				}else{
//					flag=0;
//				}
//			}else if(s2[j]!='a'){
//				flag=0;
//				//cout<<s2[j];
//			}
//		}
//		w[i]=id1[i]-id2[i];
//		mp[w[i]]++;
	}
	if(1ll*q*n*n<100000000){
		while(q--){
			cin>>s1>>s2;
			int l=s1.size();
			int a=l,b=-1;
			int ans=0;
			for(int i=0;i<l;i++){
				if(s1[i]!=s2[i]){
					a=min(a,i);
					b=max(b,i);
				}
			}
			if(b==-1){
				//cout<<"?";
				for(int i=1;i<=n;i++){
					if(rig[i]==-1)ans++;
				}
				cout<<ans<<"\n";
				continue;
			}
			for(int i=1;i<=n;i++){
				//cout<<"?";
				//cout<<rig[i]<<lef[i]<<" ";
				if(rig[i]-lef[i]==b-a&&lef[i]<=a&&s[i][0].size()-rig[i]<=s2.size()-b){
					//cout<<s[i][0]<<" ";
					bool fl=1;
					for(int j=a,j2=lef[i];j<=b;j++,j2++){
						if(s1[j]!=s[i][0][j2]||s2[j]!=s[i][1][j2]){
							//cout<<s1[j]<<s[i][0]"?";
							fl=0;
						}
					}
					ans+=fl;
				}
			}
			cout<<ans<<"\n";
		}	
		return 0;
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		cout<<0<<"\n";
//		for(int j=0;j<l;j++){
//			if(s1[j]=='b'){
//				id1[i]=j;
//			}
//		}
//		for(int j=0;j<l;j++){
//			if(s2[j]=='b'){
//				id2[i]=j;
//			}
//		}
//		w[i]=id1[i]-id2[i];
//		if(flag){
//			cout<<mp[w[i]]<<"\n";
//		}
	}
	
	return 0;
}
