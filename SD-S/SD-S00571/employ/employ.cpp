#include<bits/stdc++.h>//T4
//Ren5Jie4Di4Ling5%
using namespace std;
int n,m;
long long ans=0;
char s[505];
int nd[505],fq;//难度  放弃难度 
int h[505],e[505],ne[505],idx=0;//不同难度对应放弃编号 
int fl[505];//是否放弃或已参赛 
int fn=0;//初始放弃人数 
int lin(int nn,int bh)
{
	ne[++idx]=h[nn];
	h[nn]=idx;
	e[idx]=bh;
}
int dfs(int num1,int num2,int la,int d)//通过个数 放弃或落选个数  上一个  这是第几天结束后的状态 
{
	//cout<<"^&"<<fl[1];
	//cout<<"&";cout<<num1<<" "<<num2<<" "<<la<<" "<<d<<endl;
	
	int flag=1;
	int ll=num2;
	if(d>n)return 0;
	int aaa[505],idxx=0;

	for(int j=la;j<=ll;j++)
	{
		int c=h[j];
		while(c)
		{
			
			if(fl[e[c]]==0)
			{
				fl[e[c]]=1;
				aaa[++idxx]=e[c];
			}
			c=ne[c];
			num2++;
		}
	
	}
	//cout<<"@#$"<<fl[1];
	for(int j=1;j<=n;j++)
	{
		if(fl[j]==0);
		{
			//cout<<j<<"#$";
			flag=0;
			fl[j]=1;
			if(nd[d+1]==1)dfs(num1+1,num2,ll,d+1);
			else dfs(num1,num2+1,ll,d+1);
			fl[j]=0;
		}
	}
	if(flag&&num1>=m)ans=(ans+1)%998244353;
	
	
	
	for(int i=1;i<=idxx;i++)fl[aaa[i]]=0;
		
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)if(s[i]=='1')nd[i+1]=1;	
	for(int i=1;i<=n;i++)
	{
		cin>>fq;
		lin(fq,i);
	}
	
	//for(int i=1;i<=n;i++)cout<<h[i]<<" ";
	//for(int i=1;i<=n;i++)cout<<e[i]<<" "<<ne[i]<<"     ";
	
	fn=0;
	for(int j=0;j<=0;j++)
	{
		for(int i=h[j];i!=0;)
		{
			fl[e[i]]=1;
			i=ne[i];
			fn++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(fl[i]==0)//没放弃也没参加 
		{
			fl[i]=1;
			if(nd[1]==1)dfs(1,fn,fn,1);
			else dfs(0,fn+1,fn,1);
			fl[i]=0;
		}
	}
	cout<<ans;
	return 0;
}

