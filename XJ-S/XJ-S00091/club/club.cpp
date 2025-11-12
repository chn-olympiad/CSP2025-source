#include<iostream>
#include<algorithm> 
#include<cstring>
#include<queue>
#define int long long
using namespace std;
const int N = 1e5 +10;
inline int read(){
    int f =  1,x = 0;
    char ch = getchar();
    while(!isdigit(ch)){
        if(ch == '-') f *= -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return f * x;
}
void write(int x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9){
        write(x / 10);
    }
    putchar(x % 10);
}
int T,n;
int ans;
int tong[4];
struct st{
    int x,id;
    bool operator<(const st& other) const {
        return x > other.x;
    }
}; 
struct node{
    st s[4]; 
}p[N];
bool cmp(st x,st y){
	return x.x > y.x;
}
void init(int n){
    for(int i=1;i<=3;++i){
        tong[i] = 0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=3;++j){
            p[i].s[j].x = 0;
            p[i].s[j].id = 0;
        }
    }
    ans = 0;
}

int tmp;
void dfs(int x){
    for(int i=1;i<=3;++i){
        if(tong[i] < n/2 && x != n+1){
            tong[i] ++;
            tmp += p[x].s[i].x;
            dfs(x+1);
           
            ans = max(ans,tmp);
            tmp -= p[x].s[i].x;
            tong[i] --;
        }
        
    }
}
int sp[N];
bool cmp1(int x,int y){
    return x > y;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T = read();
    while(T --){
        n = read();
        init(n);
        bool f = true;
        for(int i=1;i<=n;++i){
            p[i].s[1].x = read(),p[i].s[1].id = 1;
            p[i].s[2].x = read(),p[i].s[2].id = 2;
            p[i].s[3].x = read(),p[i].s[3].id = 3;
            sort(p[i].s + 1,p[i].s + 3 ,cmp);
            if(p[i].s[2].x != 0 || p[i].s[3].x != 0) f = false;
        }
        if(f){
            for(int i=1;i<=n;++i){
                sp[i] = p[i].s[1].x;
            }
            sort(sp+1,sp+n+1,cmp1);
            for(int i=1;i<=n/2;++i){
                ans += sp[i];
            }
            cout << ans << endl;
            return 0;
        }
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}