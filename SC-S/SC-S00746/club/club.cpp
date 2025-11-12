#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n;
int m[N][5];
struct Node{
	int maxx=0,s_maxx=0,num;
	
}maxn[N],mx[N],s_mx[N];
bool cmp(Node x,Node y){// 最大值正序最大 
	return x.maxx>y.maxx;
}
bool cmp2(Node x,Node y){
	return x.s_maxx>y.s_maxx;//次大值正序最大 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		map<int,int> vis;
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>m[i][1]>>m[i][2]>>m[i][3];
			maxn[i].num=i;
			maxn[i].maxx=max({m[i][1],m[i][2],m[i][3]});//最大值 
			maxn[i].s_maxx=min({max(m[i][1],m[i][2]),max(m[i][2],m[i][3]),max(m[i][1],m[i][3])});//次大值 
		}
		int num[5];
		for(int i=1;i<=n;i++){//计算每列最大值的个数
			for(int j=1;j<=3;j++) 
			if(maxn[i].maxx==m[i][j]) num[j]++;
		}
		for(int i=1;i<=3;i++){ 
			if(num[i]<=n/2){// 如果该列最大值未超出要求 则直接加入
			for(int j=1;j<=n;j++){
					if(maxn[j].maxx==m[j][i]){
						ans+=m[j][i];
						vis[j]=1;// 将此成员标记为已选 
					}
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){// 若没有被选 则说明该位置需要筛选 
				mx[++cnt]=maxn[i];// 最大值顺序 
				s_mx[cnt]=maxn[i];// 次大值顺序 
			}
		}
		sort(mx+1,mx+1+cnt,cmp);
		sort(s_mx+1,s_mx+cnt+1,cmp2);
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=cnt;j++){
//				cout<<mx[i].num<<"*"<<mx[i].maxx<<mx[i].s_maxx<<" "<<s_mx[j].num<<"*"<<s_mx[j].maxx<<s_mx[i].s_maxx<<"\n";
				if(vis[mx[i].num]||vis[s_mx[j].num]) continue;//如果有一个成员已经被选 则跳过 
				if(mx[i].num==s_mx[j].num) continue; //如果是同一个成员 也跳过 
//				cout<<<<" "<<<<endl;				
				ans+=max((mx[i].maxx+s_mx[j].s_maxx),(mx[i].s_maxx+s_mx[j].maxx));
				vis[mx[i].num]=vis[s_mx[j].num]=1;
				break;
			} 
		}cout<<ans<<"\n";
	}
	
	return 0;
}

