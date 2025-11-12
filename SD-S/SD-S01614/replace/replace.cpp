#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define int long long
using namespace std;
int n,m,le[200005],a[200005],b[200005],c[200005],d[200005];
string s1[200005],s2[200005],s3[200005],s4[200005];
map<pair<string,string>,int> mp;
map<pair<int,int>,int> mp2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int f1=0;
	cin>>n>>m;
	int F=0;
	for(int i=1; i<=n; i++){
		cin>>s1[i]>>s2[i];
		F+=s1[i].size()+s2[i].size();
		mp[{s1[i],s2[i]}]=1;
	}
	for(int i=1; i<=m; i++){
		cin>>s3[i]>>s4[i];
		le[i]=s3[i].size();
		s3[i]=' '+s3[i];
		s4[i]=' '+s4[i];
	}
	if(F<=2000){
		for(int i=1; i<=m; i++){
			if(s3[i].size()!=s4[i].size()){
				cout<<"0\n";
				continue;
			}
			int l=0,r=le[i]+1,ans=0;
			while(s3[i][l+1]==s4[i][l+1]) l++;
			while(s3[i][r-1]==s4[i][r-1]) r--;
//			cout<<i<<' '<<l<<' '<<r<<"?\n";
			for(int j=l; j>=0; j--){
				string tmp="",tmp2="";
				for(int k=j+1; k<r; k++){
					tmp+=s3[i][k];
					tmp2+=s4[i][k];
				}
				for(int k=r; k<=le[i]+1; k++){
//					cout<<j<<' '<<k<<'|'<<tmp<<'*'<<tmp2<<"!!\n";
					if(mp[{tmp,tmp2}]) ans++;
					if(k!=le[i]+1){
						tmp+=s3[i][k];
						tmp2+=s4[i][k];
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	else{
		for(int i=1; i<=n; i++){
			int p=0;
			while(s1[i][p]=='a'){
				a[i]++;
				p++;
			}
			p=s1[i].size()-1;
			while(s1[i][p]=='a'){
				b[i]++;
				p--;
			}
			p=0;
			while(s2[i][p]=='a'){
				c[i]++;
				p++;
			}
			p=s2[i].size()-1;
			while(s2[i][p]=='a'){
				d[i]++;
				p--;
			}
		}
		for(int i=1; i<=m; i++){
			if(s3[i].size()!=s4[i].size()){
				cout<<"0\n";
				continue;
			}
			int p=1;
			int x=0,y=0,z=0,w=0;
			while(s3[i][p]=='a'){
				x++;
				p++;
			}
			p=le[i];
			while(s3[i][p]=='a'){
				y++;
				p--;
			}
			p=1;
			while(s4[i][p]=='a'){
				z++;
				p++;
			}
			p=le[i];
			while(s4[i][p]=='a'){
				w++;
				p--;
			}
			int ans=0;
			for(int j=1; j<=n; j++){
				if(c[j]-a[j]==z-x&&d[j]-b[j]==w-y&&x>=a[j]&&y>=b[j]) ans++;
			}
			cout<<ans<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

