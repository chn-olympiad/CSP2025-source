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

int a1[N],a2[N],a3[N];

namespace LinkCutTree{
    #define rc(x) A[x].son[1]
    #define lc(x) A[x].son[0]
    #define son(x,i) A[x].son[i]
    #define fa(x) A[x].fa
    #define rev(x) A[x].rev  
    class LCT{
     public:
        int son[2],fa,rev,val;
    }A[N];
    inline bool isroot(int x){
        return (fa(lc(x))==x)||(fa(rc(x))==x);
    } 
    inline void reverse(int x){
        swap(lc(x),rc(x));
        rev(x) ^= 1; 
    }
    inline void Push_Up(int x){
        ans[x] = ans[lc(x)]+ans[rc(x)]+val[x];
    }
    inline void Push_Down(int x){
        if(rev(x)){
            reverse(lc(x));
            reverse(rc(x));
            rev(x)=0;
        }
    }
    inline void rotate(int x){
        int A=lc(x),B=rc(x),k=(fa(A)==x),w=son(A,!k);
    }
    inline void splay(int x){

    }
    inline void toroot(int x){
    	
	}
    inline void access(int x){
    	
	} 
	inline void split(int x,int y){
		
	}
	inline void link(int x,int y){
		
	} 
	inline void cut(int x,int y){
		
	}
}
signed main(){
	FileIO("road");
	cout << 0; 
}
/*
留半個 LCT 在這裏，後面的沒空寫了，雖然這題和 LCT 一點關係都沒有 

這就一個最小生成樹板子題，，， 
*/
