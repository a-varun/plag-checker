
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;
/* variable declaration*/
int number_of_files;

int number_of_unique_words=0;
int id[100000];
char unique_words[10000][100];
int H[1000][1000];
char searching_word[1000];
int searching_index;
int encrypt_searching;
int document_id[100000];
int changed_document;
char file_names[1000][1000];


class keywords
{
    /*A class for every document in the folder so that all the keywords can be placed here*/
   public:
    int document_id;
    int number_of_words;
    char name[100][100];
}obj[4000];

int encrypt(char word[100])
{
    int value=0;
    int i;
    for(i=0;word[i]!='\o';i++)
{
    value=value+word[i];
}
    return value;
}
int find_index(char words[100])
{
     int i;
    for(i=0;i<number_of_unique_words;i++)
    {
        if(strcmp(words,unique_words[i])==0)
        {
            return i;
        }
    }
}

int find_document(int value)
{
    int i;
    for(i=0;i<number_of_files;i++)
    {
        if(value==document_id[i])
        {
            return i;
        }
    }

}

int find_previous_to_most_recent(int endvalue,char words[100])
{
    int i;
    int j;

    for(i=endvalue-1;i>=0;i--)
    {
        for(j=0;j<obj[i].number_of_words;j++)
        {
            if(strcmp(words,obj[i].name[j])==0)
            {

                return i;
            }
        }
    }
    return -1;
}





void get_no_of_files()
{
    /* this method will help to get the number of files in the folder*/
    /*Initially lets accept it from user*/
    printf("\n Enter the number of files in the folder\n");
    scanf("%d",&number_of_files);
}
int find_did(char words[100])
{
    int i;
    for(i=0;i<number_of_unique_words;i++)
    {
        if(strcmp(words,unique_words[i])==0)
        {
            return id[i];
        }
    }

}

