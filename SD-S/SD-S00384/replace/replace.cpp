#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,q,cnt;
struct f{
	int e,b,c,d;
}a[maxn];
int t[2100],ans[1100],z[2100],pos;
string s[maxn][2];
string s1[maxn][2];
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=q;j++){
			int flag1=-1;
			pos=0;
			for(int k=0;k<s1[j][0].size();k++){
				if(s1[j][0][k]==s[i][0][0]){
					bool flag=0;
					for(int p=0;p<s[i][0].size();p++){
						if(s[i][0][p]!=s1[j][0][k+p]){
							flag=1;
							break;
						}
					}
					if(!flag){
						t[k]=1;
						z[++pos]=k;
					}
				}
			}
			for(int k=0;k<s1[j][1].size();k++){
				if(s1[j][1][k]==s[i][1][0]){
					bool flag=0;
					for(int p=0;p<s[i][1].size();p++){
						if(s[i][1][p]!=s1[j][1][k+p]){
							flag=1;
							break;
						}
					}
					if(!flag){
						if(t[k]==1){
							if(flag1!=-1){
								flag1=-1;
								break;
							}
							flag1=k;
						}
					}
				}
			}
			for(int k=1;k<=pos;k++){
				t[z[pos]]=0;
			}
			if(flag1==-1){
				continue;
			}
			for(int k=0;k<flag1;k++){
				if(s1[j][0][k]!=s1[j][1][k]){
					flag1=-1;
					break;
				}
			}
			if(flag1==-1) continue;
			for(int k=flag1+s[i][1].size();k<s1[j][0].size();k++){
				if(s1[j][0][k]!=s1[j][1][k]){
					flag1=-1;
					break;
				}
			}
			if(flag1==-1){
				continue;
			}
			ans[j]++;
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
}
//struct node{
//	int l,r,len;
//}t[maxn];
//void solve1(){
//	for(int i=1;i<=n;i++){
//		int k=0,pos;
//		a[i].c=0;
//		for(int j=1;j<s[i][0].size();j++){
//			if(s[i][0][j]!=s[i][0][0]){
//				a[i].b=j;
//				k++;
//			}
//		}
//		if(k==s[i][0].size()-1){
//			swap(a[i].b,a[i].c);
//		}
//		k=0;
//		a[i].e=0;
//		for(int j=1;j<s[i][1].size();j++){
//			if(s[i][1][j]!=s[i][1][0]){
//				a[i].d=j;
//				k++;
//			}
//		}
//		if(k==s[i][1].size()-1){
//			swap(a[i].d,a[i].e);
//		}
//		a[i].c=a[i].b-a[i].d;
//		t[i]={a[i].b,s[i][1].size()}
//	}
//	for(int i=1;i<=q;i++){
//		
//	}
//}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>s1[i][0]>>s1[i][1];
	}
//	if(n<=1000&&q<=1000){
		solve();
//		return 0;
//	}
//	solve1();
	return 0;
}
