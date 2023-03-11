#include<stdio.h>
void RunAllParts(int votes[5][4])
{
int i=0,j=0;
printf(" \t\tCandidate\tCandidate\tCandidate\tCandidate\n");
printf("Precinct\t A\t\t B\t\t C\t\t D\n");
for (i=0;i<5;i++)
{
for(j=0;j<4;j++)
{
if(j==0)
printf("%d\t\t", i+1);
printf("%d\t\t",votes[i][j]);
}
printf("\n");
}
printf("\n\n\n");
int sum[6]={0}, cumalativeSum=0;
char candidateName[] = "ABCD";
for (i=0;i<4;i++)  
{
for(j=0;j<5;j++)  
{
sum[i] += votes[j][i];
cumalativeSum += votes[j][i];
}
}
j=0;
for (i=0; i<4; i++)
{
printf("\nTotal votes of Candidate %c is %d and Percentage is %.2f ", candidateName[j++], sum[i], (float)sum[i]/cumalativeSum);
}
int maxValueIndices[2]= {4, 5};
printf("\n\n\n");
int winnerFound = 0;
float per = 0.0;
for (i=0; i<4; i++)
{
per = (float)sum[i]/cumalativeSum;
if( per > 0.5 )
{
printf("\nCandidate %c is a winner having percentage %.2f", candidateName[i], per);
winnerFound = 1;
}
 if(sum[i]>sum[maxValueIndices[0]]){
maxValueIndices[1]= maxValueIndices[0];
maxValueIndices[0] = i;
}
else if(sum[i] > sum[maxValueIndices[1]] && sum[i] != sum[maxValueIndices[0]])
 {
maxValueIndices[1] = i;
}
}

if(winnerFound == 0){

 printf("\nCandidate %c got the Highest votes %d", candidateName[maxValueIndices[0]], sum[maxValueIndices[0]]);

 printf("\nCandidate %c got the Second Highest votes %d", candidateName[maxValueIndices[1]], sum[maxValueIndices[1]]);

}

}

int main()

{

int votes[5][4]= {

{192,48,206,37},

{147,90,312,21},

{186,12,121,38},

{114,21,408,39},

{267,13,382,29}

};
RunAllParts(votes);
printf("\n\n\n");
printf("\nRunning Code with candidate C receiving only 108 votes\n\n");
int Newvotes[5][4]= {
{192,48,10,37},

{147,90,20,21},

{186,12,30,38},

{114,21,40,39},

{267,13,8,29}

};
RunAllParts(Newvotes);  
}