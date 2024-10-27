#include<stdio.h>
typedef struct
{
    int regno;
    char name[50];
    char branch[50];
    int ad_year;
}student;

void savedata()
{
    FILE *p;
    student st;
    int n;
    //open the file in append mode
    p=fopen("stdata.vgt","ab");
    if(p==NULL)
    {
        printf("unable to open or create file");
    }
    else
    {
        printf("enter regno : ");
        scanf("%d",&st.regno);
        fflush(stdin);
        printf("enter name : ");
        gets(st.name);
        fflush(stdin);
        printf("enter branch : ");
        gets(st.branch);
        fflush(stdin);
        printf("enter year of admission : ");
        scanf("%d",&st.ad_year);

        //send data to file
        n=fwrite(&st, sizeof(st), 1, p);
        if(n>0)
        {
            printf("data saved");
        }
        else
            {
                printf("data not saved");
            }
    }
    fclose(p);
}
void showdata()
{
    FILE *p;
    student st;
    int n,i;
    //open the file in append mode
    p=fopen("stdata.vgt","rb");
    if(p==NULL)
    {
        printf("file does not exist");
    }
    else
    {
        i=1;
        printf("RNO\tregno\tname\tbranch\tyear\n");
            do
            {
            n=fread(&st, sizeof(st), 1, p);
                if(n>0)
                {
                    printf("%d\t%d\t%s\t%s\t%d\n",i,st.regno,st.name,st.branch,st.ad_year);
                    i++;
                }
                else
                {
                 break;  //stop do-while loop
                }
            }while(!feof(p));
    }
    fclose(p);
}
void update()
{
    student st,st1;
    int n,x,rno,aa;
    long position;
    FILE *p;

    //open file random mode
    p=fopen("stdata.vgt","r+b");
    if(p==NULL) //1st if open
    {
       printf("file does not exist");
    }         //1st  if close
    else  //1st else open
    {
        printf("enter record number to be searched : ");
        scanf("%d",&rno);
        position = (long)(rno-1)*sizeof(st);
        n=fseek(p, position,0);
        if(n==0)  //2nd if open
        {
            x=fread(&st,sizeof(st),1,p);
               if(x>0)       //3rd if open
               {
                   printf("\nRegno : %d\nName : %s\nBranch : %s\nYear of admission : %d",st.regno,st.name,st.branch,st.ad_year);
                   printf("\nDo you want to change data? enter 1-yes/0-no : ");
                   scanf("%d",&aa); //for taking choice
                        if(aa=1)     //4th if open
                        {
                            printf("enter regno : ");
                            scanf("%d",&st1.regno);
                            fflush(stdin);
                            printf("enter name : ");
                            gets(st1.name);
                            fflush(stdin);
                            printf("enter branch : ");
                            gets(st1.branch);
                            fflush(stdin);
                            printf("enter year of admission : ");
                            scanf("%d",&st1.ad_year);
                            //reset the position of file pointer
                              fseek(p,position,0);
                              //send data to file
                              x=fwrite(&st1,sizeof(st1),1,p);
                              if(x>0)  //5th if open
                              {
                                  printf("data changes saved successfully");
                              }     //5th if close
                              else  //5th else open
                              {
                                  printf("data changes not saved");
                              }    //5th else close

                        }
                        else  //4th else open
                        {
                            printf("as per your request,the data remains same");
                        }    //4th else close
               }   //3rd if close
               else   //3rd else open
               {
                   printf("cannot read data");
               }       //3rd else close
        }       //2nd if close
        else  //2nd else open
        {
            printf("record not found");
        }   //2nd else close
    }    //1st else close
    fclose(p);
}
void main()
{
int op;
        do
        {
            printf("\nstudent data management");
            printf("\n1.save");
            printf("\n2.show");
            printf("\n3.update");
            printf("\n0.exit");
            printf("\nenter choice : ");
            scanf("%d",&op);
            if(op==0)break;
            if(op==1)savedata();
            if(op==2)showdata();
            if(op==3)update();
        }while(1);
}



