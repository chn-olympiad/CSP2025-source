#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,q;
map<string,string>mp;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int l1=t1.size(),l2=t2.size();
		if(l1!=l2){
			cout<<0<<'\n';
			continue;
		}
		int l=0,r=l1-1;
		for(;l<l1&&t1[l]==t2[l];l++);
		for(;r>=0&&t1[r]==t2[r];r--);
		string str1="",str2="";
		for(int j=l;j<=r;j++)str1+=t1[j],str2+=t2[j];
		for(int i=l;i>=0;i--){
			for(int j=r;j<l1;j++){
				string str1_1="",str1_2="",str2_1="",str2_2="";
				for(int k=i;k<l;k++)str1_1+=t1[k],str2_1+=t2[k];
				for(int k=r+1;k<=j;k++)str1_2+=t1[k],str2_2+=t2[k];
				if(mp[str1_1+str1+str1_2]==str2_1+str2+str2_2)
					ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
