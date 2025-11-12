//10:10 AK
/*
CSP-J 2025 rp++
CSP-S 2025 rp++
************************
%%%
Vector_net Feather_moon WAWA_OVO zyx110824 not_exist
%%%
************************
%%% zhoukangyang %%%
%%% dengmingyang %%%
%%% liuhengxi %%%
************************
Hope
jinminjun shengtuyusen geshentan lijiayuan 
geyouyang zhengyichen
neng de dao hao de cheng ji
************************
Thank
lijian3256 guoziwei(yi jiu j) zhangshuang(zhe xie nian sheng shang pi shang le jia suo)
Hangzhou No.2 High Schoool BMH    Hangzhou No.2 High School   San Wei Su Yang
************************
shang shan ruo shui
************************
ji lv ru tie yi zhi ru gang
zhu xing yao tian ao hai qi hang
yu xiao po lang qi shi ru hong
ba ban tong xing shei yu zheng feng
tian jiao jiu lian wu xian zhui qiu
yong wang zhi qian zheng chuang yi liu
************************
chang chu ni de re qing shen chu ni shuang shou
rang wo yong bao zhe ni de meng
rang wo yong you ni zheng xin de mian kong
rang wo men de xiao rong chong man zhe qing chun de jiao ao
rang wo men qi dai ming tian hui geng hao
************************
2025 qu zhou oier will Ac or AK
************************
2023 hang shi da xia sha ZJ-J00338 100pts
2024 hang shi da cang qian qing yuan ZJ-J00424 255pts
2025 hang shi da cang qian shu yuan ZJ-J00373 ?pts
2025 hang shi da cang qian shu yuan ZJ-S00425 ?pts
************************
hang zhou shi fan da xue
cang qian xiao qu
shu yuan 16 hao lou
202B ji fang
li 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5100;
const int TT=998244353;
int n,ans,a[maxn];
void DFS(int x,int sum,int mx,int cnt){
	if(x>n){
		if(cnt>=3&&sum>2*mx)ans++;
		return;
	}
	DFS(x+1,sum,mx,cnt);
	DFS(x+1,sum+a[x],a[x],cnt+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon0.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	DFS(1,0,0,0);
	cout<<ans;
	return 0;
}

