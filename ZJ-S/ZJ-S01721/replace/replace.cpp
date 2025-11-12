#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,T,i,l1,l2,len1[200010],ll[10000010],w1,w2,wei1[200010],wei2[200010],len2[200010],flag,ans,j,k,w;
bool pd[10000010];
string a[200010],b[200010];
char str1[5000010],str2[5000010];
vector<int> ss1[10000010],ss2[10000010];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>T;
	for(i=1;i<=n;i++)cin>>a[i]>>b[i],len1[i]=a[i].size(),len2[i]=b[i].size(),a[i]=" "+a[i],b[i]=" "+b[i];
	if(n<=1000&&T<=1000&&T!=1){
		while(T--){
			cin>>str1+1>>str2+1;w=0;
			l1=strlen(str1+1);l2=strlen(str2+1);
			for(i=l2;i>=max(1ll,l2-l1+1);i--)
				if(str2[i]!=str1[l1-(i-l2+1)+1]){
					w=i;
					break;
				}
			ans=0;
			for(i=1;i<=n;i++){
				if(l2-l1!=len2[i]-len1[i])continue;
				for(j=1;j<=l1-len1[i]+1;j++){
					if(str1[j]==a[i][1]){
						flag=1;
						for(k=j;k<=j+len1[i]-1;k++)
							if(str1[k]!=a[i][k-j+1]){
								flag=0;
								break;
							}
						if(flag){
							flag=1;
							for(k=j;k<=j+len2[i]-1;k++)
								if(b[i][k-j+1]!=str2[k]){
									flag=0;
									break;
								}
							if(flag){
								if(j+len2[i]>w)ans++;
							}
						}
					}
					if(str1[j]!=str2[j])break;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=len1[i];j++){
			if(a[i][j]=='b')wei1[i]=j;
			if(b[i][j]=='b')wei2[i]=j;
		}
		ss1[wei1[i]-wei2[i]+5000000].push_back(wei1[i]);
		ss2[wei1[i]-wei2[i]+5000000].push_back(len1[i]-wei1[i]);
	}
	while(T--){
		cin>>str1+1>>str2+1;ans=0;
		l1=strlen(str1+1);l2=strlen(str2+1);
		if(l1!=l2){
			cout<<0<<'\n';
			continue;
		}
		for(i=1;i<=l1;i++){
			if(str1[i]=='b')w1=i;
			if(str2[i]=='b')w2=i;
		}
		if(!pd[w1-w2+5000000]){
			pd[w1-w2+5000000]=1;
			ll[w1-w2+5000000]=ss1[w1-w2+5000000].size();
		}
		for(i=0;i<ll[w1-w2+5000000];i++)
			if(w1>=ss1[w1-w2+5000000][i]&&l1-w1>=ss2[w1-w2+5000000][i])
				ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
