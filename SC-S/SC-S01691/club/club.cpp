#include<bits/stdc++.h>//a-club
using namespace std;
int tt;
int n,k;
int x,y,z;
int w;
long long ans;
int ta,cnta,a[100006];
int tb,cntb,b[100006];
int tc,cntc,c[100006];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>tt;
	while(tt--)
	{
		cin>>n;
		ta=tb=tc=1;
		w=0;
		k=n/2;
		cnta=cntb=cntc=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y>>z;
			++cnta;
			++cntb;
			++cntc;
			a[i]=x;
			b[i]=y;
			c[i]=z;
			w=i;
			///a:
			if(cnta>k)
			{

				if(a[i]==max(c[i],max(a[i],b[i])))
				{
					for(int j=ta+1;j<=i;j++)
					{
		//				cout<<a[j]<<"\n";//
						if(a[w]>a[j]&&a[j]!=-1) w=j;
					}					
		//			cout<<w<<"比较"<<ta<<'\n';//
					if(max(c[w],b[w])+a[ta]<max(c[ta],b[ta])+a[w])
					{
						a[ta]=-1;
						cnta--;
						++ta;
					}
					else
					{
						a[w]=-1;
					}
				}				
			}
			///b:
			if(cntb>k)
			{
			//	cout<<"!!\n";//
				if(b[i]==max(c[i],max(a[i],b[i])))
				{
					for(int j=tb+1;j<=i;j++)
					{
						if(b[w]>b[j]&&b[j]!=-1) w=j;
					}					
					if(max(a[w],c[w])+b[tb]<max(a[tb],c[tb])+b[w])
					{
						b[tb]=-1;
						cntb--;
						++tb;
					}
					else
					{
						b[w]=-1;
					}
				}				
			}
			///c:
			if(cntc>k)
			{

				if(c[i]==max(c[i],max(a[i],b[i])))
				{
					for(int j=tc+1;j<=i;j++)
					{
						if(c[w]>c[j]&&c[j]!=-1) w=j;
					}					
					if(max(a[w],b[w])+c[tc]<max(a[tc],b[tc])+c[w])
					{
						c[tc]=-1;
						cntc--;
						++tc;
					}
					else
					{
						c[w]=-1;
					}
				}				
			}
		}
		ans=0;
	//	cout<<cnta<<' '<<cntb<<' '<<cntc<<"!\n";//
		for(int i=1;i<=n;i++)
		{
	//		cout<<a[i]<<' '<<b[i]<<" "<<c[i]<<"\n";//
			ans+=max(a[i],max(b[i],c[i]));
		}
		cout<<ans;
		if(tt!=0) cout<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


n为偶数
不存在一个部门被分配多于(>)n/2个新成员

cout:满足他要求的分配方案的满意度的最大值

RP++
*/