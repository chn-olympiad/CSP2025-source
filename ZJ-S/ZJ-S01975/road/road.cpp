#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

long long n,m,k,sum;
long long x,y,z,vi[100050],flag[100050],amin[100050],bmin,cmin;

struct Edge{
	long long to,cost;
};
vector<Edge> v[100050];

long long Read(){
	long long Ra=0,Rf=1;
	char Rc=getchar();
	while(Rc<'0'||Rc>'9'){
		if(Rc=='-') Rf=-1;
		Rc=getchar();
	}
	while(Rc>='0'&&Rc<='9'){
		Ra=(Ra<<1)+(Ra<<3)+(Rc&15);
		Rc=getchar();
	}
	return Ra*Rf;
}int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//k=0,O(n^2) 16
	n=Read(),m=Read(),k=Read();
	for(int i=1;i<=m;i++){
		x=Read(),y=Read(),z=Read();
		v[x].push_back({y,z});
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			vi[j]=Read();
		}
	}
	memset(amin,0x3f,sizeof(amin));
	flag[1]=1;
	for(int i=0;i<v[1].size();i++){
		amin[v[1][i].to]=min(amin[v[1][i].to],v[1][i].cost);
	}
	for(int i=1;i<n;i++){
		bmin=9999999999;
		for(int j=1;j<=n;j++){
			if(flag[j]==0&&amin[j]<bmin){
				bmin=amin[j];
				cmin=j;
			}
		}
		flag[cmin]=1;
		sum+=bmin;
		for(int j=0;j<v[cmin].size();j++){
			amin[v[cmin][j].to]=min(amin[v[cmin][j].to],v[cmin][j].cost);
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