int hadmatmul(int value,int index)
{
    int i;
    int result=0;
    for(i=0;i<number_of_unique_words;i++)
    {
        result=(H[index][i]*value)+result;
    }
    return result;
}
void get_folder()
{
    //printf("\n enter the index file");
   // cout<<endl<<"Enter file name:";
    char fname[10]="Index.txt";
    int length=0;
    int breadth=0;
    char c;
              //cin>>fname;
              ifstream in(fname);

              if(!in)
              {
                            cout<<"File Does not Exist";
              }
              cout<<"\n\n";
              int position=0;
              while(in.eof()==0)
              {
                            in.get(c);
                            if(c!=' ')
                            {
                                file_names[length][breadth]=c;
                                breadth++;
                            }
                            else
                            {
                                if(strcmp(file_names[length],"end")==0)
                                break;

                                breadth=0;
                                length++;
                            }


              }
              length++;
            int i;
              number_of_files=length;
              number_of_files--;
             // number_of_files=400;

              for(i=0;i<number_of_files;i++)
              {
          //        cout<<endl<<endl<<file_names[i];
              }
              cout<<"returning to main "<<number_of_files;


}
void read_from_file()
{
     char c,fname[10];
              int length=0;
              int breadth=0;
              int i;
              //for(i=0;i<number_of_files;i++)
              i=0;
                  length=0;
                  breadth=0;
              obj[i].document_id=i;
              //cout<<"checking for file"<<file_names[i]<<endl;

              ifstream in("file25.txt");

              if(!in)
              {
                            cout<<"File Does not Exist";
              }
              cout<<"\n\n";
              int position=0;
              while(in.eof()==0)
              {
                            in.get(c);
                            if(c!=' ')
                            {
                                obj[i].name[length][breadth]=c;
                                breadth++;
                            }
                            else
                            {

                                breadth=0;
                                length++;
                            }
                            if(c=='\n')
                            {
                                length++;
                                obj[i].number_of_words=length;
                                i++;
                            }

              }
              number_of_files=i;
             // number_of_files=200;




}
double run_module(int a,int b)
{
  //  get_no_of_files();
    int did;
 /*   keywords obj[number_of_files]; */

    char temp[100];
    char compare[100];
    int i;
    int l;
    int j;
    int k;
    int flag=1;
    get_folder();
    read_from_file();
    number_of_files=b;

  // cout<<"The contents of files"<<endl;

   /*for(i=0;i<number_of_files;i++)
   {
      cout<<"content of file"<<i<<endl;
       for(j=0;j<obj[i].number_of_words;j++)
       {
          cout<<obj[i].name[j]<<" ";
       }
    cout<<endl;
   }
*/

    for(i=0;i<number_of_files;i++)
    {

        for(j=0;j<obj[i].number_of_words;j++)
        {

           for(k=0;k<number_of_unique_words;k++)
           {
               if(strcmp(obj[i].name[j],unique_words[k])==0)
               {
                   flag=0;
                   break;
               }
           }
           if(flag==1)
           {
              strcpy(unique_words[number_of_unique_words],obj[i].name[j]);
              number_of_unique_words++;
           }
           flag=1;

        }
    }


 printf("\n the size of hadamand matrix is %d\n",number_of_unique_words);
 int N = number_of_unique_words;
 N=a;



int n;



	H[0][0] = 1;
	for(n = 1; n < N; n += n)
	    {
		for( i = 0; i < n; i++)
		    for(j = 0; j < n; j++)
			{
			    H[i+n][j] = H[i][j];
			    H[i][j+n] = H[i][j];
			    H[i+n][j+n] = !H[i][j];
			}
	    }
/* code for printing hadamand matrix
	for(i = 0; i < N; i++)
	    {
		for(j = 0; j < N; j++)
		    {
			printf("%d ",H[i][j]);

        }
		printf("\n");
	    }
	    */















 for(i=0;i<number_of_unique_words;i++)
 {
     id[i]=0;
 }

int index;
int o=0;
int res;
clock_t init,final;
init=clock();

 for(i=0;i<number_of_files;i++)
{

    for(j=0;j<obj[i].number_of_words;j++)
    {
        did=find_did(obj[i].name[j]);
        flag=encrypt(obj[i].name[j]);
        index=find_index(obj[i].name[j]);


       res=(flag^did);
       res=hadmatmul(res,index);
       o=o+res;

      //  printf("\n the value for the word %s in file %d with the index id % is %d",obj[i].name[j],i,index,o);


    }
    for(j=0;j<obj[i].number_of_words;j++)
    {
        index=find_index(obj[i].name[j]);
        id[index]=o;
    }
   //printf("\n the value of the D%d is %d\n",i,o);
    document_id[i]=o;
    o=0;

}
final=clock()-init;
//cout<<endl<<"The time taken for index construction is"<<

double result=(double)final/((double)CLOCKS_PER_SEC);
//printf("\n the value of the document id\n");
for(i=0;i<number_of_unique_words;i++)
{
   // printf("\n word is %s and id is %d\n",unique_words[i],id[i]);
}




   /* printf("\n The number of documents detected in the folder is %d\n",number_of_files);

*/

  // printf("\n Enter the word to be searched\n");
   //scanf("%s",searching_word);
   strcpy(searching_word,"Firm");

  // printf("\n Now creating the parameters of the searching word\n");

   searching_index=find_index(searching_word);
   encrypt_searching=encrypt(searching_word);

   int most_recent_document=find_document(id[searching_index]);

   printf("\n the most recent document is %d\n",most_recent_document);

   int previous_to_most_recent=most_recent_document;

//init=clock();
   while(previous_to_most_recent!=-1)
   {

           previous_to_most_recent=find_previous_to_most_recent(previous_to_most_recent,searching_word);
           if(previous_to_most_recent!=-1)
           {
               printf("\n The document is found in %d\n",previous_to_most_recent);
           }

   }
   //final=clock()-init;
//cout<<endl<<"The time taken for index construction is"<<(double)final/((double)CLOCKS_PER_SEC);
return result;
/*
   printf("\n Enter the the document to be updated \n");
   scanf("%d",&changed_document);

   printf("\n Enter the details of the new document");

   printf("\n Enter the number of words \n");
   scanf("%d",&obj[number_of_files].number_of_words);

   printf("\n Enter the details of the file\n");

   for(i=0;i<obj[number_of_files].number_of_words;i++)
   {
       scanf("%s",obj[number_of_files].name[i]);
   }

   number_of_files++;



 o=0;
 res;
 init=clock();

 for(i=0;i<number_of_files;i++)
{

    for(j=0;j<obj[i].number_of_words;j++)
    {
        did=find_did(obj[i].name[j]);
        flag=encrypt(obj[i].name[j]);
        index=find_index(obj[i].name[j]);


       res=(flag^did);
       res=hadmatmul(res,index);
       o=o+res;

      //  printf("\n the value for the word %s in file %d with the index id % is %d",obj[i].name[j],i,index,o);


    }
    for(j=0;j<obj[i].number_of_words;j++)
    {
        index=find_index(obj[i].name[j]);
        id[index]=o;
    }
   // printf("\n the value of the D%d is %d\n",i,o);
    document_id[i]=o;
    o=0;

}
final=clock()-init;
cout<<endl<<"The time taken for index construction is"<<(double)final/((double)CLOCKS_PER_SEC);

printf("\n the value of the document id\n");
for(i=0;i<number_of_unique_words;i++)
{
    //printf("\n word is %s and id is %d\n",unique_words[i],id[i]);
}
for(i=0;i<obj[changed_document].number_of_words;i++)
{
    strcpy(obj[changed_document].name[i],"null");
}
 printf("\n Enter the word to be searched\n");
   scanf("%s",searching_word);

   printf("\n Now creating the parameters of the searching word\n");

   searching_index=find_index(searching_word);
   encrypt_searching=encrypt(searching_word);

    most_recent_document=find_document(id[searching_index]);

  printf("\n the most recent document is %d\n",most_recent_document);

    previous_to_most_recent=most_recent_document;

init=clock();
   while(previous_to_most_recent!=-1)
   {

           previous_to_most_recent=find_previous_to_most_recent(previous_to_most_recent,searching_word);
           encrypt_searching=encrypt(searching_word);
           searching_index=find_index(searching_word);
           did=find_document(id[searching_index]);
          // res=did^encrypt;
           res=hadmatmul(res,searching_index);

              if(previous_to_most_recent!=-1)
               printf("\n The document is found in %d\n",previous_to_most_recent);


   }
   final=clock()-init;
cout<<endl<<"The time taken for index construction is"<<(double)final/((double)CLOCKS_PER_SEC);


*/


}
int similarity_score[1000];


