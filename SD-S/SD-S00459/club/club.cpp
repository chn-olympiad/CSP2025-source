#include<bits/stdc++.h>
using namespace std;
int t,n,fa=1,fb=1;
struct node{
	int a,b,c;
}s[200010];
struct cha{
	int maxn,wei,ch;
}k[200010];
bool cmp1(node x,node y){
	return x.a>y.a;
}
bool cmp2(cha x,cha y){
	return x.ch<y.ch;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].b!=0 || s[i].c!=0)fa=0;
			if(s[i].c!=0)fb=0;
		}
		if(fa==1){
			int ans=0;
			sort(s+1,s+1+n,cmp1);
			for(int i=1;i<=n/2;i++)ans+=s[i].a;
			cout<<ans<<'\n';
			continue;
		}
		if(fb==1){
			int cnta=0,cntb=0,ans=0;
			for(int i=1;i<=n;i++){
				if(s[i].a>s[i].b){
					k[i].maxn=s[i].a;
					k[i].wei=1;
					k[i].ch=s[i].a-s[i].b;
					cnta++;
				}
				else if(s[i].a<s[i].b){
					k[i].maxn=s[i].b;
					k[i].wei=2;
					k[i].ch=s[i].b-s[i].a;
					cntb++;
				}
				else{
					k[i].maxn=s[i].a;
					k[i].wei=0;
					k[i].ch=0;
				}
			}
			/*for(int i=1;i<=n;i++){
				cout<<k[i].maxn<<" "<<k[i].wei<<' '<<k[i].ch<<endl;
			}*/
			for(int i=1;i<=n;i++)ans+=k[i].maxn;
			if(cnta==cntb){
				cout<<ans<<'\n';
				continue;
			}
			if(cnta>cntb){
				int cp=1;
				int len=cnta-n/2;
				sort(k+1,k+1+n,cmp2);
				for(int i=1;i<=n;i++){
					if(k[i].wei==1 && cp<=len)ans-=k[i].ch,cp++;
				}
				cout<<ans<<'\n';
			}
			if(cnta<cntb){
				int cp=1;
				int len=cntb-n/2;
				sort(k+1,k+1+n,cmp2);
				for(int i=1;i<=n;i++){
					if(k[i].wei==2 && cp<=len)ans-=k[i].ch,cp++;
				}
				cout<<ans<<'\n';
			}
		}
		else{
			int cnta=0,cntb=0,cntc=0,ans=0,xi=0;
			for(int i=1;i<=n;i++){
				if(s[i].a>max(s[i].b,s[i].c)){
					cnta++;
					k[i].maxn=s[i].a;
					k[i].wei=1;
					k[i].ch=s[i].a-max(s[i].b,s[i].c);
				}
				if(s[i].b>max(s[i].a,s[i].c)){
					cntb++;
					k[i].maxn=s[i].b;
					k[i].wei=2;
					k[i].ch=s[i].b-max(s[i].a,s[i].c);
				}
				if(s[i].c>max(s[i].b,s[i].a)){
					cntc++;
					k[i].maxn=s[i].c;
					k[i].wei=3;
					k[i].ch=s[i].c-max(s[i].b,s[i].a);
				}
				if(s[i].a==s[i].b && s[i].b==s[i].c){
					k[i].maxn=s[i].a;
					k[i].wei=0;
					k[i].ch=0;
				}
			}
			//cout<<cnta<<' '<<cntb<<' '<<cntc<<endl;
			for(int i=1;i<=n;i++)ans+=k[i].maxn;
			/*cout<<ans<<endl;
			for(int i=1;i<=n;i++){
				cout<<k[i].maxn<<" "<<k[i].wei<<' '<<k[i].ch<<endl;
			}*/
			if(cnta==n/2 || cntb==n/2 || cntc==n/2){
				cout<<ans<<'\n';
				continue;
			}
			if(cnta>n/2){
				int cp=1;
				int len=cnta-n/2;
				sort(k+1,k+1+n,cmp2);
				for(int i=1;i<=n;i++){
					if(k[i].wei==1 && cp<=len)ans-=k[i].ch,cp++;
				}
				cout<<ans<<'\n';
			}
			if(cntb>n/2){
				int cp=1;
				int len=cntb-n/2;
				sort(k+1,k+1+n,cmp2);
				for(int i=1;i<=n;i++){
					if(k[i].wei==2 && cp<=len)ans-=k[i].ch,cp++;
				}
				cout<<ans<<'\n';
			}
			if(cntc>n/2){
				int cp=1;
				int len=cntc-n/2;
				sort(k+1,k+1+n,cmp2);
				for(int i=1;i<=n;i++){
					if(k[i].wei==3 && cp<=len)ans-=k[i].ch,cp++;
				}
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}
/*
1
4
10 6 0
3 2 0
9 4 0
3 9 0

1
4
4 2 1
3 2 4
5 3 4
3 5 1

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1 
10 
2020 14533 18961 
2423 15344 16322 
1910 6224 16178 
2038 9963 19722 
8375 10557 5444 
3518 14615 17976 
6188 13424 16615 
8769 509 4394 
958 3195 9953 
16441 5313 10926 
*/
