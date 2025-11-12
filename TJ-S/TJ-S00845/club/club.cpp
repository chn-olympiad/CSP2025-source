#include<bits/stdc++.h>
using namespace std;
long long jyj,jz,zrd[11451][5],maux1=0,maux2=0,maux3=0,jl1,jl2,jl3,jlmax=0,mhzd1=0,mhzd2=0,mhzd,wufen=0,count1=0;
void cjpx()
{
	maux1=0;
	maux2=0;
	maux3=0;
	for(int j=1;j<=jz;j++)
	{
		if(zrd[j][1]>=maux1)
		{
			maux1=zrd[j][1];
			jl1=j;
		}
		if(zrd[j][2]>=maux2)
		{
			maux2=zrd[j][2];
			jl2=j;
		}
		if(zrd[j][3]>=maux3)
		{		
			maux3=zrd[j][3];
			jl3=j;
		}
	}
}
void cjbj()
{
	//jlmax=0;
	if(jl1==jl2&&maux1!=0&&maux2!=0)
	{
			int jlx,jly;
			for(int j=1;j<=3;j++)
			{
				if(zrd[jl1][j]>jlmax)
				{
					jlmax=zrd[jl1][j]+maux3;
					//cout<<jlmax<<" ";
					jlx=jl1;
					jly=j;
				}
			}
			zrd[jlx][jly]=0;
			//cout<<zrd[jlx][jly]<<" ";
			cjpx();
			//cout<<zrd[jlx][jly]<<" ";
		}
		else if(jl2==jl3&&maux2!=0&&maux3!=0)
		{
			//cout<<"a";
			int jlx,jly;
			for(int j=1;j<=3;j++)
			{
				if(zrd[jl2][j]>jlmax)
				{
					jlmax=zrd[jl2][j]+maux1;
					//cout<<jlmax<<" ";
					jlx=jl2;
					jly=j;
				}
			}
			zrd[jlx][jly]=0;
			cjpx();
		}
		else if(jl1==jl3&&maux1!=0&&maux3!=0)
		{
			int jlx,jly;
			for(int j=1;j<=3;j++)
			{
				if(zrd[jl3][j]>jlmax)
				{
					jlmax=zrd[jl3][j]+maux2;
					jlx=jl3;
					jly=j;
				}
			}
			zrd[jlx][jly]=0;
			cjpx();
			//cout<<"a";
		}
}
void zhyb()
{
	if(jl1==jl2&&jl2==jl3&&maux1!=0&&maux2!=0&&maux3!=0)
		{
			int jlx,jly;
			for(int j=1;j<=3;j++)
			{
				if(zrd[jl3][j]>jlmax)
				{
					jlmax=zrd[jl3][j];
					jlx=jl3;
					jly=j;
				}
			}
			zrd[jlx][jly]=0;
			cjpx();
			zhyb();
		}else{
			//cout<<"a";
			cjbj();
			if(jlmax>maux1+maux2+maux3)
			{
				cout<<jlmax<<endl;
			}else{
				if(jl1==jl2)
				{
					if(maux1>maux2)
					{
						cout<<maux1+maux3<<endl;
					}else{
						cout<<maux2+maux3<<endl;
					}
				}
				if(jl3==jl2)
				{
					if(maux3>maux2)
					{
						cout<<maux1+maux3<<endl;
					}else{
						cout<<maux2+maux1<<endl;
					}
				}
				if(jl1==jl3)
				{
					if(maux1>maux3)
					{
						cout<<maux2+maux1<<endl;
					}else{
						cout<<maux2+maux3<<endl;
					}
				}
			}
		}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>jyj;
	for(int i=1;i<=jyj;i++)
	{
		count1=0;
		mhzd1=0;
		mhzd2=0;
		maux1=0;
		maux2=0;
		maux3=0;
		jlmax=0;
		int fml1,fml2;
		cin>>jz;
		for(int j=1;j<=jz;j++)
		{
			for(int k=1;k<=3;k++)
			{
				cin>>zrd[j][k];
				if(j==1&&zrd[j][k]>mhzd1)
				{
					mhzd1=zrd[j][k]; 
					fml1=k;
				}
				if(j==2&&zrd[j][k]>mhzd2)
				{
					mhzd2=zrd[j][k];
					fml2=k;
				}
			}
		}
		for(int j=1;j<=jz;j++)
		{
			if(jz>10&&zrd[j][2]==0&&zrd[j][3]==0)
			{
				if(zrd[j][1]>wufen)
				{
					wufen=zrd[j][1];
					count1++;
				}
			}	
		}
		if(count1>0)//100 0 0
		{
			cout<<wufen<<endl;
			//break;
			continue;
		}
		mhzd=mhzd1+mhzd2;
		if(fml1!=fml2)
		{
			cout<<mhzd<<endl;
		}else{
			cjpx();
			zhyb();
		}
	} 
	return 0;
}