class Files
{
    public:
    char words_in_files[100][100];
    int number_of_words;
}obj[1000];



void get_keywords()
{
    printf("\n enter the keyword file");
    printf("\n Enter file name");
    char fname[10]="Index.txt";
    int length=0;
    int breadth=0;
    char c;
              //scanf("%s",fname);
              ifstream in(fname);

              if(!in)
              {
                            cout<<"File Does not Exist";
              }
              cout<<"\n\n";
              int position=0;
              while(in.eof()==0)
              {
                            in.get(c);
                            if(c!=' ')
                            {
                                keywords[length][breadth]=c;
                                breadth++;
                            }
                            else
                            {
                                if(strcmp(keywords[length],"end")==0)
                                break;

                                breadth=0;
                                length++;
                            }


              }


           //   printf("\n The number of keywords is %d\n ",length);

              number_of_keywords=length;




}

void read_from_file()
{
     char c,fname[10];
              int length=0;
              int breadth=0;
              int i;
              //for(i=0;i<number_of_files;i++)
              i=0;
                  length=0;
                  breadth=0;
              //obj[i].document_id=i;
              //cout<<"checking for file"<<file_names[i]<<endl;

              ifstream in("file25.txt");

              if(!in)
              {
                            cout<<"File Does not Exist";
              }
              cout<<"\n\n";
              int position=0;
              while(in.eof()==0)
              {
                            in.get(c);
                            if(c!=' ')
                            {
                                obj[i].words_in_files[length][breadth]=c;
                                breadth++;
                            }
                            else
                            {

                                breadth=0;
                                length++;
                            }
                            if(c=='\n')
                            {
                                length++;
                                obj[i].number_of_words=length;
                                length=0;
                                i++;
                            }

              }
              number_of_files=600;



}


void get_split_vector()
{

    int i;
    for(i=0;i<new_number_of_keywords;i++)
    {
        splitting_vector[i]=rand()%2;
    }

}

void querey_vector_generation()
{
    printf("\n Enter the number of querey keywords \n");
    number_of_querey_words=3;
    //scanf("%d",&number_of_querey_words);
    int i;
    for(i=0;i<number_of_querey_words;i++)
     {
   // scanf("%s",querey[i]);
   strcpy(querey[i],keywords[i]);
        }

     for(i=0;i<number_of_keywords;i++)
     {
         querey_vector[i]=0;
     }
     int j;

     for(i=0;i<number_of_querey_words;i++)
     {
         for(j=0;j<number_of_keywords;j++)
     {
         if(strcmp(querey[i],keywords[j])==0)
         {
            printf("\n  querey %s and %s match found ",querey[i],keywords[j]);
             querey_vector[j]=1;
         }
     }
     }

}

