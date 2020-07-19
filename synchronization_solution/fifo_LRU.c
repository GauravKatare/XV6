#include<stdio.h>
#include <stdlib.h>
#include<time.h>

int arr[18];

int f;
void fifo()
{
	printf("FIFO\n");
	int h[10]={0};
	int in[f+1];
	int fr[f+1];
	int cnt = 0;
	for(int i=0;i<f;i++)
		fr[i]=in[i] = -1;
	int fc=0;
	for(int i=0;i<18;i++)
	{
		printf("%d: ",arr[i]);
		if(h[arr[i]])
			printf("No page fault :");
		else
		{
			fc++;
			printf("Fage Fault : ");
			if(cnt<f)
			{
				fr[cnt] = arr[i];
				in[cnt++] = i;
			}
			else
			{
				int id = 0;
				for(int j=1;j<cnt;j++)
					if(in[j]<in[id])
						id = j;
				fr[id] = arr[i];
				h[fr[id]] = 0;
				in[id] = i;
			}
			h[arr[i]]=1;
		}

		for(int i=0;i<f;i++)
			printf("%d ",fr[i]);
		printf("\n");
	}
	printf("Total Faults : %d\n",fc);

}

void lru()
{
	printf("LRU\n");;
	int h[10]={0};
	int in[f+1];
	int fr[f+1];
	int cnt = 0;
	for(int i=0;i<f;i++)
		fr[i]=in[i] = -1;
	int fc=0;
	for(int i=0;i<18;i++)
	{
		printf("%d: ",arr[i]);
		if(h[arr[i]])
		{
			printf("No page fault :");
			int k =-1;
			for(int j=0;j<cnt;j++)
				if(fr[j]==arr[i])
				{
					k=j;
					break;
				}
			in[k] = i;
		}
		else
		{
			fc++;
			printf("Fage Fault : ");
			if(cnt<f)
			{
				fr[cnt] = arr[i];
				in[cnt++] = i;
			}
			else
			{
				int id = 0;
				for(int j=1;j<cnt;j++)
					if(in[j]<in[id])
						id = j;
				fr[id] = arr[i];
				h[fr[id]] = 0;
				in[id] = i;
			}
			h[arr[i]]=1;
		}

		for(int i=0;i<f;i++)
			printf("%d ",fr[i]);
		printf("\n");
	}
	printf("Total Faults : %d\n",fc);

}

int main()
{
	srand(time(0));
	printf("The random string : \n");
	for(int i=0;i<18;i++)
	{
		arr[i] = rand()%10;
		printf("%d ",arr[i]);
	}
	printf("\nEnter the number of frames\n");

	scanf("%d",&f);
	fifo();
	lru();
}