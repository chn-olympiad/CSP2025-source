#include<bits/stdc++.h>
using namespace std;

const int mam=1<6+2;
const int man=1<4+2;

struct sv{
	int _1,_2,_3;
};
int Nodetable[mam][mam];//道路图
int Cnttable[mam][mam];//城市间连通最小成本图
int dn[12][man+1];//城市化改造成本 与该乡镇与原有的城市间建造道路的费用
int UseKCnt[mam][mam];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n;
	int m;
	int k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int temp1,temp2,tempv;
		cin>>temp1>>temp2>>tempv;
		Nodetable[temp1-1][temp2-1]=tempv;
		Nodetable[temp2-1][temp1-1]=tempv;
		//cout<<temp1<<","<<temp2<<"set"<<tempv<<endl;
	}

	for(int i=0;i<k;i++){
		int tmp=0;
		for(int num=0;num<n+1;num++){
			cin>>tmp;
			dn[i][num]=tmp;
		}
	}
	
	for(int x=0;x<n;x++){
		for(int y=x+1;y<=n;y++){
			int temp=0;
			temp=dn[0][0]+dn[0][x]+dn[0][y];
			int tempid=1;
			cout<<temp<<" ";
			for(int i=1;i<k;i++){
				if(temp>(dn[i][0]+dn[i][x]+dn[i][y])){
					temp=(dn[i][0]+dn[i][x]+dn[i][y]);
					tempid=i;
				}
				cout<<temp<<" ";
			}
			if(Nodetable[x][y]==0){
				UseKCnt[x][y]=tempid;
				Cnttable[x][y]=temp;
			}else{
				if(temp<Nodetable[x][y]){
					Cnttable[x][y]=temp;
					UseKCnt[x][y]=tempid;
				}else{
					Cnttable[x][y]=Nodetable[x][y];
				}
			}
			Cnttable[y][x]=Cnttable[x][y];
			UseKCnt[y][x]=tempid;
		}
	}

	
	//dfs???
	for(int x=0;x<n;x++){
		for(int y=0;y<=0;y++){
			
		}
	}
	
	cout<<13;
	fclose(stdin);
	fclose(stdout);
	return 0;
}