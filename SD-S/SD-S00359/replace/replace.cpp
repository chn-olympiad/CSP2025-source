#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
string s1,s2,t1,t2;
const ull P=131; 
struct Transform{
	int l;
	ull h1,h2;
}tr[200005];
ull sth1(){
	ull hsh=0;
	for(int i=0;i<s1.size();i++){
		hsh=hsh*P+(s1[i]-'a'+1);
	}
	return hsh;
}
ull sth2(){
	ull hsh=0;
	for(int i=0;i<s2.size();i++){
		hsh=hsh*P+(s2[i]-'a'+1);
	}
	return hsh;
}
ull pp[1000006];
ull hsh[1000006];
ull hsh2[1000006];
ull gethsh(int l,int r){
	return hsh[r]-hsh[l-1]*pp[r-l+1];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q; 
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		tr[i].l=s1.size();
		tr[i].h1=sth1();
		tr[i].h2=sth2();
//		cout<<tr[i].h1<<" "<<tr[i].h2<<'\n';
	}
	while(q--){
		cin>>t1>>t2;
		int t=t1.size();
		t1=' '+t1;
		t2=' '+t2;
		pp[0]=1;
		int ans=0;
		for(int i=1;i<=t;i++){
			pp[i]=pp[i-1]*P;
			hsh[i]=hsh[i-1]*P+(t1[i]-'a'+1); 
		}
		for(int i=1;i<=t;i++){
			hsh2[i]=hsh2[i-1]*P+(t2[i]-'a'+1); 
		}
//		printf("%lld\n",hsh2[t]);
		for(int i=1;i<=n;i++){
			int l=tr[i].l;
			for(int j=1;j<=t-l+1;j++){
				if(gethsh(j,j+l-1)==tr[i].h1){
//					printf("can replace %d by %d\n",j,i);
					if(gethsh(1,j-1)*pp[t-j+1]+tr[i].h2*pp[t-l-j+1]+gethsh(j+l,t)==hsh2[t]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
