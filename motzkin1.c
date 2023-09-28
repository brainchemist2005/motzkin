#include<stdio.h>
#include<string.h>
 
int counter(int i)
{
 if(i == 0)
  return 0;
 else
  return i-1;
}
 
int main(int argc, char * argv[]){
 int x[5] = {0} ,y[5] = {0};
 
 char * arg = argv[1];
 
 if(argc != 2 || strlen(arg) !=5 ){
  fprintf(stderr,"error: wrong number of arguments");
  return 1;
 }

 y[0] = 200;
 
 for(int i=0; i<5 ; i++) {
  if(arg[i] == 'u'){
   x[i] = x[counter(i)] + 100 ;
   y[i] = y[counter(i)] - 100;
  }
  else if(arg[i] == 'd'){
   x[i] = x[counter(i)]+100;
   y[i]= y[counter(i)]+100;
  }
  else if(arg[i] == 'r'){
   y[i] = y[counter(i)];
   x[i] = x[counter(i)]+100;
  }
  else{
   fprintf(stderr, "error:unrecognized step %c",arg[i]);
   return 1;
  }
 }
 
 FILE *file = fopen("motzkin.svg", "w");
 if (file == NULL) {
      printf("Error opening file!\n");
      return 1;
 }
 
  fprintf(file, "<?xml version=\"1.0\"?>\n");
  fprintf(file, "<svg width=\"500\" height=\"200\" viewBox=\"-8 -8 516 216\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">\n");
 fprintf(file, "<g id=\"grid\">\n");
 fprintf(file, "<line x1=\"0\" y1=\"0\" x2=\"500\" y2=\"0\" stroke=\"black\" stroke-width=\"1\" stroke-dasharray=\"4 2\"/>\n");
 fprintf(file, "<line x1=\"0\" y1=\"100\" x2=\"500\" y2=\"100\" stroke=\"black\" stroke-width=\"1\" stroke-dasharray=\"4 2\"/>");
 fprintf(file, "<line x1=\"0\" y1=\"200\" x2=\"500\" y2=\"200\" stroke=\"black\" stroke-width=\"1\" stroke-dasharray=\"4 2\"/>");
 fprintf(file,"<line x1=\"0\" y1=\"0\" x2=\"0\" y2=\"200\" stroke=\"black\" stroke-width=\"1\" stroke-dasharray=\"4 2\"/>");
 fprintf(file, "<line x1=\"100\" y1=\"0\" x2=\"100\" y2=\"200\" stroke=\"black\" stroke-width=\"1\" stroke-dasharray=\"4 2\"/>");
 fprintf(file, "<line x1=\"200\" y1=\"0\" x2=\"200\" y2=\"200\" stroke=\"black\" stroke-width=\"1\" stroke-dasharray=\"4 2\"/>");
 fprintf(file, "<line x1=\"300\" y1=\"0\" x2=\"300\" y2=\"200\" stroke=\"black\" stroke-width=\"1\" stroke-dasharray=\"4 2\"/>");
 fprintf(file,"<line x1=\"400\" y1=\"0\" x2=\"400\" y2=\"200\" stroke=\"black\" stroke-width=\"1\" stroke-dasharray=\"4 2\"/>" );
 fprintf(file, "<line x1=\"500\" y1=\"0\" x2=\"500\" y2=\"200\" stroke=\"black\" stroke-width=\"1\" stroke-dasharray=\"4 2\"/>");
 fprintf(file, "</g>\n");
 fprintf(file, "<g id=\"steps\">\n");
 fprintf(file, "<line x1=\"0\" y1=\"200\" x2=\"%d\" y2=\"%d\" stroke=\"red\" stroke-width=\"3\" stroke-dasharray=\"none\"/>\n",x[0],y[0]);
 for(int i=0; i<4; i++) {
  fprintf(file, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"red\" stroke-width=\"3\" stroke-dasharray=\"none\"/>\n", x[i], y[i], x[i+1], y[i+1]);
 }
 fprintf(file, "</g>\n");
 
 fprintf(file, "<g id=\"points\">\n");
 for(int i=0; i<5; i++) {
  fprintf(file, "<circle cx=\"%d\" cy=\"%d\" r=\"7\" fill=\"blue\"/>\n", x[i], y[i]);
 }
 fprintf(file, "<circle cx=\"0\" cy=\"200\" r=\"7\" fill=\"blue\"/>\n");

 fprintf(file, "</g>\n");
 fprintf(file, "</svg>\n");
 
 fclose(file);
 
 return 0;
}
