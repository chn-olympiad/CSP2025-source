#include<bits/stdc++.h>
using namespace std;
int F[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>F[i];
	sort(F+1,F+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		long long ans=0;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					if(F[a]+F[b]+F[c]>2*F[c])ans++;
		cout<<ans;
		return 0;
	}
	if(n==4){
		long long ans=0;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					if(F[a]+F[b]+F[c]>2*F[c])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						if(F[a]+F[b]+F[c]+F[d]>2*F[d])ans++;
		cout<<ans;
		return 0;
	}
	if(n==5){
		long long ans=0;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					if(F[a]+F[b]+F[c]>2*F[c])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						if(F[a]+F[b]+F[c]+F[d]>2*F[d])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							if(F[a]+F[b]+F[c]+F[d]+F[e]>2*F[e])ans++;
		cout<<ans;
		return 0;
	}
	if(n==6){
		long long ans=0;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					if(F[a]+F[b]+F[c]>2*F[c])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						if(F[a]+F[b]+F[c]+F[d]>2*F[d])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							if(F[a]+F[b]+F[c]+F[d]+F[e]>2*F[e])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]>2*F[f])ans++;
		cout<<ans;
		return 0;
	}
	if(n==7){
		long long ans=0;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					if(F[a]+F[b]+F[c]>2*F[c])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						if(F[a]+F[b]+F[c]+F[d]>2*F[d])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							if(F[a]+F[b]+F[c]+F[d]+F[e]>2*F[e])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]>2*F[f])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]>2*F[g])ans++;
		cout<<ans;
		return 0;
	}
	if(n==8){
		long long ans=0;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					if(F[a]+F[b]+F[c]>2*F[c])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						if(F[a]+F[b]+F[c]+F[d]>2*F[d])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							if(F[a]+F[b]+F[c]+F[d]+F[e]>2*F[e])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]>2*F[f])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]>2*F[g])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]>2*F[h])ans++;
		cout<<ans;
		return 0;
	}
	if(n==9){
		long long ans=0;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					if(F[a]+F[b]+F[c]>2*F[c])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						if(F[a]+F[b]+F[c]+F[d]>2*F[d])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							if(F[a]+F[b]+F[c]+F[d]+F[e]>2*F[e])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]>2*F[f])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]>2*F[g])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]>2*F[h])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]+F[i]>2*F[i])ans++;
		cout<<ans;
		return 0;
	}
	if(n==10){
		long long ans=0;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					if(F[a]+F[b]+F[c]>2*F[c])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						if(F[a]+F[b]+F[c]+F[d]>2*F[d])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							if(F[a]+F[b]+F[c]+F[d]+F[e]>2*F[e])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]>2*F[f])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]>2*F[g])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]>2*F[h])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]+F[i]>2*F[i])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
												if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]+F[i]+F[j]>2*F[j])ans++;
		cout<<ans;
		return 0;
	}
	if(n==11){
		long long ans=0;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					if(F[a]+F[b]+F[c]>2*F[c])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						if(F[a]+F[b]+F[c]+F[d]>2*F[d])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							if(F[a]+F[b]+F[c]+F[d]+F[e]>2*F[e])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]>2*F[f])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]>2*F[g])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]>2*F[h])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]+F[i]>2*F[i])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
												if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]+F[i]+F[j]>2*F[j])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
												for(int k=j+1;k<=n;k++)
													if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]+F[i]+F[j]+F[k]>2*F[k])ans++;
		cout<<ans;
		return 0;
	}
	if(n==12){
		long long ans=0;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					if(F[a]+F[b]+F[c]>2*F[c])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						if(F[a]+F[b]+F[c]+F[d]>2*F[d])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							if(F[a]+F[b]+F[c]+F[d]+F[e]>2*F[e])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]>2*F[f])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]>2*F[g])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]>2*F[h])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]+F[i]>2*F[i])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
												if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]+F[i]+F[j]>2*F[j])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
												for(int k=j+1;k<=n;k++)
													if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]+F[i]+F[j]+F[k]>2*F[k])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
												for(int k=j+1;k<=n;k++)
													for(int l=k+1;l<=n;l++)
														if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]+F[i]+F[j]+F[k]+F[l]>2*F[l])ans++;
		cout<<ans;
		return 0;
	}
	if(n==13){
		long long ans=0;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					if(F[a]+F[b]+F[c]>2*F[c])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						if(F[a]+F[b]+F[c]+F[d]>2*F[d])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							if(F[a]+F[b]+F[c]+F[d]+F[e]>2*F[e])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]>2*F[f])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]>2*F[g])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]>2*F[h])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]+F[i]>2*F[i])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
												if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]+F[i]+F[j]>2*F[j])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
												for(int k=j+1;k<=n;k++)
													if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]+F[i]+F[j]+F[k]>2*F[k])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
												for(int k=j+1;k<=n;k++)
													for(int l=k+1;l<=n;l++)
														if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]+F[i]+F[j]+F[k]+F[l]>2*F[l])ans++;
		for(int a=1;a<=n;a++)
			for(int b=a+1;b<=n;b++)
				for(int c=b+1;c<=n;c++)
					for(int d=c+1;d<=n;d++)
						for(int e=d+1;e<=n;e++)
							for(int f=e+1;f<=n;f++)
								for(int g=f+1;g<=n;g++)
									for(int h=g+1;h<=n;h++)
										for(int i=h+1;i<=n;i++)
											for(int j=i+1;j<=n;j++)
												for(int k=j+1;k<=n;k++)
													for(int l=k+1;l<=n;l++)
														for(int m=l+1;m<=n;m++)
															if(F[a]+F[b]+F[c]+F[d]+F[e]+F[f]+F[g]+F[h]+F[i]+F[j]+F[k]+F[l]+F[m]>2*F[m])ans++;
		
		cout<<ans;
		return 0;
	}
	return 0;
}
