//change data written in a file
 
#include <stdio.h>
#include <stdlib.h>
 
#define SIZE 41
#define MAX  81
 
struct person{
    char name[SIZE];
    unsigned int age;
    char address[MAX];
    char job[SIZE];
};
 
int main(void)
{
    struct person info;
    struct person rec;
    //struct person turnout;
    FILE * fp;
   //long fl;
 
    if((fp = fopen("info.dat","w+b")) == NULL)
    {
        fprintf(stderr, "Error opening %s", "info.dat");
        exit(EXIT_FAILURE);
    }
    printf("Name: ");
    fgets(info.name, SIZE, stdin);
    printf("\nAge: ");
    scanf("%u", &info.age);
    getchar();
    printf("\nAddress: ");
    fgets(info.address, SIZE, stdin);
    printf("\nJob: ");
    fgets(info.job, SIZE, stdin);
    fwrite(&info, sizeof (struct person), 1, fp);
    puts("\nOriginally:");
    printf("Name: %s", info.name);
    printf("\nAge: %u",info.age);
    printf("\nAddress: %s", info.address);
    printf("\nJob: %s", info.job);
   // fl = ftell(fp);
    fseek(fp, -(long)sizeof(struct person), SEEK_CUR);
    if(fread(&rec, sizeof (struct person), 1, fp) == 1)
    {
        puts("\nRec:");
        printf("Name: %s", rec.name);
        printf("\nAge: %u",rec.age);
        printf("\nAddress: %s", rec.address);
        printf("\nJob: %s", rec.job);
    }
    else
    {
        fputs("\nError writing data.\n", stdout);
        exit(1);
    }
    puts("\nAltering ...");
    /*printf("\nName: ");
    fgets(rec.name, SIZE, stdin);*/
    printf("\nAge: ");
    scanf("%u", &rec.age);
    getchar();
    /*printf("\nAddress: ");
    fgets(rec.address, SIZE, stdin);
    printf("\nJob: ");
    fgets(rec.job, SIZE, stdin);*/
    //fl = ftell(fp);
    fseek(fp, -(long)sizeof(struct person), SEEK_CUR);
    if(fwrite(&rec, sizeof (struct person), 1, fp) == 1)
    {
        fseek(fp, -(long)sizeof(struct person), SEEK_CUR);
        if(fread(&rec, sizeof (struct person), 1, fp) == 1)
        {
            puts("\nNew:");
            printf("Name: %s", rec.name);
            printf("\nAge: %u", rec.age);
            printf("\nAddress: %s", rec.address);
            printf("\nJob: %s", rec.job);
        }
        else
        {
            fputs("\nError reading data.\n", stdout);
            exit(1);
        }
    }
    else
    {
        fputs("\nError writing data.\n", stdout);
        exit(1);
    }
 
    fclose(fp);
    puts("\nBye!");
 
    return 0;
}
