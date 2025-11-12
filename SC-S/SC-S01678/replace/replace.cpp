#include<cstdio>
#include<cstring>
using namespace std;
int n,q;
typedef unsigned long long llu;
typedef long long ll;
const int MAXN=2e5+10;
const llu bas=251;
char s[3][MAXN];
int len[MAXN],l;
llu pw[MAXN],hs[MAXN][3],pre[MAXN][3];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    pw[0]=1;
    for(int i=1;i<=200000;++i) pw[i]=pw[i-1]*bas;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
    {
        scanf("%s",s[1]+1);
        scanf("%s",s[2]+1);
        len[i]=strlen(s[1]+1);
        for(int j=1;j<=len[i];++j) hs[i][1]+=llu(s[1][j]-'a'+1)*pw[j],hs[i][2]+=llu(s[2][j]-'a'+1)*pw[j];
    }
    while(q--)
    {
        scanf("%s",s[1]+1);
        scanf("%s",s[2]+1);
        l=strlen(s[1]+1);
        int ans=0;
        for(int j=1;j<=l;++j) pre[j][1]=pre[j-1][1]+(s[1][j]-'a'+1)*pw[j],pre[j][2]=pre[j-1][2]+(s[2][j]-'a'+1)*pw[j];
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j+len[i]-1<=l;++j)
            {
                if(((pre[j+len[i]-1][1]-pre[j-1][1])==(hs[i][1]*pw[j-1]))&&(pre[j+len[i]-1][2]-pre[j-1][2]==hs[i][2]*pw[j-1])&&(pre[j-1][1]==pre[j-1][2])&&(pre[l][1]-pre[j+len[i]-1][1]==pre[l][2]-pre[j+len[i]-1][2])) ans++;
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}