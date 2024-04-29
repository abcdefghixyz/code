//MIN-MAX ALOGORITHM
#include<stdio.h>
int main()
{
	int i,n,a[20];
	printf("Enter the array size:");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("Enter the element: ");
		scanf("%d",&a[i]);
	}
	int max=a[0];
	int min=a[0];
	for (i=0;i<n;i++)
	{
		if (min>a[i])
		{
			min=a[i];
		}
		if (a[i]>max)
		{
			max=a[i];
		}
	}
	printf("The minimun ekement is %d",min);
	printf("The maximum element is %d",max);
}
