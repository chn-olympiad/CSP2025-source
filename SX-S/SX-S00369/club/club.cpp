#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
const double eps=1e-12;
const int N=1e6+10;
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
struct node{
    int b1,b2,b3;
    bool operator < (const node &x)const{
        return b1-max(b2,b3)>x.b1-max(x.b2,x.b3);
    }
}tmp[100011];
int cnt[4];
int c[3][N];
ll ans;
int n,d1[N],d2[N],d3[N];
/*bool cmp(int x,int y){
    return 
}*/
void solve(){
    n=read();
    ans=0;cnt[0]=cnt[1]=cnt[2]=0;
    for(int i=1;i<=n;i++){
        d1[i]=read();d2[i]=read();d3[i]=read();

    }
    for(int i=1;i<=n;i++){
        if(d1[i]>=max(d2[i],d3[i])){
            c[0][++cnt[0]]=i;
        }else if(d2[i]>=max(d1[i],d3[i])){
            c[1][++cnt[1]]=i;
        }else if(d3[i]>=max(d1[i],d2[i])){
            c[2][++cnt[2]]=i;
        }
    }
    //cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<"\n";
    if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2){
        for(int i=1;i<=n;i++){
            ans+=max(d1[i],max(d2[i],d3[i]));
        }
        printf("%lld\n",ans);
        return ;
    }
    for(int i=0;i<3;i++){
        if(cnt[i]>n/2){
            for(int j=1;j<=cnt[i];j++){
                if(i==0){
                    tmp[j]={d1[c[i][j]],d2[c[i][j]],d3[c[i][j]]};
                }else if(i==1){
                    tmp[j]={d2[c[i][j]],d1[c[i][j]],d3[c[i][j]]};
                }else if(i==2){
                    tmp[j]={d3[c[i][j]],d1[c[i][j]],d2[c[i][j]]};
                }
                //cout<<tmp[j].b1<<" "<<tmp[j].b2<<" "<<tmp[j].b3<<"\n";
                //printf("d1:%d d2:%d d3:%d\n",d1[i],d2[i],d3[i]);
            }
            sort(tmp+1,tmp+1+cnt[i]);
            for(int j=1;j<=cnt[i];j++){
                
            }
            for(int j=1;j<=n/2;j++){
                ans+=tmp[j].b1;
            }
            for(int j=n/2+1;j<=cnt[i];j++){
                ans+=max(tmp[j].b2,tmp[j].b3);
            }
        }else{
            for(int j=1;j<=cnt[i];j++){
                ans+=max(d1[c[i][j]],max(d2[c[i][j]],d3[c[i][j]]));
            }
        }
    }
    printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int T;T=read();
    while(T--){
        solve();
    }
	return 0;
}