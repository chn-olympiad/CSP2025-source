#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int M=100000;
struct node{
	int aa;
	int bb;
	int cc;
	int a;
	int b;
	int c;
	int val;
	int m;
}s[N];
int t,n,pos,cnt;
int ans;
bool aaa1(node x,node y){
	return x.val<y.val;
}
bool aaa2(node x,node y){
	return x.m>y.m;
}
bool aaa3(node x,node y){
	return x.c<y.c;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>s[i].aa>>s[i].bb>>s[i].cc;
		pos=0;
		for(int i=1;i<=n;i++){// based on c
			s[i].c=s[i].cc;
			s[i].a=s[i].aa-s[i].cc;
			s[i].b=s[i].bb-s[i].cc;
			ans+=s[i].c;
			s[i].c=0;
			s[i].m=max(s[i].a,s[i].b);
			if(s[i].a<0&&s[i].b<0) s[i].val=1;
			else s[i].val=0;
			if(s[i].val) pos++;
		}
		if(pos>=n/2){
			sort(s+1,s+n+1,aaa2);
			for(int i=1;i<=n/2;i++)
				ans+=s[i].m;
		}
		else{
			ans=0;
			pos=0;
			for(int i=1;i<=n;i++){// based on a
				s[i].c=s[i].aa;
				s[i].a=s[i].bb-s[i].aa;
				s[i].b=s[i].cc-s[i].aa;
				ans+=s[i].c;
				s[i].c=0;
				s[i].m=max(s[i].a,s[i].b);
				if(s[i].a<0&&s[i].b<0) s[i].val=1;
				else s[i].val=0;
				if(s[i].val) pos++;
			}
			if(pos>=n/2){
				sort(s+1,s+n+1,aaa2);
				for(int i=1;i<=n/2;i++)
					ans+=s[i].m;
			}
			else{
				ans=0;
				pos=0;
				for(int i=1;i<=n;i++){// based on b
					s[i].c=s[i].bb;
					s[i].a=s[i].aa-s[i].bb;
					s[i].b=s[i].cc-s[i].bb;
					ans+=s[i].c;
					s[i].c=0;
					s[i].m=max(s[i].a,s[i].b);
					if(s[i].a<0&&s[i].b<0) s[i].val=1;
					else s[i].val=0;
					if(s[i].val) pos++;
				}
				if(pos>=n/2){
					sort(s+1,s+n+1,aaa2);
					for(int i=1;i<=n/2;i++)
						ans+=s[i].m;
				}
				else {//Directll calculate
					ans=0;
					for(int i=1;i<=n;i++)
						ans+=max(max(s[i].aa,s[i].bb),s[i].cc);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//chzx_lfw AK IOI!!!!!
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
/*
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

18
4
13

*/