void data_vector_generation()
{
    int i,j,k;

    for(i=0;i<number_of_files;i++)
     {
    for(j=0;j<number_of_keywords;j++)
    {
        {
    data_vector[i][j]=0;
     }
     }
     char ch;
    for(i=0;i<number_of_files;i++)
    {
        //printf("\n continue");
        //scanf("%c",&ch);
      for(j=1;j<obj[i].number_of_words;j++)
      {
        for(k=0;k<number_of_keywords;k++)
      {

          if(strcmp(obj[i].words_in_files[j],keywords[k])==0 && obj[i].words_in_files[j][0]!='\0')
          {
             // printf("\n Comparing %s and %s ",obj[i].words_in_files[j],keywords[k]);
              data_vector[i][k]=1;

          }
      }
      }
    }
}
}

void print_data_vector()
{
    printf("\n the data vector\n");
    int i,j;
    char ch;
    for(i=0;i<number_of_files;i++)
    {
        for(j=0;j<new_number_of_keywords;j++)
        {
            printf("  %d",data_vector[i][j]);

        }
        printf("\n");
    }
}

void print_querey_vector()
{
    printf("\n the querey vector \n");
    int i;
    for(i=0;i<new_number_of_keywords;i++)
    {
     printf("  %d",querey_vector[i]);
    }
}
void print_keywords()
{

    printf("\n the keywords are\n");
    int i;

    for(i=0;i<number_of_keywords;i++)
    {
        printf("\n %s",keywords[i]);
    }
}

void print_contents_of_file()
{
    int i;
    int j;
    for(i=0;i<number_of_files;i++)
    {
        printf("\n contnets of file %d and number of words is %d",i,obj[i].number_of_words);
        for(j=0;j<obj[i].number_of_words;j++)
    {
        printf(" %s",obj[i].words_in_files[j]);
    }
     printf("\n");
    }
}
void find_random_U()
{
    U=rand()%10;
    U++;
    printf("\n the random extension is U=%d",U);
}

void extending_data_vector()
{
    new_number_of_keywords=number_of_keywords+U+1;
    int i,j;

    for(i=0;i<number_of_files;i++)
{
    for(j=number_of_keywords;j<new_number_of_keywords-1;j++)
    {
         data_vector[i][j]=rand()%10;
    }
}


for(i=0;i<number_of_files;i++)
{
    data_vector[i][new_number_of_keywords-1]=1;
}

}

void extending_querey_vector()
{
    int v=rand()%U;
    int i;
    int count=0;
    for(i=number_of_keywords;i<new_number_of_keywords-1;i++)
    {

     if(count<v)
     {
         querey_vector[i]=1;
         count++;
     }
     else
     {
         querey_vector[i]=0;
     }
    }
    int t=7;
    for(i=0;i<new_number_of_keywords-1;i++)
    {
        querey_vector[i]=querey_vector[i]*t;
    }
    querey_vector[new_number_of_keywords]=t;
}
void print_olddatavector()
{
    int i;
    int j;
    printf("\n data vector\n");
    for(i=0;i<number_of_files;i++)
    {
        for(j=0;j<number_of_keywords;j++)
        {
            printf(" %d",data_vector[i][j]);
        }
        printf("\n");
    }
}

void print_oldquereyvector()
{
    int i;
    printf("\n querey vector\n");
    for(i=0;i<number_of_keywords;i++)
    {
     printf(" %d",querey_vector[i]);
    }
}

void split_data_vector()
{
    int i;
    int j;
    for(i=0;i<number_of_files;i++)
    {
        for(j=0;j<new_number_of_keywords;j++)
        {
            if(splitting_vector[i]==0)
            {
                data_vector_part1[i][j]=data_vector[i][j];
                data_vector_part2[i][j]=data_vector[i][j];
            }
            else
            {
                data_vector_part1[i][j]=data_vector[i][j]/2;
                data_vector_part2[i][j]=data_vector[i][j]-data_vector_part1[i][j];
            }
        }

    }
}
void split_querey_vector()
{
    int i;
    for(i=0;i<new_number_of_keywords;i++)
    {
        if(splitting_vector[i]==1)
        {
            querey_vector_part1[i]=querey_vector[i];
            querey_vector_part2[i]=querey_vector[i];
        }
        else
        {
            querey_vector_part1[i]=querey_vector[i]/2;
            querey_vector_part2[i]=querey_vector[i]-querey_vector_part1[i];
        }
    }
}

void print_data_vector_part1()
{
    int i,j;
    printf("\n data vector part 1\n");
    for(i=0;i<number_of_files;i++)
    {
        for(j=0;j<new_number_of_keywords;j++)
        {
            printf("% d",data_vector_part1[i][j]);
        }
        printf("\n");
    }
}
void print_data_vector_part2()
{
    int i,j;
    printf("\n data vector part 2\n");
    for(i=0;i<number_of_files;i++)
    {
        for(j=0;j<new_number_of_keywords;j++)
        {
            printf("% d",data_vector_part2[i][j]);
        }
        printf("\n");
    }
}

