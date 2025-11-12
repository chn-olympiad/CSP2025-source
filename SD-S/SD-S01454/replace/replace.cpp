#include<bits/stdc++.h>

using namespace std;
const int N=2e5+5;
int n,q;
string s[N][3];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	while(q--)
	{
		string t1,t2;
		int ans=0;
//		cin>>t1>>t2;
//		int l1=t1.size();
//		if(l1!=t2.size())
//		{
//			printf("0\n");
//			continue;
//		}
//		
//		for(int i=1;i<=n;i++)
//		{
//			int l2=s[i][1].size();
//			if(l2>l1) {printf("0\n");continue;}
//			for(int j=0;j<l2-l1;j++)
//			{
//				int f=0;
//				for(int k=0;k<l2;k++)
//					if(s[i][1][j+k]!=t1[k]) {f=1;break;}
//				if(f) continue;
//				
//				for(int k=0;k<j;k++) 
//					if(t1[k]!=t2[k]) {f=1;break;}
//				if(f) continue;
//				for(int k=j;k<j+l2;k++) 
//					if(s[i][2][k-j]!=t2[k]) {f=1;break;}
//				if(f) continue;
//				for(int k=j+l2;k<l1;k++)
//				if(t1[k]!=t2[k]) {f=1;break;}
//				if(f) continue;
//				ans++; 
//			}
//		}
		printf("%d\n",ans);
	}
	return 0;
}
