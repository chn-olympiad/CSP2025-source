#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read(){
	int ans=0,j=1;
	char c=getchar();
	while(c>'9' or c<'0'){
		if(c=='-')
			j=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		ans=(ans<<3)+(ans<<1)+(c^48);
		c=getchar();
	}
	return ans*j;
}
void write(int x){
	if(x<0)
		putchar('-'),
		x=-x;
	if(x>9)
		write(x/10);
	putchar('0'+x%10);
}
const int N=1e5+5;
int T,n;
struct node{
	int a[4],mx,p,sec;
}s[N];
vector<int> v[4];
bool cmp(int x,int y){
	return s[x].mx-s[x].sec<s[y].mx-s[y].sec;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		v[1].clear();
		v[2].clear();
		v[3].clear();
		n=read();
		int ans=0;
		for(int i=1;i<=n;++i){
			s[i].mx=s[i].sec=-1,s[i].p=-1;
			for(int j=1;j<=3;++j){
				s[i].a[j]=read();
				if(s[i].a[j]>s[i].mx){
					s[i].sec=s[i].mx;
					s[i].mx=s[i].a[j];
					s[i].p=j;
				}else if(s[i].a[j]>s[i].sec)
					s[i].sec=s[i].a[j];
			}
			ans+=s[i].mx;
			v[s[i].p].push_back(i);
		}
		int f=1,mn=1e9;
		mn=min(min(v[1].size(),v[2].size()),v[3].size());
		if(v[2].size()>v[f].size())f=2;
		if(v[3].size()>v[f].size())f=3;
		if(v[f].size()>n/2){
			sort(v[f].begin(),v[f].end(),cmp);
			if(mn==0){//f不能全给某个人
				int now=v[f].size(),cnt=0;
				int g[4]={0};
				for(int i=0;i<v[f].size();++i){
					if(now*2<=n)//给够了
						break;
					--now,++cnt;
					ans-=s[v[f][i]].mx-s[v[f][i]].sec;//给
					for(int j=1;j<=3;++j)
						if(s[v[f][i]].sec==s[v[f][i]].a[j])
							g[j]=1;
				}
//				if((n%2==1) and g[1]+g[2]+g[3]-g[f]==1){//只给了某一个人，反悔!
//					int mn=1e9,who,fa;
//					for(int i=1;i<=3;++i)
//						if(!g[i])
//							who=i;
//					for(int i=1;i<=3;++i)
//						if(i!=who and i!=f)
//							fa=i;
//					for(int i=0;i<cnt;++i)//1把一个给2的反悔给3
//						mn=min(mn,s[v[f][i]].sec-s[v[f][i]].a[who]);
//					for(int i=cnt;i<v[f].size();++i)//1再给一个给3
//						mn=min(mn,s[v[f][i]].mx-s[v[f][i]].a[who]);
//					for(int i=0;i<v[fa].size();++i)//2给3一个
//						mn=min(mn,s[v[fa][i]].mx-s[v[fa][i]].a[who]);
//					cout<<"mn="<<mn<<'\n'; 
//					ans-=mn;
//				}
			}else{//f随便给
				int now=v[f].size();
				for(int i=0;i<v[f].size();++i){
					if(now*2<=n)//给够了
						break;
					--now;
					ans-=s[v[f][i]].mx-s[v[f][i]].sec;//给
				}
			}
			write(ans);
			putchar(10);
		}else{
			write(ans);
			putchar(10);
		}
	}
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/