void print_querey_vector_part1()
{
    int i;
    printf("\n querey vector part 1 \n");
    for(i=0;i<new_number_of_keywords;i++)
    {
        printf(" %d",querey_vector_part1[i]);
    }
}

void print_querey_vector_part2()
{
    int i;
    printf("\n querey vector part 2 \n");
    for(i=0;i<new_number_of_keywords;i++)
    {
        printf(" %d",querey_vector_part2[i]);
    }
}
void print_splitting_vector()
{
    printf("\n splitting vector \n");
    int i;
    for(i=0;i<new_number_of_keywords;i++)
    printf("%d ",splitting_vector[i]);
}

void compute_similarity_score()
{
    int i;
    int j;
    for(i=0;i<number_of_files;i++)
    {
        similarity_score[i]=0;
    }
    for(i=0;i<number_of_files;i++)
    {
        for(j=0;j<new_number_of_keywords;j++)
      {
          similarity_score[i]=similarity_score[i]+(data_vector_part1[i][j]*querey_vector_part1[j]);
          similarity_score[i]=similarity_score[i]+(data_vector_part2[i][j]*querey_vector_part2[j]);
      }
    }
    for(i=0;i<number_of_files;i++)
    {
        for(j=number_of_keywords;j<new_number_of_keywords-1;j++)
        {
            similarity_score[i]=similarity_score[i]+data_vector[i][j];
            similarity_score[i]=similarity_score[i]+7;
        }
    }


}

void print_similarity_score()
{
    int i;
    printf("\n The similarity score \n");
    for(i=0;i<number_of_files;i++)
    {
        printf("\n Score for file %d is %d",i,similarity_score[i]);
    }
}
void find_max()
{
    int i;
    int max=0;
    int pos=0;
    for(i=0;i<number_of_files;i++)
    {
        if(max<similarity_score[i])
        {
            max=similarity_score[i];
            pos=i;
        }
    }
    printf("\n the file is %d ",pos);
    similarity_score[pos]=0;
}

void get_top_k_documents()
{
    int i;
    printf("\n Enter the value of k");
    int k;
    scanf("%d",&k);
    while(k>0)
    {
        k--;
        find_max();
    }
}


double run_module(int a,int b)
{
    get_keywords();
    number_of_keywords=a;
    printf("\n Reading from file\n");
    read_from_file();
    number_of_files=b;
    clock_t init,final;
    init=clock();
    querey_vector_generation();
    data_vector_generation();
    //print_olddatavector();
  // print_oldquereyvector();
    find_random_U();
   extending_data_vector();
   extending_querey_vector();
   get_split_vector();
  // print_data_vector();
 // print_querey_vector();
 // print_splitting_vector();
   split_data_vector();
   split_querey_vector();
   final=clock()-init;
   return (double)final/((double)CLOCKS_PER_SEC);
  // print_data_vector_part1();
  // print_data_vector_part2();
  // print_querey_vector_part1();
  // print_querey_vector_part2();
   compute_similarity_score();
  // print_similarity_score();
  get_top_k_documents();

    return 1;
}

int main()
{
    double result[6][60];
    int i;
    int param_number_of_files;
    int param_number_of_keywords;
    int j;
    for(i=0;i<5;i++)
    {
        printf("\n Enter the number of files");
        scanf("%d",&param_number_of_files);
        printf("\n Enter the number of keywords\n ");
        scanf("%d",&param_number_of_keywords);
        for(j=0;j<50;j++)
        {

            result[i][j]=run_module(param_number_of_keywords,param_number_of_files);
            printf(" %f\n",result[i][j]);
        }

    }

    ofstream fout("Result.txt");
    int iter=100;

    if(fout.is_open())
    {
        for(i=0;i<5;i++)
        {
            fout<<"\n Entering data for "<<iter<<"Files \n";
            for(j=0;j<50;j++)
        {
            fout<<result[i][j]<<"\t";
        }
        fout<<"\n";
        iter=iter+100;
        }
    }


    fout<<"\n *********************************\n";

    fout<<"\n Statistical Average....\n";

    iter=100;
    double avg=0;

    for(i=0;i<5;i++)
    {
        for(j=0;j<50;j++)
        {
            avg=avg+result[i][j];

        }
        avg=avg/50;
        fout<<"\n The avergae time for building the index with "<<iter<<" Files is"<<avg;
        iter=iter+200;
        avg=0;
    }
    }

