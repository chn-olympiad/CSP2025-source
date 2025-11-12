#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	}
	return s*w;
}
void write(int x){
	if(x<0){
		putchar('-');
		write(-x);
		return ;
	}
	if(x<=9){
		putchar('0'+x);
		return ;
	}
	write(x/10);
	putchar('0'+x%10);
	return ;
}
const int N=2e5+5;
const int M=5e6+5;
const int mod=998244353;
const int inf=1e18+7;
const ull base=131;
ull L[M];
void ycl(){
	L[0]=1;
	for(int i=1;i<=M-5;i++){
		L[i]=L[i-1]*base;
	}
	return ;
}
string s[N][2];
ull has[N][2],hx[M][2];
unordered_map <ull,int> mp;
inline ull qie(int l,int r,int x){
	if(l==0)return hx[r][x];
	return hx[r][x]-hx[l-1][x]*L[r-l+1];
}
int ne[M];
signed main(){
//	system("fc replace.out replace3.ans");
//	return 0;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ycl();
	int n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=n;i++){
		int len=s[i][0].size()-1;
		for(int j=0;j<=len;j++){
			has[i][0]=has[i][0]*base+s[i][0][j];
			has[i][1]=has[i][1]*base+s[i][1][j];
		}
		mp[has[i][0]]=i;
	}
	int B=80;
	while(q--){
//		cout<<"q "<<q<<endl;
		string t[2];
		cin>>t[0]>>t[1];
		int len=t[0].size()-1;
		if(t[0].size()!=t[1].size()){
			puts("0");
//			cout<<0<<endl;
			continue;
		}
		int l=0,r=len;
//		cout<<t[0][l]<<" "<<t[1][l]<<endl;
		while(t[0][l]==t[1][l]&&l<=len){
//			cout<<l<<endl;
			l++;
		}
		while(t[0][r]==t[1][r]&&r>=0){
//			cout<<r<<endl;
			r--;
		}
//		cout<<"l "<<l<<" "<<r<<endl;
//		break;
		hx[0][0]=t[0][0];
		hx[0][1]=t[1][0];
		for(int i=1;i<=len;i++){
			hx[i][0]=hx[i-1][0]*base+t[0][i];
			hx[i][1]=hx[i-1][1]*base+t[1][i];
//			cout<<"hx "<<hx[i][0]<<" "<<hx[i][1]<<endl;
		}
//		break;
		int ans=0;
		if(l*(len-r+1)<=B*B){
			for(int i=0;i<=l;i++){
				for(int j=r;j<=len;j++){
					ull t=qie(i,j,0);
//					cout<<"qq "<<i<<" "<<j<<" "<<qie(i,j,0)<<endl;
					auto op=mp.find(t);
					if(op==mp.end())continue;
					int s1=(*op).second;
					if(has[s1][1]==qie(i,j,1)){
//						cout<<"qie "<<i<<" "<<j<<" "<<has[s1][1]<<" "<<qie(i,j,1)<<endl;
						ans++;
					}
				}
			}
		}
		else{
			for(int i=0;i<=r-l+1;i++){
				ne[i]=0;
			}
			int p=0;
			for(int i=1;i<=r-l+1;i++){
				while(p!=0&&t[0][l+p]!=t[0][l+i])p=ne[p];
				if(p!=0&&t[0][l+p]==t[0][l+i])p++;
				ne[i]=p;
			}
			for(int j=1;j<=n;j++){
				int le=s[j][0].size()-1;
				if(le+1<r-l+1)continue;
				int p=0;
				for(int i=0;i<=le;i++){
					if(r+le-i>len)break;
					while(p==r-l+1||(p!=0&&t[0][l+p]!=s[j][0][i]))p=ne[p];
					if(t[0][l+p]==s[j][0][i])p++;
					if(p==r-l+1){
						if(i>r||r+le-i>len)continue;
						if(has[j][1]==qie(r-i,r+le-i,1))ans++;
					}
				}
			}
		}
		write(ans);
		puts("");
//		cout<<ans<<endl;
	}
	return 0;
}