#include<bits/stdc++.h>
using namespace std;
const unsigned long long p=131;
unsigned long long n,q,ll[200005],hh[2][5000005],hh2[2][5000005],h1[2][5000005],h2[2][5000005],ans;
string a[200005],b[200005];
char s[5000005],s2[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		ll[i]=a[i].length();
		unsigned long long x=0,y=0,z=1;
		for(int j=1;j<=ll[i];j++){
			x*=p;
			x+=a[i][j-1]-'a'+1;
			y*=p;
			y+=b[i][j-1]-'a'+1;
			z*=p;
		}
		h1[0][i]=x;
		h2[0][i]=h2[1][i]=z;
		h1[1][i]=y;
	}
	for(int pp=1;pp<=q;pp++){
		cin>>s+1>>s2+1;
		ans=0;
		int l=strlen(s+1),st=0,en;
		en=l+1;
		hh2[0][0]=1;
		hh2[1][0]=1;
		hh[0][0]=hh[1][0]=0;
		for(int i=1;i<=l;i++){
			hh2[0][i]=hh2[0][i-1]*p;
			hh2[1][i]=hh2[1][i-1]*p;
			hh[0][i]=hh[0][i-1]*p+s[i]-'a'+1;
			hh[1][i]=hh[1][i-1]*p+s2[i]-'a'+1;
		}
		for(int i=1;i<=l;i++){
			if(s[i]!=s2[i]){
				break;
			}
			st=i;
		}
		for(int i=l;i>=1;i--){
			if(s[i]!=s2[i]){
				break;
			}
			en=i;
		}
		for(int i=1;i<=l&&i<=st+1;i++){
			for(int j=1;j<=n;j++){
				if(i+ll[j]-1<=l&&(hh[0][i+ll[j]-1]-hh[0][i-1]*hh2[0][ll[j]])==h1[0][j]){
					if(i+ll[j]>=en){
						if(h1[1][j]==(hh[1][i+ll[j]-1]-hh[1][i-1]*hh2[1][ll[j]])){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//chzx_lfw AKIOI!!!!!
