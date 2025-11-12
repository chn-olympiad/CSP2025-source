#include<bits/stdc++.h>
#define rint register int
using namespace std;
//bool soha;
const int mxn=200001;
int n,q;string x[mxn],y[mxn],a,b;
//bool kkksc03;
inline int read(){
    int x=0;bool f=0;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-')f=1;
    for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
    return f?-x:x;
}
inline void print(int x){
	if(x/10){
		print(x/10);
	}putchar((x%10)+'0');
}
void solve(){
	cin>>a>>b;int ans=0;
	if(a.size()!=b.size()){
		print(0);putchar('\n');return;
	}
	int l=0,r=a.size()-1;
	while(a[l]==b[l]&&l<=a.size()-1)l++;
	while(a[r]==b[r]&&r>=0)r--;
	for(rint i=1;i<=n;i++){
		if(x[i]==y[i]){
			if(a==b){
				int idx=0;
				while(1){
					idx=a.find(x[i],idx);
					if(idx==-1)break;
					ans++;idx++;
				}
			}
		}
		int tl=r-x[i].size()+1,tr=a.size()-x[i].size()+1;
		if(x[i].size()>a.size())continue;
		if(x[i].size()<r-l+1)continue;
		for(rint j=max(0,tl);j<min(tr,l+1);j++){
			string ta=a;bool f=1;
			for(rint len=0;len<x[i].size();len++){
				if(a[j+len]!=x[i][len]){
					f=0;break;
				}
				else{
					ta[j+len]=y[i][len];
					if(ta[j+len]!=b[j+len])break;
				}
			}
			if(ta==b&&f)ans++;
			if(a[j]!=b[j])break;
		}
	}
	print(ans);putchar('\n');
}
int main(){
	//printf("%lfMB\n",(&kkksc03-&soha)/1024.0/1024.0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=read();q=read();
    for(rint i=1;i<=n;i++)cin>>x[i]>>y[i];
    while(q--)solve();
    return 0;
}
/*
	Code is far away from
bug with the animal protecting
*/