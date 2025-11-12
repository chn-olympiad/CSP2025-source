//1h10min 拿到了 172pts，不知道是题简单了还是人变强了
//我说实话，T2剩下的 28pts 性价比不是很高，不如打打其他的暴力 
//难绷的来了，T3 50pts 也是简单的，这下成为部分分大神了 
//好吧细节有点多，但是为了不参加期中考试，我一定要调出来口牙！！！ 
//T2 72pts 这么简单分数线一定会上涨，但上了200pts应该就是稳过吧，冲刺！！！ 
//写题的时候想到的冷笑话：Q：SabbatoftheWitch 告诉了我们什么？ A：现充死妈 
//考虑到 B 性质是二维偏序可能会调一会所以先看看T4有没有sb部分分 
//freopen 召唤神兽！ 
//T4 25pts 调完了，调的时候犯唐了导致还剩 23min 给我打 B 性质 
//好的不出意外没调完 
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace kong{bool st;}
namespace zhu{
const int p=13331,mod=998244353;
int n,q,hs1[200200],hs0[200200],pw[200200],ht0[200200],ht1[200200],ans[200200];
string s[200200][2],t[2];
//struct zxc{
//	int l,r,op,id;
//};
//vector<zxc> v[2002000];
//int tr[2002000];
//#define lbt(x) (x&-x)
//void add(int x,int y){
//	while(x){
//		tr[x]+=y;
//		x-=lbt(x);
//	}
//}
//int sum(int x){
//	int ans=0;
//	while(x<=2000000){
//		ans+=tr[x];
//		x+=lbt(x);
//	}
//	return ans;
//}
string main(){
//	system("fc my.out replace3.ans");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
//	int flag=1;
	pw[0]=1;
	for(int i=1;i<=2000;i++){
		pw[i]=pw[i-1]*p%mod;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		int len=s[i][0].size();
//		int cnt=0,cct=0;
		for(int j=0;j<len;j++){
//			if(s[i][0][j]=='b'){
//				cnt++;
//			}
//			else if(s[i][0][j]!='a'){
//				flag=0;
//			}
//			if(s[i][1][j]=='b'){
//				cct++;
//			}
//			else if(s[i][1][j]!='a'){
//				flag=0;
//			}
			hs0[i]=(hs0[i]*p+s[i][0][j])%mod;
			hs1[i]=(hs1[i]*p+s[i][1][j])%mod;
		}
//		if(cnt>1||cct>1) flag=0;
	}
//	if(flag){
////		cerr<<"in\n";
//		for(int i=1;i<=n;i++){
//			int b0=0,b1=0,len=s[i][0].size();
//			for(int j=0;j<len;j++){
//				if(s[i][0][j]=='b'){
//					b0=j;
//				}
//				if(s[i][1][j]=='b'){
//					b1=j;
//				}
//			}
//			v[b0-b1+1000000].push_back({min(b0,b1)-1,len-1-max(b0,b1),0,0});
//		}
//		for(int i=1;i<=q;i++){
//			cin>>t[0]>>t[1];
//			int b0=0,b1=0,len=t[0].size();
//			for(int j=0;j<len;j++){
//				if(t[0][j]=='b'){
//					b0=j;
//				}
//				if(t[1][j]=='b'){
//					b1=j;
//				}
//			}
//			v[b0-b1+1000000].push_back({min(b0,b1)-1,len-1-max(b0,b1),1,i});
//		}
//		for(int i=0;i<=2000000;i++){
//			sort(v[i].begin(),v[i].end(),[](zxc x,zxc y){
//				return x.l<y.l;
//			});
//			for(auto x:v[i]){
//				int r=x.r,opt=x.op,id=x.id;
//				if(opt){
//					ans[id]=sum(r);
//				}
//				else{
//					add(r,1);
//				}
//			}
//			for(auto x:v[i]){
//				int r=x.r,opt=x.op,id=x.id;
//				if(opt){}
//				else{
//					add(r,-1);
//				}
//			}
//		}
//		for(int i=1;i<=q;i++){
//			cout<<ans[i]<<"\n";
//		}
//		return "S组只是NOIP的试机赛！";
//	}
	for(int i=1;i<=q;i++){
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<0<<'\n';
			continue;
		}
		int lent=t[0].size();
		int ans=0,l=lent,r=0;
		ht0[0]=t[0][0];
		ht1[0]=t[1][0];
		if(t[0][0]!=t[1][0]){
			l=min(l,0ll);r=max(r,0ll);
		}
		for(int i=1;i<lent;i++){
			ht0[i]=(ht0[i-1]*p+t[0][i])%mod;
			ht1[i]=(ht1[i-1]*p+t[1][i])%mod;
			if(t[0][i]!=t[1][i]){
				l=min(l,i);r=max(r,i);
			}
		}
//		cout<<ht1[lent-1]<<'\n';
		for(int j=1;j<=n;j++){
			int lens=s[j][0].size();
			for(int k=0;k+lens-1<lent;k++){
//				cout<<i<<" "<<j<<' '<<k<<"\n";
//				cout<<(ht0[k+lens-1]-(k?ht0[k-1]*pw[lens]%mod:0)+mod)%mod<<' '<<hs0[j]<<'\n';
//				cout<<(ht1[k+lens-1]-(k?ht1[k-1]*pw[lens]%mod:0)+mod)%mod<<" "<<hs1[j]<<'\n';
//				cout<<k<<" "<<k+lens-1<<" "<<l<<" "<<r<<'\n';
				if((ht0[k+lens-1]-(k?ht0[k-1]*pw[lens]%mod:0)+mod)%mod==hs0[j]&&
				   (ht1[k+lens-1]-(k?ht1[k-1]*pw[lens]%mod:0)+mod)%mod==hs1[j]&&
				   k<=l&&k+lens-1>=r){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return "S组只是NOIP的试机赛！";
}
}
namespace kong{bool ed;double MB(){return (&st-&ed)/1048576.0;}}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cerr<<zhu::main()<<'\n'<<kong::MB();
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
