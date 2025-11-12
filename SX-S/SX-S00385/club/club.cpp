#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define lys long long
#define lys_ int

char ys[1<<21],*lys1=ys,*lys2=ys,ly[1<<21],*ls=ly,ly3[20];

char gc(){
//	return getchar();
    return (lys1==lys2&&(lys2=(lys1=ys)+fread(ys,1,1<<21,stdin),lys1==lys2)?EOF:*lys1++);
}

void pc(char x){
//	putchar(x);
//	return;
    (ls-ly<1<<21)?(*ls++=x):(fwrite(ly,ls-ly,1,stdout),ls=ly,*ls++=x);
    return;
}

struct io{
    ~io(){
        fwrite(ly,1,ls-ly,stdout);
    }
}_;

lys_ read(){
    lys_ x=0,F=1;
    char c='\0';
    while(c<'0'||c>'9'){
        c=gc();
        if(c=='-')F=-1;
    }
    while(c<='9'&&c>='0'){
        x=x*10+(c^48);
        c=gc();
    }
    return x*F;
}

void print(lys_ x){
    if(x==0){
        pc('0');
        return;
    }
    int l=0;
    if(x<0)x=-x,pc('-');
    while(x)ly3[l++]=x%10+48,x/=10;
    while(l--)pc(ly3[l]);
    return;
}

const int N = 100005;

int n;
int hn;

bool vis[N];

struct node{
    int a,b,c;
    int d[4];
}p[N];



int ans;

void solveB(){
//	int sum=0;
	int ans=0;
//	for(int i=1;i<=n;i++){
	std::sort(p+1,p+n+1,[](node a,node b){
        return a.d[3]==b.d[3]?(a.d[2]==b.d[2]?a.d[1]>b.d[1]:a.d[2]>b.d[2]):a.d[3]>b.d[3];
    });
	for(int i=1;i<=n;i++){
		int j=n-i+1;
		if(p[i].a+p[j].b>p[i].b+p[j].a){
			ans+=p[i].a+p[j].b;
		}
		else{
			ans+=p[i].b+p[j].a;
		}
	}
	print(ans);
	pc('\n');
	return;
}

int ass=0;

void dfs(int i,int as,int c1,int c2,int c3){
	if(i==n+1){
		ass=std::max(ass,as);
		return;
	}
	if(c1<hn)dfs(i+1,as+p[i].a,c1+1,c2,c3);
	if(c2<hn)dfs(i+1,as+p[i].b,c1,c2+1,c3);
	if(c3<hn)dfs(i+1,as+p[i].c,c1,c2+1,c3);
	return;
}

void solvebaoli(){
	ass=0;
	dfs(1,0,0,0,0);
	print(ass),pc('\n');
}

