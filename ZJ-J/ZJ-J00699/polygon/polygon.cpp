#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
int main(){
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(a[n]==1){
		for(int i=1;i<=n-3;i++)
			sum=sum*2+i;
		cout<<sum;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3])
			cout<<1;
		else cout<<0;
	}
	else if(n==4){
		if(a[1]+a[2]+a[3]>a[3]*2)
			sum++;
		if(a[1]+a[2]+a[4]>a[4]*2)
			sum++;
		if(a[4]+a[2]+a[3]>a[4]*2)
			sum++;
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2)
			sum++;
		cout<<sum;
	}
	else if(n==5){
		for(int i=1;i<=3;i++)
			for(int j=i+1;j<=4;j++)
				for(int k=j+1;k<=5;k++)
					if(a[i]+a[j]+a[k]>a[k]*2)
						sum++;
		for(int i=1;i<=2;i++)
			for(int j=i+1;j<=3;j++)
				for(int k=j+1;k<=4;k++)
					for(int l=k+1;l<=5;l++)
						if(a[i]+a[j]+a[k]+a[l]>a[l]*2)
							sum++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2)
			sum++;
		cout<<sum;
	}
	else if(n==6){
		for(int i=1;i<=4;i++)
			for(int j=i+1;j<=5;j++)
				for(int k=j+1;k<=6;k++)
					if(a[i]+a[j]+a[k]>a[k]*2)
						sum++;
		for(int i=1;i<=3;i++)
			for(int j=i+1;j<=4;j++)
				for(int k=j+1;k<=5;k++)
					for(int l=k+1;l<=6;l++)
						if(a[i]+a[j]+a[k]+a[l]>a[l]*2)
							sum++;
		for(int i=1;i<=2;i++)
			for(int j=i+1;j<=3;j++)
				for(int k=j+1;k<=4;k++)
					for(int l=k+1;l<=5;l++)
						for(int m=l+1;m<=6;m++)
							if(a[i]+a[j]+a[k]+a[l]+a[m]>a[m]*2)
								sum++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[6]*2)
			sum++;
		cout<<sum;
	}
	else if(n==7){
		for(int i=1;i<=5;i++)
			for(int j=i+1;j<=6;j++)
				for(int k=j+1;k<=7;k++)
					if(a[i]+a[j]+a[k]>a[k]*2)
						sum++;
		for(int i=1;i<=4;i++)
			for(int j=i+1;j<=5;j++)
				for(int k=j+1;k<=6;k++)
					for(int l=k+1;l<=7;l++)
						if(a[i]+a[j]+a[k]+a[l]>a[l]*2)
							sum++;
		for(int i=1;i<=3;i++)
			for(int j=i+1;j<=4;j++)
				for(int k=j+1;k<=5;k++)
					for(int l=k+1;l<=6;l++)
						for(int m=l+1;m<=7;m++)
							if(a[i]+a[j]+a[k]+a[l]+a[m]>a[m]*2)
								sum++;
		for(int i=1;i<=2;i++)
			for(int j=i+1;j<=3;j++)
				for(int k=j+1;k<=4;k++)
					for(int l=k+1;l<=5;l++)
						for(int m=l+1;m<=6;m++)
							for(int n=m+1;n<=7;n++)
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[n]>a[n]*2)
									sum++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>a[7]*2)
			sum++;
		cout<<sum;
	}
	else if(n==8){
		for(int i=1;i<=6;i++)
			for(int j=i+1;j<=7;j++)
				for(int k=j+1;k<=8;k++)
					if(a[i]+a[j]+a[k]>a[k]*2)
						sum++;
		for(int i=1;i<=5;i++)
			for(int j=i+1;j<=6;j++)
				for(int k=j+1;k<=7;k++)
					for(int l=k+1;l<=8;l++)
						if(a[i]+a[j]+a[k]+a[l]>a[l]*2)
							sum++;
		for(int i=1;i<=4;i++)
			for(int j=i+1;j<=5;j++)
				for(int k=j+1;k<=6;k++)
					for(int l=k+1;l<=7;l++)
						for(int m=l+1;m<=8;m++)
							if(a[i]+a[j]+a[k]+a[l]+a[m]>a[m]*2)
								sum++;
		for(int i=1;i<=3;i++)
			for(int j=i+1;j<=4;j++)
				for(int k=j+1;k<=5;k++)
					for(int l=k+1;l<=6;l++)
						for(int m=l+1;m<=7;m++)
							for(int n=m+1;n<=8;n++)
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[n]>a[n]*2)
									sum++;
		for(int i=1;i<=2;i++)
			for(int j=i+1;j<=3;j++)
				for(int k=j+1;k<=4;k++)
					for(int l=k+1;l<=5;l++)
						for(int m=l+1;m<=6;m++)
							for(int n=m+1;n<=7;n++)
								for(int o=n+1;o<=8;o++)
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[n]+a[o]>a[o]*2)
										sum++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>a[8]*2)
			sum++;
		cout<<sum;
	}
	else if(n==9){
		for(int i=1;i<=7;i++)
			for(int j=i+1;j<=8;j++)
				for(int k=j+1;k<=9;k++)
					if(a[i]+a[j]+a[k]>a[k]*2)
						sum++;
		for(int i=1;i<=6;i++)
			for(int j=i+1;j<=7;j++)
				for(int k=j+1;k<=8;k++)
					for(int l=k+1;l<=9;l++)
						if(a[i]+a[j]+a[k]+a[l]>a[l]*2)
							sum++;
		for(int i=1;i<=5;i++)
			for(int j=i+1;j<=6;j++)
				for(int k=j+1;k<=7;k++)
					for(int l=k+1;l<=8;l++)
						for(int m=l+1;m<=9;m++)
							if(a[i]+a[j]+a[k]+a[l]+a[m]>a[m]*2)
								sum++;
		for(int i=1;i<=4;i++)
			for(int j=i+1;j<=5;j++)
				for(int k=j+1;k<=6;k++)
					for(int l=k+1;l<=7;l++)
						for(int m=l+1;m<=8;m++)
							for(int n=m+1;n<=9;n++)
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[n]>a[n]*2)
									sum++;
		for(int i=1;i<=3;i++)
			for(int j=i+1;j<=4;j++)
				for(int k=j+1;k<=5;k++)
					for(int l=k+1;l<=6;l++)
						for(int m=l+1;m<=7;m++)
							for(int n=m+1;n<=8;n++)
								for(int o=n+1;o<=9;o++)
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[n]+a[o]>a[o]*2)
										sum++;
		for(int i=1;i<=2;i++)
			for(int j=i+1;j<=3;j++)
				for(int k=j+1;k<=4;k++)
					for(int l=k+1;l<=5;l++)
						for(int m=l+1;m<=6;m++)
							for(int n=m+1;n<=7;n++)
								for(int o=n+1;o<=8;o++)
									for(int p=o+1;p<=9;p++)
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[n]+a[o]+a[p]>a[p]*2)
											sum++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>a[9]*2)
			sum++;
		cout<<sum;
	}
	else{
		for(int i=1;i<=8;i++)
			for(int j=i+1;j<=9;j++)
				for(int k=j+1;k<=10;k++)
					if(a[i]+a[j]+a[k]>a[k]*2)
						sum++;
		for(int i=1;i<=7;i++)
			for(int j=i+1;j<=8;j++)
				for(int k=j+1;k<=9;k++)
					for(int l=k+1;l<=10;l++)
						if(a[i]+a[j]+a[k]+a[l]>a[l]*2)
							sum++;
		for(int i=1;i<=6;i++)
			for(int j=i+1;j<=7;j++)
				for(int k=j+1;k<=8;k++)
					for(int l=k+1;l<=9;l++)
						for(int m=l+1;m<=10;m++)
							if(a[i]+a[j]+a[k]+a[l]+a[m]>a[m]*2)
								sum++;
		for(int i=1;i<=5;i++)
			for(int j=i+1;j<=6;j++)
				for(int k=j+1;k<=7;k++)
					for(int l=k+1;l<=8;l++)
						for(int m=l+1;m<=9;m++)
							for(int n=m+1;n<=10;n++)
								if(a[i]+a[j]+a[k]+a[l]+a[m]+a[n]>a[n]*2)
									sum++;
		for(int i=1;i<=4;i++)
			for(int j=i+1;j<=5;j++)
				for(int k=j+1;k<=6;k++)
					for(int l=k+1;l<=7;l++)
						for(int m=l+1;m<=8;m++)
							for(int n=m+1;n<=9;n++)
								for(int o=n+1;o<=10;o++)
									if(a[i]+a[j]+a[k]+a[l]+a[m]+a[n]+a[o]>a[o]*2)
										sum++;
		for(int i=1;i<=3;i++)
			for(int j=i+1;j<=4;j++)
				for(int k=j+1;k<=5;k++)
					for(int l=k+1;l<=6;l++)
						for(int m=l+1;m<=7;m++)
							for(int n=m+1;n<=8;n++)
								for(int o=n+1;o<=9;o++)
									for(int p=o+1;p<=10;p++)
										if(a[i]+a[j]+a[k]+a[l]+a[m]+a[n]+a[o]+a[p]>a[p]*2)
											sum++;
		for(int i=1;i<=2;i++)
			for(int j=i+1;j<=3;j++)
				for(int k=j+1;k<=4;k++)
					for(int l=k+1;l<=5;l++)
						for(int m=l+1;m<=6;m++)
							for(int n=m+1;n<=7;n++)
								for(int o=n+1;o<=8;o++)
									for(int p=o+1;p<=9;p++)
										for(int r=p+1;r<=10;r++)
											if(a[i]+a[j]+a[k]+a[l]+a[m]+a[n]+a[o]+a[p]+a[r]>a[r]*2)
												sum++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>a[10]*2)
			sum++;
		cout<<sum;
	}
	return 0;
}
