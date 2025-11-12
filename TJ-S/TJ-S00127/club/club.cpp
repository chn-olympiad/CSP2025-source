//#include<bits/stdc++.h>//Ò»ÛçÊºÉ½ 
//using namespace std;
//int t;
//int n;
//struct struc
//{
//	int a,b,c,n;	
//}an[100005],temp[100005];
//bool cmpa(struc x,struc y)
//{
//	return x.a>y.a;
//}
//bool cmpb(struc x,struc y)
//{
//	return x.b>y.b;
//}
//bool cmpc(struc x,struc y)
//{
//	return x.c>y.c;
//}
//int main()
//{
//	cin>>t;
//	int i,j;
//	while(t)
//	{
//		int a=0,sa = 0,sb = 0,sc = 0,b=0,c=0,j,x = 0;
//		t--;
//		cin>>n;
//		for(i=1;i<=n;i++)
//		{
//			cin>>an[i].a>>an[i].b>>an[i].c;
//			if(an[i].a>an[i].b && an[i].a>an[i].c)
//			{
//				a++,sa+=an[i].a;	
//			}
//			else if(an[i].b>an[i].a && an[i].b>an[i].c)
//			{
//				b++,sb += an[i].b;
//			}
//			else if(an[i].c>an[i].a && an[i].c > an[i].b)
//			{
//				c++,sc += an[i].c;
//			}
//			else
//			{
//				x++;
//				int te = min(a,min(b,c));
//				if(te == a)
//				{
//					a++,sa+=an[i].a;
//					temp[x].n = 1;
//					temp[x].a = an[x].c;
//					temp[x].b = an[x].b;
//					temp[x].c = an[x].c;
//				}	
//				else if(te == b)
//				{
//					b++,sb+=an[i].b;	
//					temp[x].n = 2;
//					temp[x].a = an[x].a;
//					temp[x].b = an[x].b;
//					temp[x].c = an[x].c;
//				}
//				else
//				{
//					c++,sc+=an[i].c;
//					temp[x].a = an[x].a;
//					temp[x].n = 3;
//					temp[x].b = an[x].b;
//					temp[x].c = an[x].c;
//				}	
//			}
//		}
//		sort(temp+1,temp+1+n);
//		int con = n/2;
//		if(a>con)
//		{
//			sort(an+1,an+1+n,cmpa);
//			for(j = con+1;j<=a;j++)
//			{
//				bool flag = 0;
//				for(int k =1;k<=x;k++)
//				{
//					if(temp[k].a>=an[j].a && temp[k].n == 1)
//					{
//						sa -= temp[k].a;
//						if(b+1<=con)
//						{
//							sb+=temp[k].a;
//							temp[k].n = 2;
//						}
//						else
//						{
//							sc+=temp[k].c;
//							temp[k].n = 3;
//						}
//						flag = 1;
//						break;
//					}
//				}
//				if(flag)
//					continue;
//				sa -= an[j].a;
//				if(an[j].b > an[j].c && b+1<=con)
//					b++,sb+=an[j].b;
//				else if(an[j].b < an[j].c && c+1<=con) 
//					c++,sc+=an[i].c;
//				else if(c<b)
//					c++,sc+=an[i].c;
//				else
//					b++,sb+=an[i].b;
//			}
//			a=con;
//		}
//		else if(b>con)
//		{
//			sort(b+1,b+1+n,cmpb);
//			for(j = con+1;j<=b;j++)
//			{
//				bool flag = 0;
//				for(int k =1;k<=x;k++)
//				{
//					if(temp[k].b>=an[j].b && temp[k].n == 2)
//					{
//						sb -= temp[k].b;
//						if(a+1<=con)
//						{
//							sa+=temp[k].b;
//							temp[k].n = 1;
//						}
//						else
//						{
//							sc+=temp[k].c;
//							temp[k].n = 3;
//						}
//						flag = 1;
//						break;
//					}
//				}
//				if(flag)
//					continue;
//				sb -= an[j].b;
//				if(an[j].a > an[j].c && a+1<=con)
//					a++,sa+=an[j].a;
//				else if(an[j].a < an[j].c && c+1<=con) 
//					c++,sc+=an[i].c;
//				else if(c<a)
//					c++,sc+=an[i].c;
//				else
//					a++,sa+=an[i].a;
//			}
//			b = con;
//		}
//		else if(c>con)
//		{
//			sort(c+1,c+1+n,cmpc);
//			for(j = con+1;j<=c;j++)
//			{
//			bool flag = 0;
//				for(int k =1;k<=x;k++)
//				{
//					
//					if(temp[k].c>=an[j].c && temp[k].n == 3)
//					{
//						sc -= temp[k].c;
//						if(b+1<=con)
//						{
//							sb+=temp[k].a;
//							temp[k].n = 2;
//						}
//						else
//						{
//							sa+=temp[k].a;
//							temp[k].n = 1;
//						}
//						flag = 1;
//						break;
//					}
//				}
//				if(flag)
//					continue;
//				sc -= an[j].c;
//				if(an[j].b > an[j].a && b+1<=con)
//					b++,sb+=an[j].b;
//				else if(an[j].b < an[j].a && a+1<=con) 
//					a++,sa+=an[i].a;
//				else if(a<b)
//					a++,sa+=an[i].a;
//				else
//					b++,sb+=an[i].b;
//			}
//		}
//		cout<<sa+sb+sc;	
//	}
//	
//	return 0;
// } 
#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t)
	{
		t--;
		int an=0,bn=0
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a>>b>>c;
				ans+=max(a,b);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
