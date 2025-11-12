#include<bits/stdc++.h>
#define int long long
#define for_(i,a,b) for(int i=a;i<=b;i++)
#define _for(i,a,b) for(int i=a;i>=b;i--)
#define For_(i,a,b,c) for(int i=a;i<=b;i+=c)
#define _For(i,a,b,c) for(int i=a;i>=b;i-=c)
#define fa(i,a) for(int i=head[a];i;i=nxt(a))
#define PII pair<int,int>
#define lowbit(x) ((x)&(-(x)))
#define mid(l,r) (((l)+(r))/2)
#define lc(q) ((q)*2)
#define rc(q) ((q)*2+1)
#define Filein(x) freopen(x".in","r",stdin)
#define Fileout(x) freopen(x".out","w",stdout)
#define FileIO(x) Filein(x),Fileout(x)
using namespace std;

namespace IO{
    inline int read(){
        int s=0,f=1;char ch=getchar();
        while('0'>ch||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
        while('0'<=ch&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
        return s*f;
    }
    inline void write(int x){
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
    inline void Fwrite(int x){
        if(x < 0) putchar('-');
        write(x<0?-x:x);
    }
}
using namespace IO;

const int N = 1e6+5;
const int Inf = LLONG_MAX;


namespace FFT{
	const int mod = 998244353;	
	const int Mod = 3;
	class compley{
	 public:
	 	
	}C;
	inline void FFT(compley *A){
		
	}
}

signed main(){
    FileIO("employ");
    cout << 0 << endl;
}

/*
求 NOIP 考好

CSP 沒考好，rp 能給我補到 NOIP 上嗎

這裏放一個 FFT 的空白 namespace 吧，雖然肯定用不到 
*/
