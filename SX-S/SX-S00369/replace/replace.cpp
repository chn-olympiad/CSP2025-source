#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
const double eps=1e-12;
const int N=1e6+10;
const ull mod=998244353;
#define ul u<<1
#define ur u<<1|1
#define first fi
#define second se
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
struct str{
    int l,r,len;
}dirt[N];
vector<ull> t[2],s[200100][2];
ull p[N],tmp[N],tmp2[N];
int n,q;
ull hsh(int l,int r,vector<ull> h){
    return h[r]-h[l-1]*p[r-l+1];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    p[0]=1;
    for(int i=1;i<200010;i++){
        p[i]=p[i-1]*mod;
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        int ls=s1.size();
        s1=" "+s1;s2=" "+s2;
        s[i][0].push_back(0);s[i][1].push_back(0);
        for(int j=1;j<=ls;j++){
            tmp[j]=tmp[j-1]*mod+s1[j];
            tmp2[j]=tmp2[j-1]*mod+s2[j];           
        }
        for(int j=1;j<=ls;j++){
            s[i][0].push_back(tmp[j]);
            s[i][1].push_back(tmp2[j]);
        }
        s1+='*';s2+='*';
        for(int j=1;j<=ls+1;j++){
            //cout<<s1[j]<<" "<<s2[j]<<"\n";
            if(s1[j]!=s2[j]&&!dirt[i].l){
                dirt[i].l=j;
            }
            if((s1[j]==s2[j]&&dirt[i].l&&!dirt[i].r)){
                dirt[i].r=j-1;
            }
        }
        dirt[i].len=ls;
        //cout<<"h1:"<<hsh(dirt[i].l,dirt[i].r,s[i][0])<<" h2:"<<hsh(dirt[i].l,dirt[i].r,s[i][1])<<"\n";
        //printf("sl:%d sr:%d dilen:%d\n",dirt[i].l,dirt[i].r,dirt[i].len);
    }
    for(int i=1;i<=n;i++){
        
    }
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        if(s1.size()!=s2.size()){
            printf("0\n");
            continue;
        }
        int lt=s1.size();
        s1=" "+s1;s2=" "+s2;
        for(int i=1;i<=lt;i++){
            tmp[i]=tmp[i-1]*mod+s1[i];
            tmp2[i]=tmp2[i-1]*mod+s2[i];
        }
        t[0].push_back(0);t[1].push_back(0);
        for(int i=1;i<=lt;i++){
            t[0].push_back(tmp[i]);
            t[1].push_back(tmp2[i]);
        }
        int tl=0,tr=0;
        s1+='*';s2+='*';
        for(int i=1;i<=lt+1;i++){
            if(s1[i]!=s2[i]&&!tl){
                tl=i;
            }
            if(s1[i]==s2[i]&&tl&&!tr){
                tr=i-1;
            }
        }
        //printf("tl:%d tr:%d dilen:%d\n",tl,tr,lt);
        int sum=0;
        //cout<<s1<<" "<<s2<<"\n";
        for(int i=1;i<=n;i++){
            int sl=dirt[i].l,sr=dirt[i].r,ls=dirt[i].len;
            //printf("id:%d sl:%d sr:%d tl:%d tr:%d\n",i,sl,sr,tl,tr);
            if(sr-sl!=tr-tl){
                continue;
            }
            //cout<<i<<" "<<hsh(tl,tr,t[0])<<" "<<hsh(sl,sr,s[i][0])<<" ";
            //cout<<hsh(tl,tr,t[1])<<" "<<hsh(sl,sr,s[i][1])<<"\n";
            if(hsh(tl,tr,t[0])!=hsh(sl,sr,s[i][0])||hsh(tl,tr,t[1])!=hsh(sl,sr,s[i][1])){
                continue;
            }
            if(hsh(tl-sl+1,tr+ls-sr,t[0])==hsh(1,ls,s[i][0])&&hsh(tl-sl+1,tr+ls-sr,t[1])==hsh(1,ls,s[i][1])){
                sum++;
            }
        }
        printf("%d\n",sum);
        t[0].clear();t[1].clear();
    }
	return 0;
}