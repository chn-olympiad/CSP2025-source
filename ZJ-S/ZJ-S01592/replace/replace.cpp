#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Fol(i,a,b) for(int i=b;i>=a;i--)
#define bug(a) cout<<" ( "<<#a<<" : "<<a<<" ) ";
#define bugln(a) cout<<" ( "<<#a<<" : "<<a<<" )\n";
#define bugg cout<<" --Debug ";
#define buggln cout<<" --Debug\n";
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define PII pair<int,int>
using namespace std;

typedef unsigned long long ull;

const int M=2e5+10,P=131;

int n,q;
struct node{
	ull ori_hsh1,sam_hsh1,ori_hsh2,sam_hsh2;
	int ori_len,sam_len,sam_pos;
}hsh[M];
int idx;
vector<int>id[M];
char s1[M],s2[M];
ull p[M],h1[M],h2[M];

ull gthsh(int l,int r,ull h[]){
	return h[r]-h[l-1]*p[r-l+1];
}

//void fo(int x){
//	if(x==0){
//		putchar('0');
//		putchar('\n');
//		return ;
//	}
//	int ans[20],idx=0;
//	while(x){
//		ans[++idx]=x%10;
//		x/=10;
//	}
//	Fol(i,1,idx){
//		putchar(ans[i]+'0');
//	}
//	putchar('\n');
//}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	bug(sizeof hsh)
	scanf("%lld%lld\n",&n,&q);
	p[0]=1;
	For(i,1,M-5){
		p[i]=p[i-1]*P;
	}
	int p1,p2;
	For(i,1,n){
		scanf("%s %s\n",s1+1,s2+1);
		int len=strlen(s1+1);
		p1=p2=-1;
		For(j,1,len){
			if(s1[j]!=s2[j]&&p1==-1){
				p1=j;
			}
			if(s1[len-j+1]!=s2[len-j+1]&&p2==-1){
				p2=len-j+1;
			}
			h1[j]=h1[j-1]*P+s1[j];
			h2[j]=h2[j-1]*P+s2[j];
		}
		if(p1==-1){
			continue;
		}
		hsh[++idx]={h1[len],gthsh(p1,p2,h1),h2[len],gthsh(p1,p2,h2),len,p2-p1+1,p1};
		id[p2-p1+1].eb(idx);
	}
//	bug(1)
	int ans;
	while(q--){
		ans=0;
		scanf("%s %s\n",s1+1,s2+1);
		int len=strlen(s1+1);
		if(len!=(int)strlen(s2+1)){
			putchar('0');putchar('\n');
			continue;
		}
		p1=p2=-1;
		For(j,1,len){
			if(s1[j]!=s2[j]&&p1==-1){
				p1=j;
			}
			if(s1[len-j+1]!=s2[len-j+1]&&p2==-1){
				p2=len-j+1;
			}
			h1[j]=h1[j-1]*P+s1[j];
			h2[j]=h2[j-1]*P+s2[j];
		}
//		bug(p1)bugln(p2)
		for(auto i:id[p2-p1+1]){
//			bug(i)
//			bug(p1-hsh[i].sam_pos+1)bugln(p1-hsh[i].sam_pos+hsh[i].ori_len)
//			bug(gthsh(p1,p2,h2))bugln(hsh[i].sam_hsh2)
			if(gthsh(p1,p2,h1)==hsh[i].sam_hsh1&&gthsh(p1,p2,h2)==hsh[i].sam_hsh2&&
				gthsh(p1-hsh[i].sam_pos+1,p1-hsh[i].sam_pos+hsh[i].ori_len,h1)==hsh[i].ori_hsh1&&
				gthsh(p1-hsh[i].sam_pos+1,p1-hsh[i].sam_pos+hsh[i].ori_len,h2)==hsh[i].ori_hsh2&&
				p1-hsh[i].sam_pos+1>=1&&p1-hsh[i].sam_pos+hsh[i].ori_len<=len
			){
				ans++;
			}
		}
		printf("%lld\n",ans);
//		fo(ans);
	}
	return 0;
}
//chzx_lfw AK IOI!!!!!

//Never notice me
//Never call my name with your voice!
//Let me forget everything
//Still moonlight shines on us
//...
//I'll end it all.
//And testify!!!!
