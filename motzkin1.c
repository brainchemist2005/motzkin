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
	int * x[5] = {0} ,y[5] = {0};

	char * arg = argv[1];

	if(argc != 2 || strlen(arg) !=5 ){	
		fprintf(stderr,"error: wrong number of arguments");
		return 1;
	}

	for(int i=0; i<5 ; i++) {
	if(arg[i] == 'u'){
		x[i] = x[counter(i)]++;
		y[i] = y[counter(i)]++;
	}
	else if(arg[i] == 'd'){
		x[i] = x[counter(i)]--;
		y[i]= y[counter(i)]++;
		
	}
	else if(arg[i] == 'r'){
		y[i] = y[counter(i)]++;
	}
	else{ 
		fprintf(stderr, "error:unrecognized step %c",arg[i]);
		return 1;
	}
	}

	for(int i=0 ; i<5 ; i++)
		printf("(%d,%d)",x[i],y[i]);

	return 0;
}
