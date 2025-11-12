#include<bits/stdc++.h>
using namespace std;
int n,q;
string t1[200001],t2[200001],a[200001],s1[200001],s2[200001];

int main(){
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		if(t1[i].size()!=t2[i].size())cout<<0<<endl;
		else
		{
		int l=0,r=t1[i].size()-1;
		while(t1[i][l]==t2[i][l])l++;
		while(t1[i][r]==t2[i][r])r--;
		int mi=r-l+1;
		
		//cout<<mi<<" ";
		int t=t1[i].size(),ans=0;
		for(int j=1;j<=n;j++){
			int s=s1[j].size();
			if(s>=mi)
			for(int k=0;k<=min(l,t-s);k++){
				int p=0,o=k;
				while(s1[j][p]==t1[i][o]&&s2[j][p]==t2[i][o]&&p<s&&o<t){
					p++;o++;
				}
				if(o>r)ans++;
			}
		}
		cout<<ans<<endl;
		}
		
	}
} 
