#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int&a){
	int f=1,x=0;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	a=f*x;
}
void print(int x){
	if(x<0){
		putchar('-');
		print(-x);
		return;
	}
	if(x<10){
		putchar(x+48);
		return;
	}
	else{
		print(x/10);
		putchar(x%10+48);
		return;
	}
}
const int base=131,mod1=1e9+7,mod2=1e9+9;
int p1[5000010],p2[5000010];
int hsh1[5000010],hsh2[5000010];
int n,q;
pair<int,int>Hsh(string s){
	pair<int,int>res;
	res={0,0};
	for(int i=0;i<s.size();i++){
		res.first=(res.first*base%mod1+s[i])%mod1;
		res.second=(res.second*base%mod2+s[i])%mod2;
	}
	return res;
}
map<pair<int,int>,pair<int,int> >mp;
pair<int,int> get_hsh(int l,int r){
	int x=hsh1[r]-hsh1[l-1]*p1[r-l+1]%mod1,y=hsh2[r]-hsh2[l-1]*p2[r-l+1]%mod2;
	x=((x%mod1+mod1)%mod1);
	y=((y%mod2+mod2)%mod2);
	return {x,y};
}
pair<int,int>com(int l,int r,int len,pair<int,int> hsh){
	pair<int,int>res=get_hsh(l,r);
	return {(hsh1[len]+((hsh.first-res.first)%mod1+mod1)%mod1*p1[len-r]%mod1)%mod1,
			(hsh2[len]+((hsh.second-res.second)%mod2+mod2)%mod2*p2[len-r]%mod2)%mod2};
}
bool cmp(pair<int,int>a,pair<int,int>b){
	if(a.first==b.first&&a.second==b.second)return true;
	else return false;
}
int t[5000010],len[5000010],cnt;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p1[0]=p2[0]=1;
	for(int i=1;i<=5000000;i++){
		p1[i]=p1[i-1]*base%mod1;
		p2[i]=p2[i-1]*base%mod2;
	}
	read(n),read(q);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(!t[s1.size()]){
			len[++cnt]=s1.size();
			t[s1.size()]++;
		}
		mp[Hsh(s1)]=Hsh(s2);
	}
//	sort(len+1,len+cnt+1);
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		hsh1[0]=hsh2[0]=0;
		int ans=0;
		pair<int,int>Hsh2=Hsh(s2);
		for(int i=0;i<s1.size();i++){
			hsh1[i+1]=(hsh1[i]*base%mod1+s1[i])%mod1;
			hsh2[i+1]=(hsh2[i]*base%mod2+s1[i])%mod2;
		}
		for(int i=1;i<=cnt;i++){
			int Len=len[i];
			if(Len>s1.size())break;
//			cout<<Len<<'\n';
			for(int l=1;l+Len-1<=s1.size();l++){
				int r=l+Len-1;
//				cout<<l<<' '<<r<<' ';
				pair<int,int>res=get_hsh(l,r);
				if(mp.count(res)){
//					cout<<"Yes ";
					if(cmp(com(l,r,s1.size(),mp[res]),Hsh2)){
//						cout<<"yes";
						ans++;
					}
//					else cout<<"no";
				}
//				cout<<'\n';
			}
//			cout<<"*********\n";
		}
		print(ans);
		puts("");
//		cout<<"------\n";
	}
}
