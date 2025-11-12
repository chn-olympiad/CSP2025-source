#include<bits/stdc++.h>
using namespace std;
typedef  unsigned int long long ull;
const ull P=131;
const int N=200;
int n,q;
char s1[N][N],s2[N][N];
ull h1[N],h2[N];
ull H1[N],H2[N];
ull p[N];
char t1[N],t2[N];
int f[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=N-1;i++){
		p[i]=p[i-1]*P;
	}
	for(int i=1;i<=n;i++){
		cin>>s1[i]+1>>s2[i]+1;
		for(int i=1;i<=strlen(s1[i]+1);i++){
			h1[i]=h1[i]*P+(ull)s1[i];
		}
		for(int i=1;i<=strlen(s2[i]+1);i++){
			h2[i]=h2[i]*P+(ull)s2[i];
		}
	}
	
	while(q--){
		memset(f,0,sizeof f);
		cin>>t1+1>>t2+1;
		for(int i=1;i<=strlen(t1+1);i++){
			H1[i]=H1[i-1]*P+t1[i];
		}
		for(int i=1;i<=strlen(t2+1);i++){
			H2[i]=H2[i-1]*P+t2[i];
		}
		f[0]=1;
		for(int i=1;i<=strlen(t1+1);i++){
			if(H1[i]==H2[i]) f[i]=1;
			for(int j=1;j<=i;j++){
				for(int k=1;k<=n;k++){
					if(h1[k]==(H1[i]-H1[j-1]*p[i-j+1])){
						if(h2[k]==(H2[i]-H2[j-1]*p[i-j+1]))
							f[i]+=f[j-1]; 
					}
				}
			}
		}
		cout<<f[strlen(t1+1)]<<endl;
	}
	return 0;
}


