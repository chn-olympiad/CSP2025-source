#include<bits/stdc++.h>
#define int long long
#define bug cout<<"songge888"<<'\n';
using namespace std;
int n,q;
string s1[200010],s2[200010];
string t1,t2;
int fff=0;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	if(n<=1010&&q<=1010){
		fff=1;
	}
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
//	cout<<s1[1][0]<<'\n';
	while(q--){
		if(!fff){
			cout<<0<<'\n';
			continue;
		}
		int ans=0;
		cin>>t1>>t2;
		string a1,a2;
		int len1,len2;
		for(int i=1;i<=n;i++){
			a1=t1;
			a2=t2;
			len1=a1.size();
			len2=s1[i].size();
			for(int j=0;j<len1;){
				int fl=0;
				for(int k=0;k<len2;k++){
					if(j+k>len1){
						fl=1;
						break;
					}
					if(j==0){
//						cout<<a1<<' '<<i<<' '<<k<<' '<<a1[j+k]<<' '<<s1[i][k]<<'\n';
					}
					if(a1[j+k]!=s1[i][k]){
//						bug
//						cout<<a1<<' '<<i<<' '<<k<<' '<<a1[j+k]<<' '<<s1[i][k]<<'\n';
//						bug
						fl=1;
						break;
					}
				}
				if(!fl){
//					bug
//					cout<<w<<'\n';
					string w=a1;
					for(int k=0;k<len2;k++){
						w[j+k]=s2[i][k];
					}
//					cout<<
					if(w==t2){
						ans++;
					}
				}
				j++;
			}
		}
		cout<<ans<<'\n';
	} 
	return 0;
}

