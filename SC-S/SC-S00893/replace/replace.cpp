#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int N=2e5+5,M=5e6+5,P=1e9+7;
struct node{int len;ull x,y;int idx1,idx2;}a[N];
ull h1[M],h2[M],mul[M];

inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48),ch=getchar();}
	return s*f;
}

inline ull get1(int x,int y){
	if(x>y) return 0;
	return h1[y]-h1[x-1]*mul[y-x+1];
}

inline ull get2(int x,int y){
	if(x>y) return 0;
	return h2[y]-h2[x-1]*mul[y-x+1];
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	mul[0]=1;
	for(int i=1;i<=5e6;i++) mul[i]=mul[i-1]*P;
	bool tag=1;
	for(int i=1;i<=n;i++){
		string s1,s2;cin>>s1>>s2;
		int len1=s1.size(),len2=s2.size();
		s1=" "+s1,s2=" "+s2;
		int cnt1=0,cnt2=0,idx1=0,idx2=0;
		for(int j=1;j<=len1;j++) {
			if(s1[j]=='a') cnt1++;
			if(s1[j]=='b') cnt2++,idx1=j;
		}
		if(cnt1!=len1-1 || cnt2!=1) tag=0;
		cnt1=0,cnt2=0;
		for(int j=1;j<=len2;j++) {
			if(s2[j]=='a') cnt1++;
			if(s2[j]=='b') cnt2++,idx2=j;
		}
		if(cnt1!=len2-1 || cnt2!=1) tag=0;
		ull x=0,y=0;
		for(int j=1;j<=len1;j++) x=x*P+s1[j];
		for(int j=1;j<=len2;j++) y=y*P+s2[j];
		a[i]={len1,x,y,idx1,idx2};
	}
	while(q--){
		string s1,s2;cin>>s1>>s2;
		int len1=s1.size(),len2=s2.size();
		if(len1!=len2){
			cout<<"0\n";
			continue;
		}
		bool tg=1;int cnt1=0,cnt2=0,idx1=0,idx2=0;
		s1=" "+s1,s2=" "+s2;
		for(int j=1;j<=len1;j++) {
			if(s1[j]=='a') cnt1++;
			if(s1[j]=='b') cnt2++,idx1=j;
		}
		if(cnt1!=len1-1 || cnt2!=1) tg=0;
		cnt1=0,cnt2=0;
		for(int j=1;j<=len2;j++) {
			if(s2[j]=='a') cnt1++;
			if(s2[j]=='b') cnt2++,idx2=j;
		}
		if(cnt1!=len2-1 || cnt2!=1) tg=0;
		if(tag && tg){
			int ans=0;
			for(int i=1;i<=n;i++){
				int id1=a[i].idx1,id2=a[i].idx2;
				int idxx1=idx1,idxx2=idx2;
				if(id2-id1!=idxx2-idxx1) continue;
				if(idxx1>idxx2) swap(idxx1,idxx2);
				if(id1>id2) swap(id1,id2);
				if(id1>idxx1 || a[i].len-id2>len1-idxx2) continue;
				ans++;
			}
			cout<<ans<<"\n";
		}else{
			for(int i=1;i<=len1;i++) h1[i]=h1[i-1]*P+s1[i];
			for(int i=1;i<=len2;i++) h2[i]=h2[i-1]*P+s2[i];
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=a[i].len;j<=len1;j++){
					int l=j-a[i].len+1,r=j;
					if(get1(1,l-1)==get2(1,l-1) && get1(r+1,len1)==get2(r+1,len2) && get1(l,r)==a[i].x && a[i].y==get2(l,r)) ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/*
有一个O(n*L2)的思路是hash+check 
只有25分啊QWQ 
B性质可以找b然后往两边对应，O(n)的，还有25

50
*/