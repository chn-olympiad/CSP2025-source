#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int x,y=1;
	if(c=='-')y=-1;
	c=getchar();
	while(c>='0'&&c<='9'){
	   x=x*10+c-'0';
	   c=getchar();
	}
	return x*y;
}
int s1[205][2],s2[205][2],t1[205][2],t2[205][2];
int n,m,ans;
int k126[205],k226[205];
int ksm(int a,int n){
	int ans=1;
	int mod=n+2;
	while(n){
		if(n&2){
			ans=ans*a%mod;
		}
		a=a*a%mod;
		n>>=1;
	}
	return ans;
}
void init(){
	k126[0]=k226[0]=1;
	for(int i=1;i<=204;i++){
		k126[i]=k126[i-1]*26%998244353;
		k226[i]=k226[i-1]*26%1000000007;
		k126[i]=ksm(k126[i],998244351);
		k226[i]=ksm(k226[i],1000000005);
	}
	return;
}
signed main(){
    //freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    init();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	string a1,a2;
    	cin>>a1>>a2;
    	s1[i][0]=s1[i][1]=s2[i][0]=s2[i][1]=1;
    	for(int j=0;j<a1.length();j++){
    		s1[i][0]=(s1[i][0]*26+a1[j]-'a')%998244353;
    		s1[i][1]=(s1[i][1]*26+a1[j]-'a')%1000000007;
		}
		for(int j=0;j<a1.length();j++){
    		s2[i][0]=(s2[i][0]*26+a2[j]-'a')%998244353;
    		s2[i][1]=(s2[i][1]*26+a2[j]-'a')%1000000007;
		}
	}
	for(int i=1;i<=m;i++){
		string a1,a2;
	    cin>>a1>>a2;
	    ans=0;
	    t1[0][0]=t1[0][1]=t2[0][0]=t2[0][1]=0;
	    for(int j=0;j<min(a1.length(),a2.length());j++){
    		t1[j][0]=(t1[max(j-1,j-j)][0]*26+a1[j]-'a')%998244353;
    		t1[j][1]=(t1[max(j-1,j-j)][1]*26+a1[j]-'a')%1000000007;
		}
		for(int j=0;j<min(a1.length(),a2.length());j++){
    		t2[j][0]=(t2[max(j-1,j-j)][0]*26+a2[j]-'a')%998244353;
    		t2[j][1]=(t2[max(j-1,j-j)][1]*26+a2[j]-'a')%1000000007;
		}
		cout<<t1[a1.length()-1][0]<<" "<<s1[1][0]<<endl;
	    if(a1.length()!=a2.length()){
	    	cout<<0;
			continue; 
		}
		for(int w=1;w<=n;w++){
			if(t1[a1.length()-1][0]==s1[w][0]&&t1[a1.length()-1][1]==s1[w][1]&&t2[a1.length()-1][0]==s2[w][0]&&t2[a1.length()-1][1]==s2[w][1])ans++;
		}
		bool flag=false;
		for(int j=0;j<a1.length();j++){
			for(int k=j;k<a1.length();k++){
				if((t1[j][0]!=t2[j][0]||t1[j][1]!=t2[j][1])){
					flag=true;
					break;
				}
				if(((t1[a1.length()-1][0]-t1[k][0])*k126[k+1]%998244353!=(t2[a2.length()-1][0]-t2[k][0])*k126[k+1]%998244353||(t1[a1.length()-1][1]-t1[k][1])*k226[k+1]%1000000007!=(t2[a2.length()-1][1]-t2[k][1])*k226[k+1]%1000000007)){
					flag=true;
					continue;
				}
				for(int w=1;w<=n;w++){
					if(j==0){
						if(t1[k][0]==s1[w][0]&&t1[k][1]==s1[w][1]&&t2[k][0]==s2[w][0]&&t2[k][1]==s2[w][1])ans++;
					}else{
						if((t1[k][0]-t1[j-1][0])*k126[j]%9988244353==s1[w][0]&&(t1[k][1]-t1[j-1][1])*k226[j]%1000000007==s1[w][1]&&(t2[k][0]-t2[j-1][0])*k126[j]%9988244353==s2[w][0]&&(t2[k][1]-t2[j-1][1])*k226[j]%1000000007==s2[w][1]){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

