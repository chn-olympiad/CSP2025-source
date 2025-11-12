#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
struct stu{
	int a,b,c;
	int ch,mx,mn;
}s[N];
bool cmp(stu x,stu y){
	if(x.ch==y.ch)return x.mx>y.mx;
	return x.ch>y.ch;
}
//ÒÉËÆAC£¬2.5hÒ»µÀÌâ£¬(TvT) 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int A=n/2,B=n/2,C=n/2;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			int f[4]={0,s[i].a,s[i].b,s[i].c};
			sort(f+1,f+1+3);
			s[i].mx=f[3],s[i].mn=f[1];
			s[i].ch=f[3]-f[2];
		}
		sort(s+1,s+1+n,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s[i].mx==s[i].a){
				if(A)ans+=s[i].mx,A--;
				else if(s[i].b>=s[i].c){
					if(B)ans+=s[i].b,B--;
					else ans+=s[i].c,C--;
				}else{
					if(C)ans+=s[i].c,C--;
					else ans+=s[i].b,B--;
				} 
			}else if(s[i].mx==s[i].b){
				if(B)ans+=s[i].b,B--;
				else if(s[i].a>=s[i].c){
					if(A)ans+=s[i].a,A--;
					else ans+=s[i].c,C--;
				}else {
					if(C)ans+=s[i].c,C--;
					else ans+=s[i].a,A--;
				}
			}else {
				if(C)ans+=s[i].c,C--;
				else if(s[i].a>=s[i].b){
					if(A)ans+=s[i].a,A--;
					else ans+=s[i].b,B--;
				}else {
					if(B)ans+=s[i].b,B--;
					else ans+=s[i].a,A--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
