#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back

const ll N=2e5+10,M=1e9+7,B=131,L=5e6;
int n,q,lth[N],tl1,tl2;
char s[L];
ll c[N][10],t1[L],t2[L],pw[L];

ll hashs(){
	int len=strlen(s);
	ll bac=0;
	for(int i=0;i<len;i++){
		bac=((bac*B)%M+s[i])%M;
	}
	return bac;
}

void hasht1(){
	tl1=strlen(s);
	t1[0]=s[0];
	for(int i=1;i<tl1;i++){
		t1[i]=((t1[i-1]*B)%M+s[i])%M;
	}
	return ;
}
void hasht2(){
	tl2=strlen(s);
	t2[0]=s[0];
	for(int i=1;i<tl2;i++){
		t2[i]=((t2[i-1]*B)%M+s[i])%M;
	}
	return ;
}

signed main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	ios;
	pw[0]=1;
	for(int i=1;i<=L;i++){
		pw[i]=(pw[i-1]*B)%M;
	}
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		memset(t1,0,sizeof t1);
		memset(t2,0,sizeof t2);
		memset(s,0,sizeof s);
		cin >> s;
		lth[i]=strlen(s);
		c[i][1]=hashs();
		memset(s,0,sizeof s);
		cin >> s;
		c[i][2]=hashs();
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		memset(s,0,sizeof s);
		cin >> s;
		hasht1();
		memset(s,0,sizeof s);
		cin >> s;
		hasht2();
		for(int h=1;h<=n;h++){
			for(int j=0;j<=lth[h];j++){
				int l=j-1;
				int r=l+lth[h];
				ll h;
				if(j==0){
					h=t1[r];
				}else{
					h=((((t1[r]-(t1[l]*pw[lth[h]]%M))%M)+M)%M);
				}
				if(h==c[h][1]){
					int h2;
					if(j==0){
						h2=t2[r];
					}else{
						h2=((((t2[r]-(t2[l]*pw[lth[h]]%M))%M)+M)%M);
					}
					if(h2==c[h][2]){
						ans++; 
					}
				}
			}
		}
		cout << ans;
	}
	return 0;
}

