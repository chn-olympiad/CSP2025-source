#include<iostream>
#include<vector>
using namespace std;
int far[1024];
int thir(vector<vector<vector<int> > >W,int GT,int stu)
{int Y=-7;
for(int d=0;d<1024;d++)
	{
		far[d]=0;
	}
while(1)
{
	int Z=0;
	
	int i=0;
	
	for(;i<stu;i++)
	{
		if(far[i]!=2){
		far[i]++;
		break;
		}
		else
		far[i]=0;
	}
	
	for(int j=0;j<4;j++)
	{
		
		
	}
	
	if(i==stu)
	{
		return Y;
	}
	int D=stu/2;
	int A=0,B=0,C=0;
	for(int i=0;i<stu;i++)
	{
	switch(far[i])
	{
		case 0:A++;break;
		case 1:B++;break;
		case 2:C++;break;
		}	
	}

	if(A<=D&&B<=D&&C<=D)
	{
		
		for(int i=0;i<stu;i++)
	{
	if(far[i]==0)
	{
		Z=Z+W[GT][i][0];
		}	
		if(far[i]==1)
	{
		Z=Z+W[GT][i][1];
		}
		if(far[i]==2)
	{
		Z=Z+W[GT][i][2];
		}
	}	
	if(Z>Y)
	{
	
	Y=Z;}
	else
	{
		
	}
	}	
}}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int t;
cin>>t;
int g[1024];
vector<vector<vector<int> > >W;


for(int i=0;i<t;i++)
{vector<vector<int > >L;
	cin>>g[i];
	for(int x=0;x<g[i];x++)
	{vector<int>S;
		for(int y=0;y<3;y++)
		{int R;
			cin>>R;
		S.push_back(R);	
		}
		L.push_back(S);
	}
	W.push_back(L);
	
}

for(int o=0;o<t;o++)
{
	cout<<thir(W,o,g[o])<<endl;

}
return 0;
}
