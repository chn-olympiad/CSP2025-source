#include<bits/stdc++.h>
#define sz size()
#define fs first
#define sc second
#define fst ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
long long ans=1;
int n,m,num=0;
string s;
int c[1100];
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	fst;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0) num++;
	}for(int i=2;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}cout<<ans;
	return 0;
}
/*
xian zai hai mei kai kao,wo jiu yi jing po bu ji dai de
xie xia le zhe duan zhushi

xian zai yi jing shi 18:04 le
wo de xin qing shi fen gou shi  
dao bu shi shuo wo zuo le yi dui gou shi 
(shi ji shang wo jiu shi zuo le yi tuo gou shi ,
dan wo de yi si shi wo bu shi yin wei wo zuo le yi tan gou shi xin qing bian gou shi de)
er shi yin wei wo fa zi fei fu xie le yida duan hua wang bao cun le
qi si wo le 
wo xian zai yao nai zhe xing zi hui xiang yi xia,zai xei xia lai:

wo mei nai xin xiang le 
fan zheng da gai jiu shi gan xie le yi dui ren 
ran hou jue de zhe ci kao ~120
ru guo wo you xing(xing yun de xing)qie you qing(qing xv de qing) wo hui zai NOIP hao hao zai xie yi bian

xi wang neng hun ge 3=

gan xie na ge zheng li mi huo xing wei da shang de ren 
ma fang ni ba zhe yi da duan wen zi xie cheng han zi
From luogu @Shiro_Zhu BCMS ZhuXi
ling : bi wo cai de bi wo qiang de gen wo shui ping cha bu duo de dou AK CSP
hai you ,wo bu xiang ding ge lv gou tui yi 
lai ge blue
blue
blue
blue
blue
blue
blue
blue
blue

dui le ,wo hai yao tu cao yi xia,wo de da zhou mei le .

hai you,zhe shi wo di yi ci da CSP-S
*/
//password: Ren5Jie4Di4Ling5%
