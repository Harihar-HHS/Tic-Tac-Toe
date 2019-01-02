#include<stdio.h>

int a[3][3];

void rules()
{
	int i,j;
	printf("\nBoard =>\n");
	for(i=0;i<3;i++)
	{
		printf("----------|\n");	// 10 -
		for(j=0;j<3;j++)
			printf("%d | ",a[i][j]);
		printf("\n");
	}
        printf("----------|\n");
	printf("\n Enter the position no. to play\n");
}

void board()
{
	int i,j;
        printf("\nBoard =>\n");
        for(i=0;i<3;i++)
        {
                printf("----------|\n");        // 10 -
                for(j=0;j<3;j++)
                {
			if(a[i][j]==1)
				printf("X | ");
			else if(a[i][j]==0)
				printf("O | ");
			else
			        printf(" | ");
		}
                printf("\n");
        }
        printf("----------|\n");
}

int iswin()
{
	int i;
	for(i=0;i<3;i++)
	if((a[i][0]==a[i][1])&&(a[i][0]==a[i][2])&&(a[i][0]!=-1))	// rows
			return a[i][0];
	for(i=0;i<3;i++)
        if((a[0][i]==a[1][i])&&(a[0][i]==a[2][i])&&(a[0][i]!=-1))     // cols
                        return a[0][i];
	if((a[0][0]==a[1][1])&&(a[0][0]==a[2][2])&&(a[0][0]!=-1))
			return a[0][0];
	if((a[0][2]==a[1][1])&&(a[0][2]==a[2][0])&&(a[0][2]!=-1))
                        return a[0][2];
	return(-1);
}

int update(int op,int j)
{
	int r=(op-1)/3,c=(op-1)%3;
	if(a[r][c]==-1)
	{
		if(j%2==0)
			a[r][c]=1;
		else
			a[r][c]=0;
		return 0;
	}
	return 1;
}

void main()
{
	int i,j,op=1,f=-1;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
		a[i][j]=op++;
	rules();
	for(i=0;i<3;i++)
        for(j=0;j<3;j++)
                a[i][j]=-1;
	board();
	i=0;op=0;
	printf("Enter cell no.\n");
	while(i<9)
	{
		if(i%2==0)
			printf("\nX's turn\n");
		else
			printf("\nO's turn\n");
		printf("Enter the cell no. : ");
		scanf("%d",&op);
		//printf("i=%d",i);
		if(update(op,i))
		{
			printf("Already filled!!!!!!\n\nTry again");
			//printf("%d--",i--);
			i--;
		}
		board();
//		printf("%d++",i++);
		i++;
		op=iswin();
		if(op!=-1)
		{
			printf("\nGame over\n\n");
			f=0;
			if(op==1)
				printf("X wins\n");
			else
				printf("O wins\n");
			break;
		}
	}
	if(f==-1)
		printf("\n\nDraw!!!\n");
}