void solve(){
	bool flag=true;
    for(int i=0;i<=n;i++)vis[i]=0;
    ans=0;
    n=read();
    hn=n/2;
    for(int i=1;i<=n;i++){
        p[i].d[1]=p[i].a=read(),p[i].d[2]=p[i].b=read(),p[i].d[3]=p[i].c=read();
        std::sort(p[i].d+1,p[i].d+3+1);
        if(p[i].c!=0)flag=false;
    }
    if(n<=30){
//	print(1);
    	solvebaoli();
    	return;
	}
    if(flag){
    	solveB();
    	return;
	}
    std::sort(p+1,p+n+1,[](node a,node b){
        return a.d[3]==b.d[3]?(a.d[2]==b.d[2]?a.d[1]>b.d[1]:a.d[2]>b.d[2]):a.d[3]>b.d[3];
    });
    int cnta=0,cntb=0,cntc=0;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
		if(cnta<hn){
            if(p[i].a==p[i].d[3]){
                if(p[i].a==p[i].b&&p[i].a==p[i].c){
                    if(cntb<hn&&cntc<hn){
                        if(cntb<=cntc){
                            cntb++;
                            ans+=p[i].b;
                            vis[i]=true;
                            continue;
                        }
                        else{
                            cntc++;
                            ans+=p[i].c;
                            vis[i]=true;
                            continue;
                        }
                    }
                    else if(cntb<hn){
                        cntb++;
                        ans+=p[i].b;
                        vis[i]=true;
                        continue;
                    }
                    else if(cntc<hn){
                        cntc++;
                        ans+=p[i].c;
                        vis[i]=true;
                        continue;
                    }
                }
                if(p[i].a==p[i].b){
                    if(cntb<hn){
                        if(cntb<cnta){
                            cntb++;
                            ans+=p[i].b;
                            vis[i]=true;
                            continue;
                        }
                    }
                }
                if(p[i].a==p[i].c){
                    if(cntc<hn){
                        if(cntc<cnta){
                            cntc++;
                            ans+=p[i].c;
                            vis[i]=true;
                            continue;
                        }
                    }
                }
                cnta++;
                ans+=p[i].a;
                vis[i]=true;
                continue;
            }
        }
        if(cntb<hn){
            if(p[i].b==p[i].d[3]){
                if(cntc<hn){
                    if(p[i].b==p[i].c){
                        if(cntc<cntb){
                            cntc++;
                            ans+=p[i].c;
                            vis[i]=true;
                            continue;
                        }
                    }
                }
                cntb++;
                ans+=p[i].b;
                vis[i]=true;
                continue;
            }
        }
        if(cntc<hn){
            if(p[i].c==p[i].d[3]){
                cntc++;
                ans+=p[i].c;
                vis[i]=true;
                continue;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        if(cnta<hn){
            if(p[i].a==p[i].d[2]){
                if(p[i].a==p[i].b&&p[i].a==p[i].c){
                    if(cntb<hn&&cntc<hn){
                        if(cntb<=cntc){
                            cntb++;
                            ans+=p[i].b;
                            vis[i]=true;
                            continue;
                        }
                        else{
                            cntc++;
                            ans+=p[i].c;
                            vis[i]=true;
                            continue;
                        }
                    }
                    else if(cntb<hn){
                        cntb++;
                        ans+=p[i].b;
                        vis[i]=true;
                        continue;
                    }
                    else if(cntc<hn){
                        cntc++;
                        ans+=p[i].c;
                        vis[i]=true;
                        continue;
                    }
                }
                if(p[i].a==p[i].b){
                    if(cntb<hn){
                        if(cntb<cnta){
                            cntb++;
                            ans+=p[i].b;
                            vis[i]=true;
                            continue;
                        }
                    }
                }
                if(p[i].a==p[i].c){
                    if(cntc<hn){
                        if(cntc<cnta){
                            cntc++;
                            ans+=p[i].c;
                            vis[i]=true;
                            continue;
                        }
                    }
                }
                cnta++;
                ans+=p[i].a;
                vis[i]=true;
                continue;
            }
        }
        if(cntb<hn){
            if(p[i].b==p[i].d[2]){
                if(cntc<hn){
                    if(p[i].b==p[i].c){
                        if(cntc<cntb){
                            cntc++;
                            ans+=p[i].c;
                            vis[i]=true;
                            continue;
                        }
                    }
                }
                cntb++;
                ans+=p[i].b;
                vis[i]=true;
                continue;
            }
        }
        if(cntc<hn){
            if(p[i].c==p[i].d[2]){
                cntc++;
                ans+=p[i].c;
                vis[i]=true;
                continue;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        if(cnta<hn){
            if(p[i].a==p[i].d[1]){
                if(p[i].a==p[i].b&&p[i].a==p[i].c){
                    if(cntb<hn&&cntc<hn){
                        if(cntb<=cntc){
                            cntb++;
                            ans+=p[i].b;
                            vis[i]=true;
                            continue;
                        }
                        else{
                            cntc++;
                            ans+=p[i].c;
                            vis[i]=true;
                            continue;
                        }
                    }
                    else if(cntb<hn){
                        cntb++;
                        ans+=p[i].b;
                        vis[i]=true;
                        continue;
                    }
                    else if(cntc<hn){
                        cntc++;
                        ans+=p[i].c;
                        vis[i]=true;
                        continue;
                    }
                }
                if(p[i].a==p[i].b){
                    if(cntb<hn){
                        if(cntb<cnta){
                            cntb++;
                            ans+=p[i].b;
                            vis[i]=true;
                            continue;
                        }
                    }
                }
                if(p[i].a==p[i].c){
                    if(cntc<hn){
                        if(cntc<cnta){
                            cntc++;
                            ans+=p[i].c;
                            vis[i]=true;
                            continue;
                        }
                    }
                }
                cnta++;
                ans+=p[i].a;
                vis[i]=true;
                continue;
            }
        }
        if(cntb<hn){
            if(p[i].b==p[i].d[1]){
                if(cntc<hn){
                    if(p[i].b==p[i].c){
                        if(cntc<cntb){
                            cntc++;
                            ans+=p[i].c;
                            vis[i]=true;
                            continue;
                        }
                    }
                }
                cntb++;
                ans+=p[i].b;
                vis[i]=true;
                continue;
            }
        }
        if(cntc<hn){
            if(p[i].c==p[i].d[1]){
                cntc++;
                ans+=p[i].c;
                vis[i]=true;
                continue;
            }
        }
    }
    print(ans);
    pc('\n');
    return;
}

int T;
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    T=read();

    while(T--){
        solve();
    }
    return 0;
}

/*
《Base64人》

5Yqq5Yqb5oiQ5Li655CG56eR5aSnWe55qE56ys5LiJ55m+5Lmd5YZB5YWr5aSp77yB77yB77yB
x6b6Z5aaN5p2J77yM5oiR54i5l2g

*/