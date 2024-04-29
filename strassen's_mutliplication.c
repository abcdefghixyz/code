#include<stdio.h>
int main()
{
	int a[2][2],b[2][2],c[2][2],i,j;
	printf("Elements of first array\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Enter the array elements: ");
			scanf("%d",&a[i][j]);
		}
	}
	printf("Elements of second array\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Enter the array elements: ");
			scanf("%d",&b[i][j]);
		}
	}
	int a11=a[0][0],a12=a[0][1],a21=a[1][0],a22=a[1][1];
	int b11=b[0][0],b12=b[0][1],b21=b[1][0],b22=b[1][1];
	int p=(a11+a22)*(b11+b22);
	int q=(a21+a22)*b11;
	int r=a11*(b12-b22);
	int s=a22*(b21-b11);
	int t=(a11+a12)*b22;
	int u=(a21-a11)*(b11+b12);
	int v=(a12-a22)*(b21+b22);

	
	c[0][0]=p+s-t+v;
	c[0][1]=r+t;
	c[1][0]=q+s;
	c[1][1]=p+r-q+u;
	
	printf("Elements of resultant array\n");
	for(i=0;i<2;i++){
		for (j=0;j<2;j++){
			printf("%d",c[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
