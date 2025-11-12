#include<bits/stdc++.h>
using namespace std;
int to[2][10005][5];
int team[5][10005];
int wish[10005][5];
int t;
int n;
struct node{
	int num,tot,tot2;
}m[10005];
bool cmt(node a,node b){
	//cout<<"当前判断"<<a.num<<" "<<b.num<<endl; 
	//if(a.tot>a.tot2+b.tot) cout<<"1"<<endl;
	//else cout<<"0"<<endl;
	if(b.tot>a.tot) return a.tot<a.tot2+b.tot;
	else return a.tot>b.tot;
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int x=1;x<=t;++x){
		//cout<<endl<<"the "<<x<<" time"<<endl<<endl<<endl;
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				cin>>wish[i][j];
			}
			//cout<<wish[i][1]<<endl<<wish[i][2]<<endl<<wish[i][3]<<endl;
			if(wish[i][1]>=wish[i][2]&&wish[i][2]>=wish[i][3]){
			    to[1][i][1]=1; 
			    to[1][i][2]=2;
			    to[1][i][3]=3;
			    to[2][i][1]=wish[i][1];
			    to[2][i][2]=wish[i][2];
			    to[2][i][3]=wish[i][3];
			    //cout<<"role"<<endl;
			}
			if(wish[i][2]>=wish[i][1]&&wish[i][1]>=wish[i][3]){
			    to[1][i][1]=2; 
			    to[1][i][2]=1;
			    to[1][i][3]=3;
			    to[2][i][1]=wish[i][2];
			    to[2][i][2]=wish[i][1];
			    to[2][i][3]=wish[i][3];
				//cout<<"role"<<endl;
			}
			if(wish[i][1]>=wish[i][3]&&wish[i][3]>=wish[i][2]){
			    to[1][i][1]=1; 
			    to[1][i][2]=3;
			    to[1][i][3]=2;
			    to[2][i][1]=wish[i][1];
			    to[2][i][2]=wish[i][3];
			    to[2][i][3]=wish[i][2];
				//cout<<"role"<<endl;
			}
			if(wish[i][2]>=wish[i][3]&&wish[i][3]>=wish[i][1]){
			    to[1][i][1]=2; 
			    to[1][i][2]=3;
			    to[1][i][3]=1;
			    to[2][i][1]=wish[i][2];
			    to[2][i][2]=wish[i][3];
			    to[2][i][3]=wish[i][1];
				//cout<<"role"<<endl;
			}
			if(wish[i][3]>wish[i][2]&&wish[i][2]>wish[i][1]){
			    to[1][i][1]=3; 
			    to[1][i][2]=2;
			    to[1][i][3]=1;
			    to[2][i][1]=wish[i][3];
			    to[2][i][2]=wish[i][2];
			    to[2][i][3]=wish[i][1]; 
				//cout<<"role"<<endl;
			}
			if(wish[i][3]>=wish[i][1]&&wish[i][1]>=wish[i][2]){
			    to[1][i][1]=3; 
			    to[1][i][2]=1;
			    to[1][i][3]=2;
			    to[2][i][1]=wish[i][3];
			    to[2][i][2]=wish[i][1];
			    to[2][i][3]=wish[i][2]; 
				//cout<<"role"<<endl;
			}
			team[to[1][i][1]][i]++;
			//cout<<"example:first "<<to[1][i][1]<<" second "<<to[1][i][2]<<" third "<<to[1][i][3]<<endl;
		}
		for(int r=1;r<=3;++r){
			//cout<<"第"<<r<<"轮检测"<<endl;
			for(int i=1;i<=3;++i){
			//cout<<"club"<<i<<":"<<endl;
			int flagg=0;
			int cnt=0;
			for(int j=1;j<=n;++j){
				if(to[1][j][1]==i){
				flagg++;
				cnt++;
				m[cnt].num=j;
				m[cnt].tot=to[2][j][1];
				m[cnt].tot2=to[2][j][2];
				//cout<<m[cnt].num<<"的tot:  "<<m[cnt].tot<<endl;
				//cout<<m[cnt].num<<"的tot2:  "<<m[cnt].tot2<<endl;
				}
			}
			sort(m+1,m+cnt+1,cmt);
			//cout<<"team"<<i<<"guy:"<<flagg<<endl;
			if(flagg>n/2){
				//cout<<"N"<<endl;
				//sort(m+1,m+cnt+1,cmt);
				for(int j=1;j<=n/2;++j){
					//cout<<m[j].num<<"通过"<<endl;
					to[2][m[j].num][2]=-1;
					to[2][m[j].num][3]=-1;
				}
				for(int j=n/2+1;j<=cnt;++j){
					//cout<<m[j].num<<"未通过"<<endl;
					to[2][m[j].num][1]=to[2][m[j].num][2];
					to[2][m[j].num][2]=to[2][m[j].num][3];
					to[2][m[j].num][3]=-1;
					//cout<<"将"<<m[j].num<<"从"<<to[1][m[j].num][1]<<"转移至"<<to[1][m[j].num][2]<<endl;
					int slender=to[1][m[j].num][1];
					to[1][m[j].num][1]=to[1][m[j].num][2];
					to[1][m[j].num][2]=to[1][m[j].num][3];
					to[1][m[j].num][3]=slender;
				}
			}
		}
		}
		int res=0;
		for(int i=1;i<=n;++i){
			res+=to[2][i][1];
		}
		cout<<res<<endl;
	}
    return 0;
} 