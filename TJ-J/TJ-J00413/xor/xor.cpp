#include<bits/stdc++.h>
using namespace std;
char c;
void qread(int &n)
{
	c=0,n=0;
	for(;c<'0'||'9'<c;c=getchar());
	for(;'0'<=c&&c<='9';n=n*10+c-'0',c=getchar());
}
int a[500010];
struct segment
{
	int start,end;
};
bool cmp(segment x,segment y)
{
	return x.end<y.end;
}
segment b[500010];
int top=0;
int main()
{
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;qread(n),qread(k);
	for(int i=1;i<=n;i++)
	{
		qread(a[i]);
	}
	int tmp;
	for(int i=1;i<=n;i++)
	{
		tmp=0;
		for(int j=i;j<=n;j++)
		{
			tmp^=a[j];
			if(tmp==k)
			{
				b[++top]={i,j};
				break;
			}
		}
	}
	sort(b+1,b+1+top,cmp);
	if(top==0)
	{
		cout<<0;
		return 0;
	}
	int c=1;
	segment last=b[1];
	for(int i=2;i<=top;i++)
	{
		if(b[i].start>last.end)
		{
			c++;
			last=b[i];
		}
	}
	printf("%d",c);
	return 0;
}
/*
O(n)~O(n^2)时间复杂度的代码
保守估计60pts

我就要上迷惑行为大赏！！！ 
*/
