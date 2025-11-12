#include<bits/stdc++.h>
// #define ll long long
// 保險起見還是注釋掉吧，，反正這題也不會溢出 
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
//const int Inf = LLONG_MAX;
const int Inf=INT_MAX; 

int a1[N],a2[N],a3[N];
int sum[N];

signed main(){
    FileIO("club");
	// -Wall 一直提醒我這裏有 warning，我不信 
	// NOI Linux 沒 CE 就是贏了 
	int T = read();
    while(T--){
        priority_queue<int> Que1,Que2,Que3;
        int n=read();
        int ans = 0;
        for_(i,1,n){
            a1[i]=read(),a2[i]=read(),a3[i]=read();
            if(a1[i] >= a2[i] && a1[i] >= a3[i]){
                Que1.push(-(a1[i]-max(a2[i],a3[i])));
                ans += a1[i];
            }
            if(a2[i] > a1[i] && a2[i] >= a3[i]){
                Que2.push(-(a2[i]-max(a1[i],a3[i])));
                ans += a2[i];
            }
            if(a3[i] > a1[i] && a3[i] > a2[i]){
                Que3.push(-(a3[i]-max(a1[i],a2[i])));
                ans += a3[i];
            }
        }
        if((int)Que1.size() > n/2){
            while((int)Que1.size() > n/2){
                ans += Que1.top();
                Que1.pop();
            }
        }
        if((int)Que2.size() > n/2){
            while((int)Que2.size() > n/2){
                ans += Que2.top();
                Que2.pop();
            }
        }
        if((int)Que3.size() > n/2){
            while((int)Que3.size() > n/2){
                ans += Que3.top();
                Que3.pop();
            }
        }
        Fwrite(ans);
        puts("");
    }
    exit(0);
}

/*
/然而我 不是神/
/不像 他們無所不能/

T1 

感觉是一个贪心啊，先考虑如果没有限制怎么做，就是直接把每个人都安排到其对应的最喜爱的部门即可

但是我们有不能超过 frac{n}{2} 的邪恶限制，我们可以对每个人都求出对不同部门的满意度的差距

对于人满的部门直接找到其选取的人中和另一个差值小的然后放到其他部门即可

复杂度单 log，期望得分 100pts

写了 30 分钟，写出来的不知道为什么过不去最后一个样例，很邪恶。

後面發現是忘記特判 a2 和 a3 相等，只判了 a1=a3 和 a1=a2，比較失敗

T2

最開始想了一個最短路做法，但是好像假了，很坏，需要研究一下怎麽做，而且不知道爲什麽輸入法變成繁體了，不會切回去，，

又仔細看了一下，我草，這是一個最小生成樹的板子，但是最小生成樹怎麽打啊，一下子忘掉了，完蛋完蛋完蛋完蛋

這題保齡了嗚啊，感覺一下子就完蛋了呢，，，如果沒 T2 的話我 WC 也基本沒機會了，翻盤嗎，我怎麽可能用 T3 和 T4 拿到接近 200 分啊，，，

QQ 群裏説的話似乎應驗了呢，，，如果連 WC 都去不了，我這段時間真的還有什麽意義嗎 

不知道，不想了，萬一呢，不過其實我已經知道結果了才是，

把思路留在這裏，先跑一邊最小生成樹，然後嘗試去建立每個城市 i 並對於每一條邊 x,y 都嘗試進行一次用 a_i,x + a_i,y 替換，然後和原本的去進行對比，複雜度 O(m log n+n^2k)

做法期望得分 100，自己期望得分 0

T3

我草，字符串

感覺這下是真的完蛋了，雖然能看出來是 dp 但是完全沒有思路

先考慮部分分吧，，，可是我部分分都沒有思路，，先看 T4 吧

期望得分 0

T4

寫了很多，最後似乎只有 1/2 的一個暴力是有用的，，，複雜度 O(n!) ，期望得分 8pts


算下來居然只有 108pts，雖然很大程度是因爲 T2 有做法沒想出來心態炸掉了導致後面題不想去想，但是事實就是 108pts

實際上 108pts 也沒有了，我完全不想去寫 T4 那點分數少得可憐的暴力，如果是 NOIP 可能還會有點興趣，不過 CSP 這 8 分不能讓我進 WC，6 級鈎我也本來就有了，似乎毫無意義呢

哈，那我到底，學了些什麽，我真的什麽都不會啊，，，

明明，絕對不應該只有這些分數的啊，，，恐怕在整個天津的高二裏都是倒數啊，，

我到底在做些什麽，，，無論是哪場模擬賽都沒有打出過這麽低的分數，，

最低的分數留給 CSP 了嘛，那我的 WC 夢又破碎了呢，明明去年都能只差一點拿到 WC 名額的呢...

哎，我還是不值得一個燦爛的結尾嗎

或許，還有 NOIP 一次機會？

/貪心的 我想 我想 生命 不該這樣/
/我想要太多太多 裝滿房子 歡樂自由 每刻每時/
/血淚痛苦 歸于價值 圓滿結局咫尺/
/我失去太多太多 散落如寫 滿狂言妄 語的廢紙/
/野火燒盡 春不複至 只是我佯裝不知/

考試前我還和別人說絕對補考 Tarjan 和最小生成樹，哈，居然考了

而我復習了 1e18 年的 LCT 和樹剖居然沒見到呢，

這是我賽前說批話的報應嗎？我想是的，不過也不止，或許我只是拿到了我應有的分數

/逃離 這奇怪定律 的方法/
/不知道啊/
/如果我能停止思考 不再説出錯誤跡象/
/一萬次重複實驗 能否保證這次 順利啓航/
/既然 壞事 縂會發生 把計劃在 搖籃裏扼殺/
/不存在 就不用付出代價了吧/

正睿的模擬賽，多校的模擬賽，LCA 營的模擬賽，甚至洛谷的模擬賽，打了一次又一次

分數真的從來沒有這麽低過，甚至我 vp 的聯合省選2025 Day1 都比這次的分數高

上一次這麽低還是聯合省選2024，，，

怎麽會這樣，還是不甘心，可是真的不記得，完全不記得最小生成樹怎麽打

我能想起 LCT 想起樹剖想起 FFT 想起主席樹可我爲什麽就是想不起最小生成樹，爲什麽啊，，

真的失去了所有的力氣呢，我還，真是失敗，在 0 容錯的 OI 中。

我不想學文化課，我想去找矩陣群去找 Mrkn 去找 gza 想去找很多很多人，可是我現在的實力，無論找誰也找不到吧。

最簡單的方法——去 WC——已經失敗了呢。

看著周圍頹廢蜘蛛紙牌和谷歌小恐龍的小朋友，不由得有些感慨，以前的我也是這樣吧，到現在我變成高二了，卻完全沒有高二應有的實力呢

留個 luogu uid 吧，萬一有人看到呢 uid：1000298，Vsinger_洛天依

不過估計也不會有人看，，

/平凡城市 平淡故事 平靜不成詩/
/光陰太短 悲傷太淺 不夠釀成酒/
/仄仄平平 脚步匆匆 春夏又秋冬/
/故事講給我 我來寫首歌 這應該會有用 歌聲帶你想起來/
/上山崗 上山崗 請同我 大聲唱/
/唱太陽 唱月亮 唱時光 唱成長/
/歌聲繞 歌聲長 繞過天高山水長/
/不做翅膀 也做個肩膀/
/朋友朋友朋朋友/
/上山崗 請聽我 大聲唱/
/唱悲傷 唱希望 唱時光 唱成長/
/不孤單 不孤單 就像流水繞青山/
/千山踏遍 更願你柔軟/
*/
