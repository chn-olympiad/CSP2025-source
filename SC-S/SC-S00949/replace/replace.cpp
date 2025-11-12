#include<bits/stdc++.h>
#define N 5000005
using namespace std;
struct Node{
	int cnt;
	unordered_map<int,int>mp;
}trie[N];
int p=1,n,q;
string a,b;
int h(char a,char b){
	return (a-'a')*26+(b-'a')+1;
}int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		int len=a.size(),pos=1;
		for(int j=0;j<len;j++){
			int v=h(a[j],b[j]);
			if(!trie[pos].mp[v])trie[pos].mp[v]=++p;
			pos=trie[pos].mp[v];
		}trie[pos].cnt++;
	}while(q--){
		cin>>a>>b;
		int len=a.size(),cmp=b.size();
		if(len!=cmp)cout<<0<<endl;
		else{
			int lost=len-1,ans=0;
			while(b[lost]==a[lost])lost--;
			for(int i=0;i<len;i++){
				int pos=1;
				for(int j=i;j<len;j++){
					pos=trie[pos].mp[h(a[j],b[j])];
					if(!pos)break;
					if(j>=lost)ans+=trie[pos].cnt;
				}if(a[i]!=b[i])break;
			}cout<<ans<<"\n";
		}
	}return 0;
}/*
luogu:sms123
orz kkksc03,chen_zhe,Alex_Wei...

IIIIIIIIII          WW      WW     IIIIIIIIII     LL             LL        
    II              WW      WW         II         LL             LL
    II              WW  WW  WW         II         LL             LL
    II              WW  WW  WW         II         LL             LL
    II              WW  WW  WW         II         LL             LL
    II              WWWW  WWWW         II         LL             LL
IIIIIIIIII          WW      WW     IIIIIIIIII     LLLLLLLLLL     LLLLLLLLLL


    AA         KK      KK          IIIIIIIIII       OOOOOO       IIIIIIIIII     !!
  AA  AA       KK    KK                II         OO      OO         II         !!
AA      AA     KK  KK                  II         OO      OO         II         !!
AA      AA     KKKK                    II         OO      OO         II         !!
AA      AA     KK  KK                  II         OO      OO         II         !!
AAAAAAAAAA     KK    KK                II         OO      OO         II
AA      AA     KK      KK          IIIIIIIIII       OOOOOO       IIIIIIIIII     !!


RRRRRRRR       PPPPPPPP
RR      RR     PP      PP         ++             ++
RR      RR     PP      PP         ++             ++
RRRRRRRR       PPPPPPPP       ++++++++++     ++++++++++
RR  RR         PP                 ++             ++
RR    RR       PP                 ++             ++
RR      RR     PP

long long int rp = 0;
int main()
{
	while (1) rp++;
	return 0;
}

PLEASE DO NOT
//freopen
feropen
freeopen
freopen("",r,stdin);
freopen("","r",stdout);
freopen("","r",stdin);
*/