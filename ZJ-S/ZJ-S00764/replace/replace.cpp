#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][3];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		int len=t1.size(),l=-1,r=-1;
		for(int i=0;i<len;i++){
			if(t1[i]!=t2[i]){
				if(l==-1)l=i;
				r=i;
			}
		}
		long long ret=0;
		for(int i=1;i<=n;i++){
			if(s[i][1].size()<r-l+1)continue;
			for(int y=0;y<len;y++){
				if(y+s[i][1].size()-1>=len||y>l)break;
				if(y+s[i][1].size()-1<r)continue;
				bool flag1=0,flag2=0;
				int cnt=0;
				for(int ll=y;cnt<s[i][1].size();ll++){
					if(t1[ll]!=s[i][1][cnt]){
						flag1=1;break;
					}
					if(t2[ll]!=s[i][2][cnt]){
						flag2=1;break;
					}
					cnt++;
				}
				if(flag1||flag2){}
				else if(cnt==s[i][1].size())ret++;
			}
		}
		printf("%lld\n",ret);
	}
	return 0;
}
