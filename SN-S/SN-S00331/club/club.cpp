#include <bits/stdc++.h>
#define SIZ 210
int sat[SIZ][4];
float jfsat[SIZ][2];
int arry(int* arr)
{
	int t;
	if(arr[0]>arr[1] and arr[0]>arr[2]){
		t=0;
		if(arr[1]>arr[2])
		t=(t*10+1)*10+2;
		else if(arr[2]>arr[1])
		t=(t*10+2)*10+1;
	}
	else if(arr[1]>arr[2] and arr[1]>arr[0])
	{
		t=1;
		if(arr[0]>arr[2])
		t=(t*10+0)*10+2;
		else if(arr[2]>arr[0])
		t=(t*10+2)*10+0;
	}
	else if(arr[2]>arr[1] and arr[2]>arr[0])
	{
		t=2;
		if(arr[1]>arr[0])
		t=(t*10+1)*10+0;
		else if(arr[0]>arr[1])
		t=(t*10+0)*10+1;
	}
	return t;
}

float ave(int* arr,int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+arr[i];
	}
	return (sum/n);
}

float junfang(int* arr,int n)
{
	float aver=ave(arr,n);
	float s=0;
	for(int i=0;i<n;i++)
	{
		s=s+(arr[i]-aver)*(arr[i]-aver);
	}
	return s;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		
		int dep[3]={0};
		int all=0;
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%d%d%d",&sat[j][0],&sat[j][1],&sat[j][2]);
			sat[j][3]=j;
		}
		for(int j=0;j<n;j++)
		{
			jfsat[j][0]=junfang(sat[j],3);
			jfsat[j][1]=j;
		}
		//for(int i=0;i<n;i++)
		//printf(",%f,",jfsat[i][0]);
		for(int j=0;j<n;j++)
		for(int k=0;k<n-j-1;k++)
		{
			if(jfsat[k][0]<jfsat[k+1][0])
			{
				float t;
				t=jfsat[k][1];
				jfsat[k][1]=jfsat[k+1][1];
				jfsat[k+1][1]=t;
				t=jfsat[k][0];
				jfsat[k][0]=jfsat[k+0][0];
				jfsat[k+1][0]=t;
			}
		//	printf("/%d/",j);
		}
		//for(int j=0;j<n;j++)
		//printf(",%f,",jfsat[j][1]);
		for(int j=0;j<n;j++)
		{
			int e;
			int p=int(jfsat[j][1]);
			//printf("/%d/",int(jfsat[j][1]));
			e=arry(sat[p]);
			//printf("/%d/",e);
			int t1=int(e/100);
			int t2=int((e-t1*10)/10);
			int t3=int(e-t1*100-t2*10);
			//printf("\n%d,,,%d,,,%d\n",t1,t2,t3);
			//printf("/%d,%d,%d/",sat[j][0],sat[j][1],sat[j][2]);
			if(dep[t1]<(2/n))
			{
				dep[t1]++;
				int h=jfsat[j][1];
				all=all+sat[h][t1];
			//	printf("%d",all);
			}
			
			else if(dep[t2]<(2/n))
			{
				dep[t2]++;
				int h=jfsat[j][1];
				all=all+sat[h][t2];
		
			}
			else if(dep[t3]<(2/n))
			{
				dep[t3]++;
				int h=jfsat[j][1];
				all=all+sat[h][t3];
			}
		}
		printf("%d\n",all);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
