#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n ,m;string s,st;
struct dt{
	string sl,sr,s;int l,r;
}a[100100],b[100100];
struct xd{
	char a,b,aa,bb;int hi,hih;
}cd[100100];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	if(n*m*n<=1e9){
		for(int i=1;i<=n;i++){
			cin>>s>>st;
			if(s==st)continue;
			a[i].s=s;
			a[i].l=s.size()+1;a[i].r=-1;
			for(int j=0;j<s.size();j++){
				if(s[j]!=st[j]){
					a[i].l=min(a[i].l,j);
					a[i].r=max(a[i].r,j);
				}
			}a[i].sl=a[i].sr="";
			for(int j=a[i].l;j<=a[i].r;j++){
				a[i].sl+=s[j];
				a[i].sr+=st[j];
			}
		}
			
		for(int i=1;i<=m;i++){
			cin>>s>>st;
			b[i].l=s.size()+1;b[i].r=-1;
			for(int j=0;j<s.size();j++){
				if(s[j]!=st[j]){
					b[i].l=min(b[i].l,j);
					b[i].r=max(b[i].r,j);
				}
			}b[i].sl=b[i].sr="";
			for(int j=b[i].l;j<=b[i].r;j++){
				b[i].sl+=s[j];
				b[i].sr+=st[j];
			}int ss=0;
			for(int j=1;j<=n;j++){
				if(b[i].sl==a[j].sl&&b[i].sr==a[j].sr){
					int ll=a[j].l+1;
					int ii=0,bb=0;
					for(int h=b[i].l-ll+1;h<=b[i].r-ll+1;h++){
	//					cout<<h<<' '<<s[h]<<" "<<a[j].s[ii]<<"\n";
						if(s[h]==a[j].s[ii]){
							ii++;
						}
						else if(s[h]!=a[j].s[ii]){
							bb=1;break;
						}
					}if(bb||ii==0)continue;
					ss++;
				}
			}cout<<ss<<"\n";
		}
	}
	for(int j=1;j<=n;j++){
		cin>>s>>st;
		char a,b;a=s[0];int hi;
		for(int i=0;i<s.size();i++){
			if(s[i]!=a){
				b=s[i];
			}
			else if(s[i]==b){
				swap(a,b);
			}
		}
		for(int i=0;i<s.size();i++){
			if(s[i]==b)hi=i;
		}
		char aa,bb;aa=st[0];int hih;
		for(int i=0;i<st.size();i++){
			if(st[i]!=aa){
				bb=s[i];
			}
			else if(st[i]==bb){
				swap(aa,bb);
			}
		}
		for(int i=0;i<s.size();i++){
			if(st[i]==bb)hih=i;
		}
		cd[j]=xd{a,b,aa,bb,hi,hih};
	}
	for(int j=1;j<=n;j++){
		cin>>s>>st;
		char a,b;a=s[0];int hi;
		for(int i=0;i<s.size();i++){
			if(s[i]!=a){
				b=s[i];
			}
			else if(s[i]==b){
				swap(a,b);
			}
		}
		for(int i=0;i<s.size();i++){
			if(s[i]==b)hi=i;
		}
		char aa,bb;aa=st[0];int hih;
		for(int i=0;i<st.size();i++){
			if(st[i]!=aa){
				bb=s[i];
			}
			else if(st[i]==bb){
				swap(aa,bb);
			}
		}
		for(int i=0;i<s.size();i++){
			if(st[i]==bb)hih=i;
		}int ss=0;
		for(int h=1;h<=n;h++){
			if(hih-hi==cd[h].hih-cd[h].hi&&a==cd[h].a&&b==cd[h].b&&aa==cd[h].aa&&bb==cd[h].bb)ss++;
			else if(hih-hi==cd[h].hi-cd[h].hih&&b==cd[h].a&&a==cd[h].b&&bb==cd[h].aa&&aa==cd[h].bb)ss++;
		}cout<<ss<<"\n";
	}
	return 0;
}
//30+


