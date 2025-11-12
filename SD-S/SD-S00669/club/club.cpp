#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct student{
	int a,b,c;
}s[100010];//每个学生 
struct club{
	int like;
	int l,cha,secon;
	char nex;
}a[100010],b[100010],c[100010];//三个社团 
long long ans;
int cnta,cntb,cntc;
bool cmp(club x,club y){
	return x.cha<y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		ans=0,cnta=1,cntb=1,cntc=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>=max(s[i].b,s[i].c)){
				a[++cnta].l=i;
				a[cnta].like=s[i].a;
				ans+=s[i].a;
				if(s[i].b>s[i].c){
				    a[cnta].cha=(s[i].b-s[i].a);
				}else{
				    a[cnta].cha=(s[i].c-s[i].a);	
				}
			}else if(s[i].b>=max(s[i].a,s[i].c)){
				b[++cntb].l=i;
				b[cntb].like=s[i].b;
				ans+=s[i].b;
				if(s[i].a>s[i].c){
				    b[cntb].cha=(s[i].a-s[i].b);
				}else{
				    b[cntb].cha=(s[i].c-s[i].b);	
				}
			}else{
				c[++cntc].l=i;
				c[cntc].like=s[i].c;
				ans+=s[i].c;
				if(s[i].b>s[i].a){
				    c[cntc].cha=(s[i].b-s[i].c);
				}else{
				    c[cntc].cha=(s[i].a-s[i].c);	
				}
			}
		}
		sort(a+1,a+1+cnta,cmp);
		sort(b+1,b+1+cntb,cmp);
		sort(c+1,c+1+cntc,cmp);
		while(n/2<cnta){
			ans+=a[cnta].cha;
			cnta--;
		}
		while(n/2<cntb){
			ans+=b[cntb].cha;
			cntb--;
		}
		while(n/2<cntc){
			ans+=c[cntc].cha;
			cntc--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//rp++;
//rp++;
//rp++;
//rp++;
//rp++;
//rp++;
//rp++;
