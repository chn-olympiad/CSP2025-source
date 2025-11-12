#include <bits/stdc++.h>
using namespace std;
int t,n,ans[8],x[205],y[205],z[205],a,b,c,an[205],bn[205],cn[205],first[205],second[205];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++){
		a=b=c=0;
		cin>>n;
		for(int i = 1;i <= n;i++){
			x[i]=y[i]=z[i]=an[i]=bn[i]=cn[i]=first[i]=second[i]=0;
			cin>>x[i]>>y[i]>>z[i];
			int m = 99999999,l;
			if(max(x[i],y[i])==max(x[i],z[i])){
				first[i]=x[i];
				second[i]=max(y[i],z[i]);
				if(a==n/2){
					for(int j = 1;j <= i;j++){
						if(m!=min(m,an[i]))
						{
							m=min(m,an[i]);
							l=j;
						}
					}
					if(first[l]+second[i]>second[l]+first[i]){
						if(second[i]=y[i]){
							++b;
							bn[i]=y[i];
							ans[q]+=bn[i];
							--a; 
						}
						else if(second[i]=z[i]){
							c++;
							cn[i]=z[i];
							ans[q]+=cn[i];
							--a; 
						}
					}
					else
					{
						if(second[l]=y[l])
						{
							++b;
							bn[l]=y[l];
							ans[q]+=bn[l]-an[l];
							an[l]=0;
						}
						else if(second[l]=z[l])
						{
							++c;
							cn[l]=z[l];
							ans[q]+=cn[l]-an[l];
							an[l]=0;
						}
						an[i]=x[i];
						ans[q]+=an[i];
						
					}
				}
				else{
					++a;
					an[i]=x[i];
					ans[q]+=an[i];
				}
			}
			else if(max(x[i],y[i])==max(y[i],z[i])){
				first[i]=y[i];
				second[i]=max(x[i],z[i]);
				if(b==n/2){
					for(int j = 1;j <= i;j++){
						if(m!=min(m,bn[i]))
						{
							m=min(m,bn[i]);
							l=j;
						}
					}
					if(first[l]+second[i]>second[l]+first[i]){
						if(second[i]=x[i]){
							++a;
							an[i]=x[i];
							ans[q]+=an[i];
							--b;
						}
						else if(second[i]=z[i]){
							c++;
							cn[i]=z[i];
							ans[q]+=cn[i];
							--b;
						}
					}
					else
					{
						if(second[l]=x[l])
						{
							++a;
							an[l]=x[l];
							ans[q]+=an[l]-bn[l];
							bn[l]=0;
						}
						else if(second[l]=z[l])
						{
							++c;
							cn[l]=z[l];
							ans[q]+=cn[l]-bn[l];
							bn[l]=0;	
						}
						bn[i]=y[i];
						ans[q]+=bn[i];
					}
				}
				else{
					++b;
					bn[i]=y[i];
					ans[q]+=bn[i];
				}
			}
			else{
				first[i]=z[i];
				second[i]=max(y[i],x[i]);
				if(c==n/2)
				{
					for(int j = 1;j <= i;j++){
						if(m!=min(m,cn[i]))
						{
							m=min(m,cn[i]);
							l=j;
						}
					}
					if(first[l]+second[i]>second[l]+first[i]){
						if(second[i]=x[i]){
							++a;
							an[i]=x[i];
							ans[q]+=an[i];
							--c;
						}
						else if(second[i]=y[i]){
							b++;
							bn[i]=y[i];
							ans[q]+=bn[i];
							--c;
						}
					}
					else{
						if(second[l]=x[l]){
							++a;
							an[l]=x[l];
							ans[q]+=an[l]-cn[l];
							cn[l]=0;
						}
						else if(second[l]=y[l]){
							++b;
							bn[l]=y[l];
							ans[q]+=bn[l]-cn[l];
							cn[l]=0;
						}
						cn[i]=z[i];
						ans[q]+=cn[i];
					}
				}
				else{
					++c;
					cn[i]=z[i];
					ans[q]+=cn[i];
				}
			}
		}
	}
	for(int i = 1;i <= t;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
