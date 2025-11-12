#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mk make_pair
#define fir first
#define sec second
#define put putchar
using namespace std;
int rd(){
	int sum=0,p=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')p=-1;ch=getchar();}
	while(isdigit(ch)){sum=sum*10+(ch-'0');ch=getchar();}
	return sum*p;
}
void wr(int x){
	if(x<0)put('-'),x=-x;
	if(x>9)wr(x/10);
	put(x%10+'0');
}
const int JYAAKIOI=1e18,N=1e5+10;
int n,q,ans,la[N],lb[N];
string a[N],b[N],s,t;
string get(string s,int l,int r){
	string res="";
	for(int i=l;i<=r;++i)res=res+s[i];
	return res;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=rd();q=rd();
	for(int i=1;i<=n;++i)cin>>a[i]>>b[i],la[i]=a[i].size(),lb[i]=b[i].size();
	while(q--){
		ans=0;
		cin>>s>>t;
		int ls=s.size()-1,lt=t.size()-1;
		if(ls!=lt||n>=1000){
			wr(0);
			put('\n');
			continue;
		}
		for(int i=1;i<=n;++i){
			for(int j=0;j+la[i]-1<=ls;++j){
				if(get(s,j,j+la[i]-1)==a[i]){
					//cout<<i<<' '<<j<<endl;
					bool p=1;
					for(int k=0;k<j;++k){
						if(s[k]!=t[k]){
							p=0;
							break;
						}
					}
					if(!p)continue;
					for(int k=j+la[i];k<=ls;++k){
						if(s[k]!=t[k]){
							p=0;
							break;
						}
					}
					if(!p)continue;
					for(int k=j;k<=j+la[i]-1;++k){
						if(b[i][k-j]!=t[k]){
							p=0;
							break;
						}
					}
					if(!p)continue;
					++ans;
				}
			}
		}
		wr(ans),put('\n');
	}
	return 0;
}
