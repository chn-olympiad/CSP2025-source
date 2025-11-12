#include<bits/stdc++.h>
using namespace std;
int a[10086][10086];
int t;
int minn=98765;
int AC;
int W;
int qwee;
int qwe= -1;
int A[10086][10086];
int q[10086][10086];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int n;
		AC=0;
		qwe= -1;
		W=0;
		cin>>n;
		int m=n/2;
		for(int i=1;i<=n;i++){
			qwe=-1;
			for(int r=1;r<=3;r++){
				cin>>a[i][r];
				if(a[i][r]>qwe){
					qwe=a[i][r];
					W=j;
				}
			}
		}
	}
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cout<<qwee<<"\n";
	return 0;
}

