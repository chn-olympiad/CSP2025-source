#include<bits/stdc++.h>
#define sz size()
#define fs first
#define sc second
#define fst ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n,q,len=0;
struct Shiro{
	string a,b;
}s[200100],s1[200100];
bool f[200100];
int g_l[200100],g_r[200100];
int main(){
	fst;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		len++;
		cin>>s[len].a>>s[len].b;
		if(s[len].a==s[len].b){
			continue;
			len--;
		}
		int l=0,r=0;
		for(int j=0;j<s[len].a.sz;j++){
			if(s[len].a[j]!=s[len].b[j]){
				l=j;
				break;
			}
		}for(int j=s[len].a.sz-1;j>l;j--){
			if(s[len].a[j]!=s[len].b[j]){
				r=j;
				break;
			}
		}if(l==0&&r==s[len].a.sz-1){
			s1[len]=s[len];
			f[len]=0;
		}else{
			f[len]=1;
			g_l[len]=l;
			g_r[len]=r;
			for(int j=l;j<=r;j++){
				s1[len].a+=s[len].a[j];
				s1[len].b+=s[len].b[j];
			}
		}
	}
//	for(int i=1;i<=len;i++){
//		cout<<gai[i]<<" "<<s1[i].a<<" "<<s1[i].b<<endl;
//	}
	while(q--){
		long long ans=0;
		string t1,t2,x,y;
		cin>>t1>>t2;
		if(t1.sz!=t2.sz){
			cout<<0<<endl;
			continue;
		}int l=0,r=0;
		for(int j=0;j<t1.sz;j++){
			if(t1[j]!=t2[j]){
				l=j;
				break;
			}
		}for(int j=t1.sz-1;j>l;j--){
			if(t1[j]!=t2[j]){
				r=j;
				break;
			}
		}if(l==0&&r==t1.sz-1){
			x=t1;
			y=t2;
		}else{
			for(int j=l;j<=r;j++){
				x+=t1[j];
				y+=t2[j];
			}
		}for(int i=1;i<=len;i++){
			if(x==s1[i].a&&y==s1[i].b){
				if(!f[i]){
					ans++;
				}
				else{
					if(l<g_l[i]||t1.sz-r<s[i].a.sz-g_r[i]) continue;
					bool flag=1;
					for(int j=1;j<=g_l[i];j++){
						if(t1[l-j]!=s[i].a[g_l[i]-j]){
							flag=0;
							break;
						}
					}
					if(flag){
						for(int j=1;j<=s[i].a.sz-g_r[i];j++){
							if(t1[r+j]!=s[i].a[g_r[i]+j]){
								flag=0;
								break;
							}
						}
					}
					if(flag){
						ans++;
					}
				}
			}
		}cout<<ans<<endl;
	}
	return 0;
}

