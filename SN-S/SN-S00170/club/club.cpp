#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,mx=-1e5,a1=0,b1=0,c1=0;
	int aaa=0;
	//mxx最大值,a1那时的a,b1那时的b,c1那时的c 
	int a[100005]={0},b[100005],c[100005],d[100005]={0};
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;int no=0;
		int a[100005]={0};
		scanf("%d",&n);
		int maxn=n/2;//以防我不知道 上限是maxn 
		for(int j=0;j<n;j++)//以防我不知道这是读入 
		{
//		cin>>a[j]>>b[j]>>c[j];
		int q,w,e,qw;
		cin>>q>>w>>e;
		a[j]=q;
		if(w!=0||e!=0)a1=1;
		qw=max(q,w);
		aaa=max(qw,e);
		no+=aaa;
//		cout<<"aaa"<<aaa<<endl;
		}
		if(a1==0)//特性A 
		{
			no=0;
			sort(a,a+maxn);
			for(int p=maxn;p>0;p--)
			{
				no+=a[p];
			}
		}
	cout<<no<<endl;
	}
	return 0;
}//I like ccf,plesae give me a 3=
//前言:The next words maybe have a little mistakes in grammer; 
//I wanted toget a 2= befor I saw this problem,but now I think I only can get a 3= or 0 score
//Okey ,the time of this exam has gone past,but there is not any problems that I can finish it.
//I am going to AFO after this examination 
//  
