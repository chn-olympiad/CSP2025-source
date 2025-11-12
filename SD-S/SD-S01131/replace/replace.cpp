//
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rop(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define por(i,a,b) for(int i=a;i>b;i--)
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double ld;
using namespace std;
int n,q,l[200005],r[200005],ans,pos[200005],lst[200005];
string s[200005][3],t[200005][3];
//bool flag=1;
//struct node{
//	int len,pos1,pos2;
//	bool operator<(node x)const{
//		return((pos1-pos2==x.pos1-x.pos2)?((pos1==x.pos1)?(pos2>x.pos2):(pos1<x.pos1)):(pos1-pos2<x.pos1-x.pos2));
//	}
//}a[200005];
int getval(int x,int y){
	int res=0;
	rep(i,max(1,r[y]+2-(int)s[x][1].size()),min((int)t[y][1].size()-(int)s[x][1].size()+1,l[y])){
		rep(j,i,i+s[x][1].size()-2)
			if(s[x][1][j-i+1]!=t[y][1][j]||s[x][2][j-i+1]!=t[y][2][j])
				goto loop;
		res++;
		loop:;
	}
	return res;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	rep(i,1,n){
		cin>>s[i][1]>>s[i][2];
		s[i][1]=" "+s[i][1];
		s[i][2]=" "+s[i][2];
//		bool flag1=1,flag2=1;
//		rop(j,1,s[i][1].size()){
//			if(s[i][1][j]!='a'&&s[i][1][j]!='b'||s[i][2][j]!='a'&&s[i][2][j]!='b')
//				flag=0;
//			if(s[i][1][j]=='b'){
//				if(!flag1)
//					flag=0;
//				flag1=0;
//			}
//			if(s[i][2][j]=='b'){
//				if(!flag2)
//					flag=0;
//				flag2=0;
//			}
//		}
	}
	rep(i,1,q){
		cin>>t[i][1]>>t[i][2];
		t[i][1]=" "+t[i][1];
		t[i][2]=" "+t[i][2];
//		bool flag1=1,flag2=1;
//		rop(j,1,t[i][1].size()){
//			if(t[i][1][j]!='a'&&t[i][1][j]!='b'||t[i][2][j]!='a'&&t[i][2][j]!='b')
//				flag=0;
//			if(t[i][1][j]=='b'){
//				if(!flag1)
//					flag=0;
//				flag1=0;
//			}
//			if(t[i][2][j]=='b'){
//				if(!flag2)
//					flag=0;
//				flag2=0;
//			}
//		}
	}
//	if(flag){
//		rep(i,1,n){
//			int pos1,pos2;
//			rop(j,1,s[i][1].size()){
//				if(s[i][1][j]=='b')
//					pos1=j;
//				if(s[i][2][j]=='b')
//					pos2=j; 
//			}
//			a[i]={s[i][1].size()-1,pos1,pos2};
//		}
//		sort(a+1,a+n+1);
//		rep(i,1,n)
//			pos[i]=a[i].pos1-a[i].pos2;
//		lst[1]=1;
//		rep(i,2,n){
//			if(pos[i]!=pos[i-1])
//				lst[i]=i-1;
//			else
//				lst[i]=lst[i-1];
//		}
//		rep(i,1,q){
//			int pos1,pos2;
//			rop(j,1,t[i][1].size()){
//				if(t[i][1][j]=='b')
//					pos1=j;
//				if(t[i][2][j]=='b')
//					pos2=j;
//			}
//			
//		}
//		return 0;
//	}
	rep(i,1,q){
		ans=0;
		l[i]=n;
		r[i]=0;
		rop(j,1,t[i][1].size())
			if(t[i][1][j]!=t[i][2][j]){
				l[i]=min(l[i],j);
				r[i]=max(r[i],j);
			}
		rep(j,1,n)
			ans+=getval(j,i);
		cout<<ans<<endl;
	}
	return 0;
}
/*
40
*/

