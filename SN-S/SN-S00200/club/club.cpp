#include<bits/stdc++.h>
using namespace std;
int px(int a,int b,int c){
	if(a>=b){
		if(a<c)return 31;
		else if(b>=c)return 12;
		else return 13;
	}
	else{
		if(b<c)return 32;
		else if(a>=c)return 21;
		else return 23;
	}
}
int opp=1,n,ans,anss[3],r[4][100005],p[4][100005][2],q[4]={1,1,1,1};
int main(){
	frepoen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>opp;
	while(opp--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>r[1][i]>>r[2][i]>>r[3][i];
			r[0][i]=px(r[1][i],r[2][i],r[3][i]);
			//cout<<r[0][i];
		}
		for(int i=1;i<=n;i++)
		{
			if(r[0][i]/10==1){
				p[1][q[1]][0]=i;
				//cout<<p[1][q[1]][0]<<",1,"<<q[1]<<" ";
				q[1]++;
			}
				if(r[0][i]/10==2){
				p[2][q[2]][0]=i;
				//cout<<p[2][q[2]][0]<<",2,"<<q[2]<<" ";
				q[2]++;
			}
				if(r[0][i]/10==3){p[3][q[3]][0]=i;
				//cout<<p[3][q[3]][0]<<",3,"<<q[3]<<" ";
				q[3]++;
			}
		}
		if(q[1]-1>(n/2)){//cout<<1<<endl;
			for(int i=1;i<q[1];i++)
			{
				p[1][i][1]=r[1][p[1][i][0]]-r[r[0][p[1][i][0]]%10][p[1][i][0]];
				//cout<<p[1][i][1]<<endl;
			}
			//cout<<n/2-q[1]+1<<"'";
			for(int i=1;i<q[1]-n/2;i++)
			{
				//cout<<"e";
				anss[1]=10003721;
				for(int j=1;j<q[1];j++)
				{
					//cout<<p[1][j][1]<<":"<<j<<":"<<p[1][j][0]<<endl;
					if(anss[1]>=p[1][j][1]&&p[1][j][0]!=0){
						anss[1]=p[1][j][1],anss[2]=j;
						//cout<<anss[1]<<":"<<anss[2]<<endl;
					}
				}
				p[r[0][p[1][anss[2]][0]]%10][q[r[0][p[1][anss[2]][0]]%10]][0]=p[1][anss[2]][0];
				q[r[0][p[1][anss[2]][0]]%10]++;
				p[1][anss[2]][0]=0;
			}
		}
		if(q[2]-1>(n/2)){//cout<<2<<endl;
			for(int i=1;i<=q[2];i++)
			{
				p[2][i][1]=r[2][p[2][i][0]]-r[r[0][p[2][i][0]]%10][p[2][i][0]];
			}
			for(int i=1;i<=q[2]-n/2;i++)
			{
				anss[1]=10003721;
				for(int j=1;j<=q[2];j++)
				{
					if(anss[1]>p[2][j][1]&&p[2][j][0]!=0)anss[1]=p[2][j][1],anss[2]=j;
				}
				p[r[0][p[2][anss[2]][0]]%10][q[r[0][p[2][anss[2]][0]]%10]][0]=p[2][anss[2]][0];
				q[r[0][p[2][anss[2]][0]]%10]++;
				p[2][anss[2]][0]=0;
			}
		}
		if(q[3]-1>(n/2)){//cout<<3<<endl;
			for(int i=1;i<=q[3];i++)
			{
				p[3][i][1]=r[3][p[3][i][0]]-r[r[0][p[3][i][0]]%10][p[3][i][0]];
			}
			for(int i=1;i<=q[3]-n/2;i++)
			{
				anss[1]=10003721;
				for(int j=1;j<=q[3];j++)
				{
					if(anss[1]>p[3][j][1]&&p[3][j][0]!=0)anss[1]=p[3][j][1],anss[2]=j;
				}
				p[r[0][p[3][anss[2]][0]]%10][q[r[0][p[3][anss[2]][0]]%10]][0]=p[3][anss[2]][0];
				q[r[0][p[3][anss[2]][0]]%10]++;
				p[3][anss[2]][0]=0;
			}
		}
		for(int j=1;j<q[1];j++)
		{
			//cout<<r[1][p[1][j][0]]<<" ";
			ans+=r[1][p[1][j][0]];
		}
		for(int j=1;j<q[2];j++)
		{
			//cout<<r[2][p[2][j][0]]<<" ";
			ans+=r[2][p[2][j][0]];
		}
		for(int j=1;j<q[3];j++)
		{
			//cout<<r[3][p[3][j][0]]<<" ";
			ans+=r[3][p[3][j][0]];
		}
		cout<<ans<<endl;
	}
	return 0;
}
