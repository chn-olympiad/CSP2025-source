#include<bits/stdc++.h> 
#define ULL unsigned long long
using namespace std;
const int N=1e6+10;
const ULL P=131;
int n,q,ll[N];
char s[2][N],t[2][N];
ULL ss[N][2], ts[2][N], p[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<N;i++) p[i]=p[i-1]*P;
	for(int i=1;i<=n;i++){
		cin>>s[0]+1>>s[1]+1;
		ll[i]=strlen(s[0]+1);
		for(int k=0;k<2;k++){
			for(int j=1;j<=strlen(s[0]+1);j++){
				ss[i][k]=ss[i][k]*P+s[k][j]-'a'+1;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t[0]+1>>t[1]+1;int ans=0;
		for(int k=0;k<2;k++){
			for(int j=1;j<=strlen(t[0]+1);j++){
				ts[k][j]=ts[k][j-1]*P+t[k][j]-'a'+1;
			}
		}
		for(int j=1;j<=strlen(t[0]+1);j++){
			ULL A=ts[0][j-1]*p[strlen(t[0]+1)-j+1],B=ts[1][j-1]*p[strlen(t[0]+1)-j+1];
			if(A!=B) continue;
			for(int k=1;k<=n;k++){
				int l=ll[k]+j-1;
				A+=ss[k][0]*p[strlen(t[0]+1)-l]+ts[0][strlen(t[0]+1)]-ts[0][l]*p[strlen(t[0]+1)-l];
				B+=ss[k][1]*p[strlen(t[0]+1)-l]+ts[1][strlen(t[0]+1)]-ts[1][l]*p[strlen(t[0]+1)-l];
				if(A==B) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}