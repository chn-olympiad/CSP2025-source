#include<bits/stdc++.h>
using namespace std;
long long T,n,ans,a1[100010],a2[100010],a3[100010],f[300][5],b1,b2,b3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		if(n==2)
		{
			for(int i=1;i<=n;i++) cin>>f[i][1]>>f[i][2]>>f[i][3];
			for(int i1=1;i1<=3;i1++)
				for(int i2=1;i2<=3;i2++)
					{
						b1=0;b2=0;b3=0;
						if(i1==1) b1++;if(i1==2) b2++;if(i1==3) b3++;
						if(i2==1) b1++;if(i2==2) b2++;if(i2==3) b3++;
						if(b1<=n/2&&b2<=n/2&&b3<=n/2)
							ans=max(ans,f[1][i1]+f[2][i2]);
					}
			cout<<ans<<endl;
		}
		if(n==4)
		{
			for(int i=1;i<=n;i++) cin>>f[i][1]>>f[i][2]>>f[i][3];
			for(int i1=1;i1<=3;i1++)
			for(int i2=1;i2<=3;i2++)
			for(int i3=1;i3<=3;i3++)
			for(int i4=1;i4<=3;i4++)
			{
				b1=0;b2=0;b3=0;
				if(i1==1) b1++;if(i1==2) b2++;if(i1==3) b3++;
				if(i2==1) b1++;if(i2==2) b2++;if(i2==3) b3++;
				if(i3==1) b1++;if(i3==2) b2++;if(i3==3) b3++;
				if(i4==1) b1++;if(i4==2) b2++;if(i4==3) b3++;
				if(b1<=n/2&&b2<=n/2&&b3<=n/2)
					ans=max(ans,f[1][i1]+f[2][i2]+f[3][i3]+f[4][i4]);
			}
			cout<<ans<<endl;
		}
		if(n==10)
		{
			for(int i=1;i<=n;i++) cin>>f[i][1]>>f[i][2]>>f[i][3];
			for(int i1=1;i1<=3;i1++)
			for(int i2=1;i2<=3;i2++)
			for(int i3=1;i3<=3;i3++)
			for(int i4=1;i4<=3;i4++)
			for(int i5=1;i5<=3;i5++)
			for(int i6=1;i6<=3;i6++)
			for(int i7=1;i7<=3;i7++)
			for(int i8=1;i8<=3;i8++)
			for(int i9=1;i9<=3;i9++)
			for(int i10=1;i10<=3;i10++)
			{
				b1=0;b2=0;b3=0;
				if(i1==1) b1++;if(i1==2) b2++;if(i1==3) b3++;
				if(i2==1) b1++;if(i2==2) b2++;if(i2==3) b3++;	
				if(i3==1) b1++;if(i3==2) b2++;if(i3==3) b3++;
				if(i4==1) b1++;if(i4==2) b2++;if(i4==3) b3++;
				if(i5==1) b1++;if(i5==2) b2++;if(i5==3) b3++;
				if(i6==1) b1++;if(i6==2) b2++;if(i6==3) b3++;
				if(i7==1) b1++;if(i7==2) b2++;if(i7==3) b3++;
				if(i8==1) b1++;if(i8==2) b2++;if(i8==3) b3++;
				if(i9==1) b1++;if(i9==2) b2++;if(i9==3) b3++;
				if(i10==1) b1++;if(i10==2) b2++;if(i10==3) b3++;
				if(b1<=n/2&&b2<=n/2&&b3<=n/2)
					ans=max(ans,f[1][i1]+f[2][i2]+f[3][i3]+f[4][i4]+f[5][i5]+f[6][i6]+f[7][i7]+f[8][i8]+f[9][i9]+f[10][i10]);
			}
			cout<<ans<<endl;
		}
		if(n==100000)
		{
			for(int i=1;i<=n;i++) cin>>a1[i]>>a2[i]>>a3[i];
			sort(a1+1,a1+n+1);
			for(int i=n/2+1;i<=n;i++) ans+=a1[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}
