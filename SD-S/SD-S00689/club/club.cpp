/*luogu@Nahia uid:1199153
Genshin Impact uid:289015817
I love Nahida forever!*/
//锦瑟无端五十弦，一弦一柱思华年。 
#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(int i = a;i<=b;i++)
using namespace std;
int a[100005][4];
int mid(int x,int y,int z){
	int ccf[3] = {x,y,z};
	sort(ccf,ccf+3);
	return ccf[1];
}
struct node{
	int cha,id;
};
bool cmp(node x,node y){
	return x.cha>y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		ll ans = 0;
		scanf("%d",&n);
		vector<node> vc1,vc2,vc3;
		vc1.push_back({-1,-1});
		vc2.push_back({-1,-1});
		vc3.push_back({-1,-1});
		For(i,1,n){
			For(j,1,3) scanf("%d",&a[i][j]);
			ans+=max({a[i][1],a[i][2],a[i][3]});
		}
		For(i,1,n){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				vc1.push_back({a[i][1]-mid(a[i][1],a[i][2],a[i][3]),i});
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				vc2.push_back({a[i][2]-mid(a[i][1],a[i][2],a[i][3]),i});
			}
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				vc3.push_back({a[i][3]-mid(a[i][1],a[i][2],a[i][3]),i});
			}
		}
		if(vc1.size()-1>n/2){
			sort(vc1.begin(),vc1.end(),cmp);
			For(i,n/2,(int)vc1.size()-1){
				int j = vc1[i].id;
				ans = ans-a[j][1]+mid(a[j][1],a[j][2],a[j][3]);
			}
		}
		else if(vc2.size()-1>n/2){
			sort(vc2.begin(),vc2.end(),cmp);
			For(i,n/2,(int)vc2.size()-1){
				int j = vc2[i].id;
				ans = ans-a[j][2]+mid(a[j][1],a[j][2],a[j][3]);
			}
		}
		else if(vc3.size()-1>n/2){
			sort(vc3.begin(),vc3.end(),cmp);
			For(i,n/2,(int)vc3.size()-1){
				int j = vc3[i].id;
				ans = ans-a[j][3]+mid(a[j][1],a[j][2],a[j][3]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
//写错的的话就是我记错了QWQ 
/*你也在听吗 落单的孩子啊 别害怕 别害怕 黑夜不会太长 悬崖上的花 让我为你摘下 数一瓣 落一瓣 就少一朵忧伤*/
/*是你吗 在回家的路上 洒满月光点亮花蕊 是你吗 弹奏古老和弦 赶走梦魇伴我入睡
是你吗 将头顶的雨水 编织成蓝色的屋檐 约好了 等我们都长大再次遇见 追寻梦的蔓延*/ 
/*你眼眶超载的眼泪 乘客是绝望和心碎 我可以看见↑ 你忍住伤悲 那一双爱笑眼睛不适合皱眉*/ 
/*手心的蔷薇 刺伤而不自觉 你值得被疼爱 你懂我的期待*/ 
/*注：她指OI 
她值得被疼爱。可是，我什么时候真正疼爱过她呢？
whk像一只手，无情地把我们俩拨开 。*/ 
