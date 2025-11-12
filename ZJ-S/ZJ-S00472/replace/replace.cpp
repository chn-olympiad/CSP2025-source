#include<bits/stdc++.h>
using namespace std;
#define int long long
const int base=313;
const int NM=2e5+10;
int n,q;
struct node{
	int s1,s2,len;
}a[NM];
int delta[NM];
const int N=5e6+10;
char ch1[N],ch2[N];
int p[N];

int gethash1(){
	int hash=0;
	int n=strlen(ch1+1);
	for(int i=1;i<=n;i++)hash=hash*base+ch1[i]-'a'+1;
	return hash;
}
int gethash2(){
	int hash=0;
	int n=strlen(ch2+1);
	for(int i=1;i<=n;i++)hash=hash*base+ch2[i]-'a'+1;
	return hash;
}

void init(){for(int i=1;i<=N-1;i++)p[i]=p[i-1]*base;}
char t1[N],t2[N];
int h1[N],h2[N];
int cutt(int L,int R){return h1[R]-h1[L-1]*p[R-L+1];}

void solveA(){
	cin>>(t1+1)>>(t2+1);
	int tlen=strlen(t1+1);
	for(int i=1;i<=tlen;i++){
		h1[i]=h1[i-1]*base+t1[i]-'a'+1;
		h2[i]=h2[i-1]*base+t2[i]-'a'+1;
	}
}
int Len=0;
void solvee(){
	int pos1=0,pos2=0;
	for(int i=1;i<=Len;i++){
		if(t1[i]=='b')pos1=i;
		if(t2[i]=='b')pos2=i;
	}
	int ans=0;
	int tt=pos2-pos1;
//	cout<<"tt:"<<tt<<endl;
	for(int i=1;i<=n;i++){
		bool f=0;
		if(tt<0 and delta[i]>0)continue;
		if(tt>0 and delta[i]<0)continue;
//		cout<<"now:"<<i<<' '<<delta[i]<<endl;
		for(int j=1;j+a[i].len-1<=Len;j++){
//			cout<<"scaning:"<<j<<' '<<j+a[i].len-1<<endl;
			if(cutt(j,j+a[i].len-1)==a[i].s1)f=1;
//			if(cutt(j,j+a[i].len-1)!=1 and cutt(j,j+a[i].len-1)!=0){
//				cout<<"not 1or0:"<<cutt(j,j+a[i].len-1)<<endl;
//			}
		}
		if(f==1){
//			cout<<"checking!"<<tt<<' '<<delta[i]<<endl;
			if(tt<0 and delta[i]<0){if((-tt)%(-delta[i])==0)ans++};
			else if(tt%delta[i]==0)ans++;
		}
	}
	cout<<ans<<endl;
}

void solveB(){
	for(int i=1;i<=q;i++){
		cin>>(t1+1)>>(t2+1);
		Len=strlen(t1+1);
//		cout<<"Len:"<<Len<<endl;
		memset(h1,0,sizeof h1);
		memset(h2,0,sizeof h2);
		for(int j=1;j<=Len;j++){
			h1[j]=h1[j-1]*base+t1[j]-'a'+1;
			h2[j]=h2[j-1]*base+t2[j]-'a'+1;
		}
		solvee();
	}
}



void predo(){
	
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>(ch1+1);
		a[i].s1=gethash1();
		cin>>(ch2+1);
		a[i].s2=gethash2();
		a[i].len=strlen(ch1+1);
		int pos1=0,pos2=0;
		for(int j=1;j<=a[i].len;j++){
			if(pos1 and ch1[j]=='b'){
				pos1=1000000;
				pos2=-1;
				break;
			}
			if(pos2 and ch2[j]=='b'){
				pos1=1000000;
				pos2=-1;
				break;
			}
			if(ch1[j]=='b')pos1=j;
			if(ch2[j]=='b')pos2=j;
		}
		if(pos2==0 and pos1==0)delta[i]=1000000;
		delta[i]=pos2-pos1;
	}
	if(q==1){
		solveA();
	}else{
		solveB();
	}
	
	/*
	我是真写不出来了，今年的题目怎么出的这么邪门啊。
	练的全部都没有考到，我明明所有模拟赛都有200pts++的，为什么今天只能疯狂骗分啊？
	为什么今年的CSP好像每道题目都有绿+~蓝啊？
	怎么会这么难写（生气）
	考完去luogu上一看发现清一色蓝题我就老实了
	现在的状态是T1没切出来，T2没切出来，T3彻底疯狂
	我考啥啊考，最后一年AFO了，还是没能有好结果
	我的所有练习全都在四个小时里面白费了
	好绝望，NOIP会不会良心一点啊？
	为什么今年这么抽象这么抽象，我真不理解，为什么大家好像都会写的样子？
	会不会是因为我昨天晚上一点钟睡没睡好
	才导致现在这副样子的
	我明明喝了四瓶咖啡续命，但是这个题目在我眼里就是好难啊
	为什么为什么为什么为什么为什么。 
	*/
}
